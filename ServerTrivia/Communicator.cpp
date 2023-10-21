#include "Communicator.h"
#pragma warning(suppress: 26800)

Communicator* Communicator::_instance = nullptr;

Communicator::Communicator() : _listenSocket(),
							   _clients(),
							   _mutex(),
							   _clientLock(_mutex, defer_lock),
							   _reqHandlerFact(*RequestHandlerFactory::getInstance())
{
	_listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_listenSocket == INVALID_SOCKET)
		throw exception(__FUNCTION__ " - socket");
	cout << "Listen Socket Created" << endl;
}

Communicator::~Communicator()
{
	try
	{
		closesocket(_listenSocket);
	}
	catch (const exception& e) { cout << "Error closing listening socket - " << e.what() << endl; }
}

void Communicator::errorResult(RequestResult& reqRes) const
{
	Json data;

	switch (reqRes._resultCode)
	{
		case ERROR_CODE_NOT_RELEVANT:
			data[MESSAGE] = "Code not relevant";
			break;
		case ERROR_UNVALID_CODE:
			data[MESSAGE] = "UnValid code Error";
			break;
		case ERROR_USER_ALREADY_EXISTS:
		case ERROR_USER_ALREADY_LOGGED_IN:
		case ERROR_WRONG_PASSWORD:
		case ERROR_USER_DOESNT_EXSITS:
		case ERROR_USER_NOT_IN_ROOM:
		case ERROR_ROOM_NOT_FOUND:
		case ERROR_ROOM_OWNER_NOT_FOUND:
		case ERROR_NO_SPACE_IN_ROOM:
			return;
		default:
			cerr << __FUNCTION__ "unknown Error" << endl;
			return;
	}

	reqRes._responseMsg = data.dump();
}

void Communicator::setClientNewState(RequestResult & reqRes, const SOCKET& sock)
{	
	if (!reqRes._newHandler)
		return;
	_clients[sock] = move(reqRes._newHandler);
}

void Communicator::closedSocketProt(const SOCKET& sock)
{

	_clientLock.lock();
	unique_ptr<IRequestHandler> handler = move(_clients.find(sock)->second);
	_clients.erase(sock);
	_clientLock.unlock();

	string playerName = _reqHandlerFact.getLoginManager().getUserName(sock);
	if (playerName.empty())
		return;

	switch (handler->getType())
	{
	case HANDLER_LOGIN:
	case HANDLER_MENU:
		break;
	case HANDLER_ROOM:
	{
		Room* room = dynamic_cast<RoomRequestHandler*>(handler.get())->getRoom();
		int roomId = room->getRoomData()._id;

		if (room->getRoomOwner() == playerName)
			closeRoomProtcol(playerName, roomId);
		else
			leaveRoomProtocol(playerName, roomId);
		break;
	}
	case HANDLER_GAME:
	{
		Game& game = dynamic_cast<GameRequestHandler*>(handler.get())->getGame();
		int gameId = game.getGameId();

		if (game.getGameOwner() == playerName)
			closeGameProtocol(playerName, gameId);
		else
			leaveGameProtocol(playerName, gameId);
		break;
	}
	default:
		cout << __FUNCTION__ " Undefined handler type." << endl;
		break;
	}
	_reqHandlerFact.getLoginManager().logOut(playerName);
}

void Communicator::leaveRoomProtocol(const string& userName, const int& roomId)
{
	Room& room = _reqHandlerFact.getRoomManager().getRoom(roomId);
	auto&& players = room.getAllUsers();

	room.removeUser(*_reqHandlerFact.getLoginManager().getLoggedUser(userName));

	Json data = {
				{CODE, CODE_SUCCESS},
				{MESSAGE, "Player " + userName + " Left."},
	};
	Communicator::getInstance()->broadCast(players,
										   data.dump(),
										   CODE_LEAVE_ROOM,
										   userName);
}

void Communicator::closeRoomProtcol(const string& userName, const int& roomId) {

	auto&& players = _reqHandlerFact.getRoomManager().getPlayersInRoom(roomId);
	_reqHandlerFact.getRoomManager().deleteRoom(roomId);

	Json data = {
				{CODE, CODE_SUCCESS},
				{MESSAGE, "Room Admin Disconnected"},
	};
	Communicator::getInstance()->broadCast(players,
										   data.dump(),
										   CODE_CLOSE_ROOM,
										   userName);
}

void Communicator::leaveGameProtocol(const string& userName, const int& gameId)
{
	_reqHandlerFact.getGameManager().getGameById(gameId).LeaveGame(userName);
}

void Communicator::closeGameProtocol(const string& userName, const int& gameId)
{
	auto&& players = _reqHandlerFact.getGameManager().getGameById(gameId).GetActivePlayersNames();
	_reqHandlerFact.getGameManager().deleteGame(gameId);

	Json data = {
		{CODE,    CODE_SUCCESS},
		{MESSAGE, "Game creator Disconnected."}
	};
	Communicator::getInstance()->broadCast(players,
										   data.dump(),
										   CODE_CLOSE_GAME,
										   userName);
}

void Communicator::broadCast(const vector<string>& names, string msg, unsigned char requestCode, string excludeUser, int gameId)
{
	try {
		SOCKET sock;
		string finalMsg = DataSender::prepareDataToBroadCast(requestCode, msg);

		for (auto& player : names)
		{
			if (player == excludeUser)
				continue;
			
			sock = _reqHandlerFact.getLoginManager().getUserSocket(player);
			if (requestCode == CODE_CLOSE_GAME)
				_clients[sock] = _reqHandlerFact.createMenuRequestHandler(string(player));
			if (requestCode == CODE_START_GAME)
				_clients[sock] = _reqHandlerFact.createGameRequestHandler(gameId, player);
			if (requestCode == CODE_CLOSE_ROOM)
				_clients[sock] = _reqHandlerFact.createMenuRequestHandler(string(player));
			DataSender::sendDataToDiffUser(sock, finalMsg);
		}
	}
	catch (...) { cerr << ERROR_UNKNOWN(__FUNCTION__); };
}

void Communicator::setRequestData(RequestData& reqData, 
								  const DataReceiver& dataRec,
								  RequestResult& reqRes) const
{
	reqData._receivalTime = chrono::system_clock::now();
	reqData._code = dataRec._messageCode;
	reqData._request = JsonRequestPacketDeserializer::getDeserializer()->deserializeRequest(dataRec._finalMsg, dataRec._messageCode);
	reqRes._requestCode = dataRec._messageCode;

	if (!reqData._request)
		reqRes._resultCode = ERROR_UNVALID_CODE;
}

void Communicator::getMessageFromClient(DataReceiver& dataRec)
{
	// Get code
	dataRec._bytesReadFromSocket = recv(dataRec._clientSocket,
										reinterpret_cast<char*>(&dataRec._messageCode),
										AMOUNT_OF_BYTES_FOR_CODE,
										0);
	if (dataRec._bytesReadFromSocket <= CLOSED_SOCKET) // Check if communication is closed.
		throw exception("Closed Socket ");

	// Get message Length
	dataRec._bytesReadFromSocket = recv(dataRec._clientSocket,
										dataRec._msgLengthCharArr,
										AMOUNT_OF_BYTES_FOR_INT,
										0);

	JsonRequestPacketDeserializer::convert4BytesToInt(dataRec._msgLengthCharArr, dataRec._sizeOfMessageInInt);

	// Get Message
	dataRec.setMessageSize();
	dataRec._bytesReadFromSocket = recv(dataRec._clientSocket,
										dataRec._finalMsg,
										dataRec._sizeOfMessageInInt,
										0);
	cout << "Test - Socket number : " << dataRec._clientSocket << endl;
	cout << "Test - Code Received : " << int(dataRec._messageCode) << endl;
	cout << "Test - Message Received : " << dataRec._finalMsg << endl;
};

void Communicator::startHandleRequests()
{
	bindAndListen();

	while (true)
		acceptClients();
}

Communicator* Communicator::getInstance()
{
	if (!_instance)
		_instance = new Communicator();
	return _instance;
}

void Communicator::deleteInstance()
{
	delete _instance;
}

void Communicator::bindAndListen() const
{
	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = IFACE;

	if (::bind(_listenSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	cout << "Listen Socket is binded." << endl;

	if (::listen(_listenSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	cout << "Listen Socket started listening." << endl;
}

void Communicator::communicateWithClient(SOCKET sock)
{
	DataReceiver dataRec(sock);
	RequestData reqData(sock);
	RequestResult reqRes;
	DataSender dataSender(sock);
	try 
	{
		while (true) 
		{
			try {
				// Receive message from client
				getMessageFromClient(dataRec);
			}
			// In case of closed socket
			catch (const exception& e) 
			{ 
				cerr << e.what() << sock << endl;
				throw;
			};

			// Analyze request
			setRequestData(reqData, dataRec, reqRes);

			// Handle Request
			if (reqData._request)
				if (_clients[sock]->isRequestRelevant(reqData))
					_clients[sock]->handleRequest(reqData, reqRes);
				else
					reqRes._resultCode = ERROR_CODE_NOT_RELEVANT;
			
			
			// Move Client State
			if (reqRes._resultCode == CODE_SUCCESS)
				setClientNewState(reqRes, sock);
			else
				errorResult(reqRes);

			// Send back message to client
			dataSender.setData(reqRes);
			dataSender.sendData();

			reqRes._broadCast = false;
			reqData.reset();
		}
	}
	catch (...) {
		cerr << __FUNCTION__ "Error with client - " << sock << endl;
		closedSocketProt(sock);
	}
}

void Communicator::acceptClients()
{
	const SOCKET& clientSocket = CreateNewClientSocket();

	_clientLock.lock();
	_clients.emplace(clientSocket, _reqHandlerFact.createLoginRequestHandler());
	_clientLock.unlock();

	thread newClientThread(&Communicator::communicateWithClient, this, clientSocket);
	newClientThread.detach();
}

SOCKET Communicator::CreateNewClientSocket()
{
	SOCKET clientSocket = accept(_listenSocket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	cout << "New Client received - Socket number " << clientSocket << endl;

	return clientSocket;
}
