#pragma once
#include "RequestHandlerFactory.h"


class RequestHandlerFactory;


/**
 * @brief Handles menu-related requests for a user.
 *
 * This class is responsible for handling various menu-related requests, such as logging out,
 * retrieving room information, joining a room, creating a room, and fetching statistics. It checks
 * the relevance of the request and processes it accordingly.
 * 
 * Notes - Inherit from IRequestHandler,
 *         Default Constructor is deleted.
 *
 */
class MenuRequestHandler : public IRequestHandler {
public:
    /**
     * @brief Constructor for MenuRequestHandler.
     *
     * @param user The logged-in user associated with the handler.
     */
    MenuRequestHandler(LoggedUser user);

    /**
    * @brief Constructor is deleted to prevent creating Handler with out proper data.
    */
    MenuRequestHandler() = delete;

    /**
     * @brief Check if the request is relevant for this handler.
     *
     * This method determines whether the given request data is relevant for this handler.
     *
     * @param requestInfo The request data to be checked.
     * @return True if the request is relevant, false otherwise.
     */
    bool isRequestRelevant(const RequestData& requestInfo) const override;

    /**
     * @brief Handle the incoming request.
     *
     * This method processes the incoming request based on its type and provides
     * a response through the RequestResult.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void handleRequest(RequestData& reqData, RequestResult& reqRes) override;

private:
    /**
     * @brief Handle a request to log out.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void logOut(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Handle a request to get room information.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void getRooms(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Handle a request to join a room.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void joinRoom(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a request to create a room.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void createRoom(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a request to fetch user statistics.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void getStatistics(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Get rooms data as a formatted string.
     *
     * @return A string containing room data.
     */
    string getRoomsData() const;

    /**
     * @brief Get high score data as a formatted string.
     *
     * @return A string containing high score data.
     */
    string getHighScoreNames() const;

	RequestHandlerFactory* _reqHandlerFact;
	LoggedUser _user;
};
