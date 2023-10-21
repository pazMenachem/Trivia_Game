#pragma once
#include "Game.h"


/**
 * @brief Manages active games.
 *
 * This class is responsible for managing active game instances, including creating new games, deleting games,
 * and retrieving game information based on game identifiers.
 */
class GameManager {
public:
    /**
     * @brief Constructor for GameManager.
     *
     * @param db A pointer to the database used for game data.
     */
    GameManager(IDataBase* db) : _games(), _db(db) {};
    
    /**
    * @brief Constructor is deleted to prevent creating Handler with out proper data.
    */
    GameManager() = delete;
    /**
     * @brief Create a new game.
     *
     * This method creates a new game associated with the provided room.
     *
     * @param room The room for which the game is created.
     */
    void CreateGame(Room& room);

    /**
     * @brief Delete a game by its unique identifier.
     *
     * This method deletes an active game based on its unique identifier.
     *
     * @param Id The unique identifier of the game to delete.
     */
    void deleteGame(const int Id);

    /**
     * @brief Get a game by its unique identifier.
     *
     * This method retrieves an active game based on its unique identifier.
     *
     * @param gameId The unique identifier of the game.
     * @return A reference to the retrieved game.
     */
    Game& getGameById(int gameId);
private:
	// <Room Id, Game>
	map<int, Game> _games;
	IDataBase* _db;
};

