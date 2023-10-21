#include "MenuRequestHandler.h"
#include "Communicator.h"

MenuRequestHandler::MenuRequestHandler(LoggedUser user): IRequestHandler(HANDLER_MENU),
                                                         _reqHandlerFact(RequestHandlerFactory::getInstance()),
                                                         _user(user){}

bool MenuRequestHandler::isRequestRelevant(const RequestData& requestData) const
{
    if (requestData._code == CODE_CREATE_ROOM    ||
        requestData._code == CODE_GET_ROOMS_DATA ||
        requestData._code == CODE_JOIN_ROOM      ||
        requestData._code == CODE_GET_STATISTICS ||
        requestData._code == CODE_LOGOUT)
        return true;
    return false;
}

void MenuRequestHandler::handleRequest(RequestData& reqData, RequestResult & reqRes)
{
    switch (reqData._code)
    {
        case CODE_CREATE_ROOM:
        {
            createRoom(reqData, reqRes);
            break;
        }
        case CODE_LOGOUT:
        {
            logOut(reqData, reqRes);
            break;
        }
        case CODE_GET_ROOMS_DATA:
        {
            getRooms(reqData, reqRes);
            break;
        }
        case CODE_GET_STATISTICS:
        {
            getStatistics(reqData, reqRes);
            break;
        }
        case CODE_JOIN_ROOM:
        {
            joinRoom(reqData, reqRes);
            break;
        }
        default:
            cerr << __FUNCTION__ << " Something went wrong..." << endl;
    }
    return;
}

void MenuRequestHandler::logOut(RequestData& reqData, RequestResult& reqRes) const
{
    Json data;
    int res = _reqHandlerFact->getLoginManager().logOut(_user.getUserName());
    
    if (res == ERROR_USER_DOESNT_EXSITS)
        data = {
                {CODE, CODE_ERROR},
                {MESSAGE, "User doesn't exists."}
        };
    if (res == SUCCESS_LOGOUT)
        data = {
                {CODE, CODE_SUCCESS}
        };

    setRequestResult(reqRes, data);
    reqRes._newHandler = _reqHandlerFact->createLoginRequestHandler();
}

void MenuRequestHandler::getRooms(RequestData& reqData, RequestResult& reqRes) const
{
    Json data = {
        {CODE,  CODE_SUCCESS},
        {ROOMS, getRoomsData()}
    };

    setRequestResult(reqRes, data);
}

void MenuRequestHandler::joinRoom(RequestData& reqData, RequestResult& reqRes)
{
    Room* roomPtr = nullptr;
    string owner = dynamic_cast<JoinRoomRequest*>(reqData._request)->_ownerName;
    int res = _reqHandlerFact->getRoomManager().getRoomByOwner(owner, roomPtr);

    Json data;

    if (res == ERROR_ROOM_NOT_FOUND)
        data = {
            {CODE,    ERROR_ROOM_NOT_FOUND},
            {MESSAGE, "Room not found."}
        };

    if (res == ERROR_ROOM_OWNER_NOT_FOUND)
        data = {
            {CODE,    ERROR_ROOM_OWNER_NOT_FOUND},
            {MESSAGE, "Room owner not found."}
        };

    if (res == SUCCESS_ROOM_FOUND)
    {
        res = roomPtr->addUser(_user);
        if (res == ERROR_NO_SPACE_IN_ROOM)
            data = {
                    {CODE,    ERROR_NO_SPACE_IN_ROOM},
                    {MESSAGE, "Room is full."},
                };

        if (res == SUCCESS_ADDING_USER)
        {
            data = {
                {CODE,   CODE_SUCCESS},
                {ROOMID, roomPtr->getRoomData()._id}
            };
            reqRes._newHandler = _reqHandlerFact->createRoomRequestHandler(roomPtr, move(_user));
            reqRes._broadCast = true;
        }
    }

    setRequestResult(reqRes, data);
    if (reqRes._broadCast)
        Communicator::getInstance()->broadCast(_reqHandlerFact->getRoomManager().getPlayersInRoom(roomPtr->getRoomData()._id),
                                               reqRes._responseMsg, 
                                               reqData._code, 
                                               _user.getUserName());
}

void MenuRequestHandler::createRoom(RequestData& reqData, RequestResult& reqRes)
{
    CreateRoomRequest* createRoomReq;
    RoomData rd;
    Json data;
    Room* roomPtr;
    createRoomReq = dynamic_cast<CreateRoomRequest*>(reqData._request);

    if (!_reqHandlerFact->getRoomManager().checkIfRoomExists(createRoomReq->_roomName))
    {
        rd._roomName = createRoomReq->_roomName;
        rd._maxPlayers = createRoomReq->_maxUsers;
        rd._numOfQuestionsInGame = createRoomReq->_questionCount;
        rd._timePerQuestion = createRoomReq->_answerTimeOut;
        rd._owner = _user.getUserName();
        roomPtr = &_reqHandlerFact->getRoomManager().createRoom(_user, move(rd));

        data = {
            {CODE,   CODE_SUCCESS},
            {ROOMID, roomPtr->getRoomData()._id},
        };

        reqRes._newHandler = _reqHandlerFact->createRoomRequestHandler(roomPtr, move(_user));
    }
    else 
        data = {
            {CODE,    CODE_ERROR},
            {MESSAGE, "Room name already taken"}
        };

    setRequestResult(reqRes, data);
}

void MenuRequestHandler::getStatistics(RequestData& reqData, RequestResult& reqRes) const
{
    auto&& stats = _reqHandlerFact->getStatisticsManager().getUserStatistics(_user.getUserName());

    Json data = {
        {CODE,            CODE_SUCCESS},
        {ANSWERS,         stats[ANSWERS]},
        {GAMES,           stats[GAMES]},
        {AVERAGE_TIME,    stats[AVERAGE_TIME]},
        {POINTS,          stats[POINTS]},
        {CORRECT_ANSWERS, stats[CORRECT_ANSWERS]},
        {HIGHSCORES,      getHighScoreNames()}
    };

    setRequestResult(reqRes, data);
}

string MenuRequestHandler::getRoomsData() const
{
    auto&& rooms = _reqHandlerFact->getRoomManager().getRooms();
    string roomsData = "";

    for (auto& room : rooms)
        roomsData +=
            room._roomName                          + ',' +
            to_string(room._numOfQuestionsInGame)   + ',' +
            to_string(room._timePerQuestion)        + ',' +
            to_string(room._maxPlayers)             + ',' +
            to_string(room._numberOfCurrentPlayers) + ',' +
            room._owner                             + ';';

    return roomsData;
}

string MenuRequestHandler::getHighScoreNames() const {

    auto&& highScores = _reqHandlerFact->getStatisticsManager().getHighScore();
    string result = "";

    for (const auto& playerNpoints : highScores)
        result += playerNpoints.first             + "," +
                  to_string(playerNpoints.second) + ";";

    result.erase(result.find_last_of(';'));
    return result;
}
