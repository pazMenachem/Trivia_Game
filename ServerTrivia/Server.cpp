#include "Server.h"


Server::Server() : _wsaInit(),
				   _dataBase(SqliteDataBase::getInstance()),
				   _requestHandleFact(*(RequestHandlerFactory::getInstance(_dataBase))),
				   _communicator(Communicator::getInstance()){}

Server::~Server() { 
	JsonRequestPacketDeserializer::getDeserializer()->deleteJsonDeserializer();
	JsonResponsePacketSerializer::getSerializer()->deleteSerializer();
	_dataBase->deleteInstance();
	_requestHandleFact.deleteInstance();
}

void Server::run()
{
	createCommunicatorThread();

	string stop;
	while (stop != QUIT)
		cin >> stop;
}

void Server::createCommunicatorThread()
{
	thread communThread(&Communicator::startHandleRequests, _communicator);
	communThread.detach();
}