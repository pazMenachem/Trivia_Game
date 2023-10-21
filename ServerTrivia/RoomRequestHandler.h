#pragma once
#include "RequestHandlerFactory.h"


class RequestHandlerFactory;


/**
 * @brief Handles requests of players in Waiting Room stage.
 *
 * This class is responsible for handling various requests related to a room, such as getting
 * players in the room, starting a game, closing a room, leaving a room,and sending chat messages.
 * It checks the relevance of the request and processes it accordingly.
 * 
 * Notes - default Constructor is deleted,
 *         Inherit from IRequestHandler.
 */
class RoomRequestHandler : public IRequestHandler {
public:
    /**
     * @brief Constructor for RoomRequestHandler.
     *
     * @param room The room to which the handler is associated.
     * @param loggedUser The logged-in user associated with the handler.
     */
    RoomRequestHandler(Room* room, LoggedUser loggedUser);

    /**
     * @brief Constructor is deleted to prevent creating Handler with out proper data.
     */
    RoomRequestHandler() = delete;

    /**
     * @brief Check if the request is relevant for this handler.
     *
     * This method determines whether the given request data is relevant for this handler.
     *
     * @param requestData The request data to be checked.
     * @return True if the request is relevant, false otherwise.
     */
    bool isRequestRelevant(const RequestData& requestData) const override;

    /**
     * @brief Handle the incoming request.
     *
     * This method processes the incoming request based on its type and provides
     * a response through the RequestResult.
     *
     * @param reqHanData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void handleRequest(RequestData& reqHanData, RequestResult& reqRes) override;

    /**
     * @brief Get the room associated with this handler.
     *
     * @return A pointer to the associated room.
     */
    Room* getRoom() const;

private:
    /**
     * @brief Handle a request to get players names in the room.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void getPlayersInRoom(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Handle a request to start a game.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     * Notes - BroadCast to other players include.
     */
    void startGame(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Handle a request to close the room.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     * Notes - BroadCast to other players include.
     */
    void closeRoom(RequestData& reqData, RequestResult& reqRes) const;

    /**
     * @brief Handle a request to leave the room.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     * Notes - BroadCast to other players include.
     */
    void leaveRoom(RequestData& reqData, RequestResult& reqRes);

    /**
     * @brief Handle a chat message request.
     *
     * @param reqData The request data to be handled.
     * @param reqRes The result of handling the request.
     * Notes - BroadCast to other players include.
     */
    void chatMessage(RequestData& reqData, RequestResult& reqRes) const;

	Room* _room;
	LoggedUser _loggedUser;
};

