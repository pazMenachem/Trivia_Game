#include "RequestHandlerFactory.h"

RequestHandlerFactory* RequestHandlerFactory::_instance = nullptr;

unique_ptr<LoginRequestHandler> RequestHandlerFactory::createLoginRequestHandler()
{
    return make_unique<LoginRequestHandler>();
}

unique_ptr<MenuRequestHandler> RequestHandlerFactory::createMenuRequestHandler(const string& userName)
{
    return make_unique<MenuRequestHandler>(*_loginManager.getLoggedUser(userName));
}

unique_ptr<RoomRequestHandler> RequestHandlerFactory::createRoomRequestHandler(Room* rPtr,
                                                                               LoggedUser loggedUser)
{
    return make_unique<RoomRequestHandler>(rPtr, move(loggedUser));
}

unique_ptr<GameRequestHandler> RequestHandlerFactory::createGameRequestHandler(int gameId, const string& userName)
{
    return make_unique<GameRequestHandler>(_gameManager.getGameById(gameId),_loginManager.getLoggedUser(userName));
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
    return _loginManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
    return _roomManager;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
    return _statisticManager;
}

GameManager& RequestHandlerFactory::getGameManager()
{
    return _gameManager;
}

RequestHandlerFactory* RequestHandlerFactory::getInstance(IDataBase* dataBase)
{
        if (!_instance && dataBase)
            _instance = new RequestHandlerFactory(dataBase);
        return _instance;
}

void RequestHandlerFactory::deleteInstance()
{
    delete _instance;
}

RequestHandlerFactory::RequestHandlerFactory(IDataBase* dataBase) : _dataBase(dataBase),
                                                                    _loginManager(_dataBase),
                                                                    _statisticManager(_dataBase),
                                                                    _roomManager(),
                                                                    _gameManager(dataBase){}
