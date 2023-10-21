#include "GameRequestHandler.h"
#include "Communicator.h"

GameRequestHandler::GameRequestHandler(Game& game, LoggedUser* user) : IRequestHandler(HANDLER_GAME),
                                                                       _game(game),
                                                                       _user(*user), 
                                                                       _gameManager(_requestHandlerFactory.getGameManager())
                                                                         
{}

bool GameRequestHandler::isRequestRelevant(const RequestData& requestData) const
{
    if (requestData._code == CODE_SUBMIT_ANSWER  ||
        requestData._code == CODE_LEAVE_GAME     ||
        requestData._code == CODE_GET_GAME_STATS )
        return true;
    if (requestData._code == CODE_CLOSE_GAME && _game.getGameOwner() == _user.getUserName())
        return true;
    return false;
}

void GameRequestHandler::handleRequest(RequestData& requestData, RequestResult& reqRes)
{
    auto&& players = _game.GetActivePlayersNames();
    switch (requestData._code) {
    case CODE_GET_GAME_STATS:
        getGameStats(requestData, reqRes);
        break;
    case CODE_LEAVE_GAME:
        leaveGame(requestData, reqRes);
        break;
    case CODE_SUBMIT_ANSWER:
        submitData(requestData, reqRes);
        break;
    case CODE_CLOSE_GAME:
        closeGame(requestData, reqRes);
        break;
    default:
        cerr << ERROR_UNKNOWN(__FUNCTION__) << endl;
    }
    
    if (reqRes._broadCast)
        Communicator::getInstance()->broadCast(players,
                                               reqRes._responseMsg,
                                               reqRes._requestCode,
                                               _user.getUserName());
}

Game& GameRequestHandler::getGame() const
{
    return _game;
}

void GameRequestHandler::submitData(RequestData& reqData, RequestResult& reqRes)
{
    SubmitAnswerRequest* submitReq = dynamic_cast<SubmitAnswerRequest*>(reqData._request);
    Json data;
    int res = _game.submitAnswer(submitReq->_answerNumber, submitReq->_time, _user.getUserName());

    if (res == SUCCESS_SUBMITTING_ANSWER)
    {
        res = _game.getGameStats(data);
        if (res == SUCCESS_GETTING_GAME_STATS)
            data[CODE] = CODE_SUCCESS;
        
        if (res == ERROR_GETTING_GAME_STATS)
        {
            data[CODE]    = CODE_ERROR;
            data[MESSAGE] = "Error getting game stats.";
        }
    }

    if (res == ERROR_SUBMITTING_ANSWER)
        data = {
            {CODE,    CODE_ERROR},
            {MESSAGE, "Error submitting answer."}
        };

    setRequestResult(reqRes, data);
}

void GameRequestHandler::leaveGame(RequestData& reqData, RequestResult& reqRes)
{
    _game.LeaveGame(_user.getUserName());
    Json data = {
        {CODE,        CODE_SUCCESS},
        {PLAYER_NAME, _user.getUserName()}
    };

    setRequestResult(reqRes, data);
    //reqRes._broadCast = true; // To send Chat message later on ** not working yet **
    reqRes._newHandler = _requestHandlerFactory.createMenuRequestHandler(_user.getUserName());
}

void GameRequestHandler::getGameStats(RequestData& reqData, RequestResult& reqRes)
{
    Json data;
    int res = _game.getGameStats(data);
    
    if (res == SUCCESS_GETTING_GAME_STATS)
        data[CODE] = CODE_SUCCESS;

    setRequestResult(reqRes, data);
}

void GameRequestHandler::closeGame(RequestData& reqData, RequestResult& reqRes)
{
    _gameManager.deleteGame(_game.getGameId());

    Json data = {
        {CODE,    CODE_SUCCESS},
        {MESSAGE, "Game creator left."}
    };

    setRequestResult(reqRes, data);
    reqRes._broadCast = true;
    reqRes._newHandler = _requestHandlerFactory.createMenuRequestHandler(_user.getUserName());
}
