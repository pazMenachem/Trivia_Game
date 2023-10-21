#pragma once
#include "RequestHandlerFactory.h"


class RequestHandlerFactory;


/**
 * @brief Handles requests specific to a game.
 *
 * This class is responsible for handling various requests related to a game, such as submitting game data,
 * leaving a game, fetching game statistics, and closing a game. It checks the relevance of the request and
 * processes it accordingly.
 * 
 * Notes - default Constructor is deleted,
 *         Inherit from IRequestHandler.
 */
class GameRequestHandler : public IRequestHandler {
public:
    /**
     * @brief Constructor for GameRequestHandler.
     *
     * @param game The game associated with the handler.
     * @param user The logged-in user associated with the game.
     */
    GameRequestHandler(Game& game, LoggedUser* user);

    /**
    * @brief Constructor is deleted to prevent creating Handler with out proper data.
    */
    GameRequestHandler() = delete;
    /**
     * @brief Check if the request is relevant for this handler.
     *
     * This method determines whether the given request data is relevant for this handler.
     *
     * @param requestData The request data to be checked.
     * @return True if the request is relevant, false otherwise.
     */
    virtual bool isRequestRelevant(const RequestData& requestData) const override;

    /**
     * @brief Handle the incoming request.
     *
     * This method processes the incoming request based on its type and provides a response through the RequestResult.
     *
     * @param requestData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    virtual void handleRequest(RequestData& requestData, RequestResult& reqRes) override;

    /**
     * @brief Get the associated game.
     *
     * @return A reference to the associated game.
     */
    Game& getGame() const;

private:
    /**
     * @brief Handle a request to submit game data.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void submitData(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a request to leave the game.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void leaveGame(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a request to fetch game statistics.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void getGameStats(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a request to close the game.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void closeGame(RequestData& reqData, RequestResult& reqRes);

	RequestHandlerFactory* _requestHandlerFact;
	Game& _game;
	LoggedUser& _user;
	GameManager& _gameManager;
};

