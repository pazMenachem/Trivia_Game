#pragma once
#include "RequestHandlerFactory.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"


static const unsigned short PORT = 8826;
static const unsigned int IFACE = 0;
using handlersMap = std::map<SOCKET, unique_ptr<IRequestHandler>>;

// DataReceiver is in charge of receiving the message from the client socket.
// Eventually it will hold the code (_message code), and client's message (_final message).
// It will also close the client socket once the connection is over.
struct DataReceiver {
	DataReceiver() = delete;
	DataReceiver(SOCKET& clientSocket)
		:_bytesReadFromSocket(NULL),
		_messageCode(NULL),
		_msgLengthCharArr(),
		_sizeOfMessageInInt(NULL),
		_finalMsg(nullptr),
		_clientSocket(clientSocket) {}
	void setMessageSize() {
		delete[] _finalMsg;
		_finalMsg = new char[_sizeOfMessageInInt + 1];
		_finalMsg[_sizeOfMessageInInt] = '\0';
	}
	~DataReceiver() {
		delete[] _finalMsg;
		closesocket(_clientSocket);
	}

	int _bytesReadFromSocket;
	unsigned char _messageCode;
	char _msgLengthCharArr[AMOUNT_OF_BYTES_FOR_INT];
	unsigned int _sizeOfMessageInInt;
	char* _finalMsg;
	SOCKET& _clientSocket;
};

// NOTE - Client socket is being closed by DataReceiver struct
struct DataSender {
	DataSender() = delete;
	DataSender(SOCKET& sock) : _sock(sock) {};

	void sendData() {
		send(_sock, _finalMsgToSend.c_str(), int(_finalMsgToSend.size()), 0);
	};

	void setData(const RequestResult& reqRes) {
		_finalMsgToSend = JsonResponsePacketSerializer::convertMsgToClient(reqRes._requestCode, reqRes._responseMsg);
	};
	static string prepareDataToBroadCast(const unsigned char& requestCode, const string& msg) {
		
		Json jsonMsg = Json::parse(msg);
		switch (requestCode) {
		case CODE_JOIN_ROOM:
		case CODE_LEAVE_ROOM:
		case CODE_LEAVE_GAME:
			jsonMsg[BROADCAST] = CODE_BC_PLAYER_JOINED_LEFT;
			break;
		case CODE_CLOSE_ROOM:
			jsonMsg[BROADCAST] = CODE_BC_ROOM_CLOSED;
			break;
		case CODE_START_GAME:
			jsonMsg[BROADCAST] = CODE_BC_GAME_STARTED;
			break;
		case CODE_CHAT_MESSAGE:
			// BroadCast added in the request handle. * Do not add here *
			break;
		case CODE_CLOSE_GAME:
			jsonMsg[BROADCAST] = CODE_BC_GAME_CLOSED;
			break;
		default:
			cerr << __FUNCTION__ "Unknown Error" << endl;
		};

		return JsonResponsePacketSerializer::convertMsgToClient(requestCode, jsonMsg.dump());
	}
	static void sendDataToDiffUser(const SOCKET& sock,const string& msg) {
		send(sock, msg.c_str(), int(msg.size()), 0);
	}

	SOCKET& _sock;
	string _finalMsgToSend;
};

/**
 * @brief Manages network communication between a server and its clients.
 *
 * The Communicator class is responsible for establishing and maintaining a TCP/IP network communication between a server and its clients.
 * Notes - SingleTon class
 */
class Communicator {
public:
	/**
	 * @brief Destructor for the Communicator class.
	 *
	 * This destructor closes the listen socket.
	 */
	~Communicator();
	/**
	 * @brief Starts handling incoming client requests.
	 *
	 * This method works in an infinite loop, continuously handling incoming client requests.
	 */
	void startHandleRequests();
	/**
	* @brief Broadcast a message to multiple clients.
	*
	* This method broadcasts a message to a group of clients while excluding a specific user if needed.
	*
	* @param names The usernames of the clients to receive the message.
	* @param msg The message to broadcast.
	* @param requestCode The request code associated with the message.
	* @param excludeUser The username to exclude from the broadcast.
	* @param gameId The game identifier, if applicable (default is -1).
	*/
	void broadCast(const vector<string>& names, string msg, unsigned char requestCode, string excludeUser, int gameId = -1);

	Communicator(const Communicator&) = delete;
	Communicator& operator=(const Communicator&) = delete;

	/**
	 * @brief Get the singleton instance of the Communicator.
	 *
	 * @return A pointer to the Communicator instance.
	 */
	static Communicator* getInstance();
	/**
	* @brief Delete the Communicator instance.
	*/
	void deleteInstance();

private:
	SOCKET _listenSocket;
	handlersMap _clients;
	mutex _mutex;
	unique_lock<mutex> _clientLock;
	RequestHandlerFactory& _reqHandlerFact;
	static Communicator* _instance;
	
	Communicator();
	//Binds the listen socket to the specified port and interface, and starts listening for incoming client connections.
	void bindAndListen() const;
	//Accepts incoming client connections and starts a new thread to handle each client.
	void acceptClients();
	//Creates a new client connection and returns the client socket.
	SOCKET CreateNewClientSocket();

	void communicateWithClient(SOCKET sock);

	void getMessageFromClient(DataReceiver& dataRec);

	void setRequestData(RequestData& reqData,const DataReceiver& dataRec, RequestResult& reqRes) const;

	void errorResult(RequestResult& reqRes) const;

	void setClientNewState(RequestResult & reqRes, const SOCKET& sock);

	void closedSocketProt(const SOCKET& sock);

	void closeRoomProtcol(const string& userName, const int& roomId);

	void leaveRoomProtocol(const string& userName, const int& roomId);

	void leaveGameProtocol(const string& userName, const int& gameId);

	void closeGameProtocol(const string& userName, const int& gameId);
};
