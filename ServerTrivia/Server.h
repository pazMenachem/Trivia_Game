#pragma once
#include "Communicator.h"
#include "WSAInitializer.h"
#include "SqliteDataBase.h"
#include "RequestHandlerFactory.h"


#define QUIT "quit"

//Server class which provides the main server functionality.
class Server {
public:
	// Initializes the WSA and the Communicator object using the default constructor.
	Server();
	//Deletes the singleton instances of the class
	//JsonRequestPacketDeserializer and JsonResponsePacketSerializer.
	~Server();
	// Runs the server by creating a communicator thread and waiting for the quit command.
	void run();

private:
	// Creates a new thread for the Communicator to handle requests.
	void createCommunicatorThread();

	WSAInitializer _wsaInit;
	IDataBase* _dataBase;
	RequestHandlerFactory& _requestHandleFact;
	Communicator* _communicator;
};

