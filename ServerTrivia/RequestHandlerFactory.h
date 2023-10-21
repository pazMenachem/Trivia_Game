#pragma once
#include "StatisticsManager.h"
#include "RoomManager.h"
#include "LoginManager.h"
#include "GameManager.h"

#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "RoomRequestHandler.h"
#include "GameRequestHandler.h"


class LoginRequestHandler;
class MenuRequestHandler;
class RoomRequestHandler;
class GameRequestHandler;


/**
 * @brief Factory for creating request handlers.
 *
 * This class serves as a factory for creating various request handlers. It allows the creation
 * of handlers for login requests, menu requests, room requests, and game requests. Additionally,
 * it provides access to manager instances responsible for login, rooms, statistics, and games.
 */
class RequestHandlerFactory {
public:
    /**
     * @brief Create a LoginRequestHandler.
     *
     * This method creates a unique pointer to a LoginRequestHandler instance.
     *
     * @return A unique pointer to a LoginRequestHandler.
     */
    unique_ptr<LoginRequestHandler> createLoginRequestHandler();

    /**
     * @brief Create a MenuRequestHandler.
     *
     * This method creates a unique pointer to a MenuRequestHandler instance.
     *
     * @param userName The username for which the handler is created.
     * @return A unique pointer to a MenuRequestHandler.
     */
    unique_ptr<MenuRequestHandler> createMenuRequestHandler(const string& userName);

    /**
     * @brief Create a RoomRequestHandler.
     *
     * This method creates a unique pointer to a RoomRequestHandler instance.
     *
     * @param rPtr A pointer to the associated room.
     * @param loggedUser The logged-in user associated with the handler.
     * @return A unique pointer to a RoomRequestHandler.
     */
    unique_ptr<RoomRequestHandler> createRoomRequestHandler(Room* rPtr, LoggedUser loggedUser);

    /**
     * @brief Create a GameRequestHandler.
     *
     * This method creates a unique pointer to a GameRequestHandler instance.
     *
     * @param gameId The identifier of the associated game.
     * @param userName The username for which the handler is created.
     * @return A unique pointer to a GameRequestHandler.
     */
    unique_ptr<GameRequestHandler> createGameRequestHandler(int gameId, const string& userName);

    /**
     * @brief Get the LoginManager instance.
     *
     * @return A reference to the LoginManager instance.
     */
    LoginManager& getLoginManager();

    /**
     * @brief Get the RoomManager instance.
     *
     * @return A reference to the RoomManager instance.
     */
    RoomManager& getRoomManager();

    /**
     * @brief Get the StatisticsManager instance.
     *
     * @return A reference to the StatisticsManager instance.
     */
    StatisticsManager& getStatisticsManager();

    /**
     * @brief Get the GameManager instance.
     *
     * @return A reference to the GameManager instance.
     */
    GameManager& getGameManager();

    /**
     * @brief Get the singleton instance of the RequestHandlerFactory.
     *
     * This method returns the singleton instance of the RequestHandlerFactory.
     *
     * @param dataBase must pass dataBase pointer in creation, default is only used to not pass arguments.
     * @return The singleton instance of the RequestHandlerFactory.
     */
    static RequestHandlerFactory* getInstance(IDataBase* dataBase = nullptr);

    /**
     * @brief Delete the singleton instance of the RequestHandlerFactory.
     *
     * This method deletes the singleton instance of the RequestHandlerFactory.
     */
    void deleteInstance();

    /**
     * @brief Copy constructor is deleted to prevent copying.
     */
    RequestHandlerFactory(const RequestHandlerFactory&) = delete;

    /**
     * @brief Copy assignment operator is deleted to prevent copying.
     */
    RequestHandlerFactory& operator=(const RequestHandlerFactory&) = delete;

private:
    /**
     * @brief Private constructor for the RequestHandlerFactory.
     *
     * This constructor is private to enforce the use of the singleton pattern. It allows
     * initializing the factory with database.
     *
     * @param dataBase valid dataBase pointer
     */
    RequestHandlerFactory(IDataBase* dataBase);
	static RequestHandlerFactory* _instance;
	IDataBase* _dataBase;
	LoginManager _loginManager;
	StatisticsManager _statisticManager;
	RoomManager _roomManager;
	GameManager _gameManager;
};

