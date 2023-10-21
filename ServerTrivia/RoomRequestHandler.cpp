#include "RoomRequestHandler.h"
#include "Communicator.h"

RoomRequestHandler::RoomRequestHandler(Room* room,
                                       LoggedUser loggedUser) : IRequestHandler(HANDLER_ROOM),
                                                                _room(room),
                                                                _loggedUser(loggedUser){}

bool RoomRequestHandler::isRequestRelevant(const RequestData& requestData) const
{
    if (requestData._code == CODE_START_GAME           ||
        requestData._code == CODE_GET_PLAYERS_IN_ROOM  ||
        requestData._code == CODE_CLOSE_ROOM           ||
        requestData._code == CODE_LEAVE_ROOM           ||
        requestData._code == CODE_CHAT_MESSAGE)
        return true;
    return false;
}

void RoomRequestHandler::handleRequest(RequestData& reqData, RequestResult& reqRes)
{   
    int roomId = _room->getRoomData()._id;
    auto&& players = _room->getAllUsers(); // Must keep, _room will be deleted (Close room)

    switch (reqData._code)
    {
    case CODE_GET_PLAYERS_IN_ROOM:
        getPlayersInRoom(reqData, reqRes);
        return;
    case CODE_LEAVE_ROOM:
        leaveRoom(reqData, reqRes);
        break;
    case CODE_START_GAME:
        startGame(reqData, reqRes);
        break;
    case CODE_CLOSE_ROOM:
        closeRoom(reqData, reqRes);
        break;
    case CODE_CHAT_MESSAGE:
        chatMessage(reqData, reqRes);
        break;
    default:
        cerr << ERROR_UNKNOWN(__FUNCTION__) << endl;
    }

    if(reqRes._broadCast)
        Communicator::getInstance()->broadCast(players,
                                               reqRes._responseMsg,
                                               reqRes._requestCode, 
                                               _loggedUser.getUserName(),
                                               roomId);
}

Room* RoomRequestHandler::getRoom() const
{
    return _room;
}

void RoomRequestHandler::getPlayersInRoom(RequestData& reqData, RequestResult& reqRes) const
{
    Json data = {
        {CODE,            CODE_SUCCESS},
        {PLAYERS_IN_ROOM, getNamesFromContainer(_room->getAllUsers())},
    };
    
    setRequestResult(reqRes, data);
}

void RoomRequestHandler::startGame(RequestData& reqData, RequestResult& reqRes) const
{
    _requestHandlerFactory.getGameManager().CreateGame(*_room);

    Json data = {
        {CODE, CODE_SUCCESS},
    };

    setRequestResult(reqRes, data);
    reqRes._broadCast = true;
    reqRes._newHandler = _requestHandlerFactory.createGameRequestHandler(_room->getRoomData()._id, _loggedUser.getUserName());
    _requestHandlerFactory.getRoomManager().deleteRoom(_room->getRoomData()._id);
}

void RoomRequestHandler::closeRoom(RequestData& reqData, RequestResult& reqRes) const
{
    _requestHandlerFactory.getRoomManager().deleteRoom(_room->getRoomData()._id);

    Json data = {
        {CODE,    CODE_SUCCESS},
        {MESSAGE, "Room has been closed by the admin"},
    };

    setRequestResult(reqRes, data);
    reqRes._broadCast = true;
    reqRes._newHandler = _requestHandlerFactory.createMenuRequestHandler(_loggedUser.getUserName());
}

void RoomRequestHandler::leaveRoom(RequestData& reqData, RequestResult& reqRes)
{
    Json data;

    int res = _room->removeUser(_loggedUser);
    if (res == ERROR_USER_NOT_IN_ROOM)
        data = {
            {CODE,    ERROR_USER_NOT_IN_ROOM},
            {MESSAGE, "User Not In Room"},
    };
    if (res == SUCCESS_REMOVING_USER)
    {
        data = {
            {CODE, CODE_SUCCESS},
        };

        reqRes._broadCast = true;
        reqRes._newHandler = _requestHandlerFactory.createMenuRequestHandler(_loggedUser.getUserName());
    }
    
    setRequestResult(reqRes, data);
}

void RoomRequestHandler::chatMessage(RequestData& reqData, RequestResult& reqRes) const {
    ChatMessageRequest* req = dynamic_cast<ChatMessageRequest*>(reqData._request);

    Json data = {
        {CODE,      CODE_SUCCESS},
        {BROADCAST, CODE_BC_NEW_CHAT_MESSAGE},
        {MESSAGE,   req->_message},
        {USERNAME,  req->_sender},
    };
    reqRes._broadCast = true;
    setRequestResult(reqRes, data);
}
