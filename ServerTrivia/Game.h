#pragma once

#include "IDataBase.h"
#include "Room.h"

class GameManager;

/**
 * @brief Represents a game instance.
 *
 * This class manages a game, including the game data, questions, player submissions, and game-specific functions.
 */
class Game {
public:
    /**
     * @brief Default constructor for Game.
     */
    Game() = default;

    /**
    * @brief Move constructor for Game.
    */
    Game(const Game&& res);

    /**
     * @brief Constructor for Game with provided room and questions.
     *
     * @param room The associated room for the game.
     * @param questions A vector of questions for the game.
     */
    Game(Room& room, vector<Question>&& questions);

    /**
     * @brief Submit an answer for the game.
     *
     * This method allows a player to submit an answer to the current question within the game.
     * The player will have to wait for other players to submit OR leave the game.
     *
     * @param answerNumber The selected answer number.
     * @param time The time taken to submit the answer.
     * @param userName The username of the player submitting the answer.
     * @return An integer representing the result of the answer submission.
     */
    int submitAnswer(const int answerNumber, const int time, const string userName);

    /**
     * @brief Get game statistics.
     *
     * This method retrieves game statistics and stores them in a provided JSON object.
     *
     * @param data The JSON object to store the game statistics.
     * @return An integer representing the result of retrieving game statistics.
     */
    int getGameStats(Json& data);

    /**
     * @brief Get the unique identifier of the game.
     *
     * This method retrieves the unique identifier of the game.
     *
     * @return The unique identifier of the game.
     */
    int getGameId() const;

    /**
     * @brief Get the username of the game owner.
     *
     * This method retrieves the username of the game owner.
     *
     * @return The username of the game owner.
     */
    string getGameOwner() const;

    /**
     * @brief Get the names of active players in the game.
     *
     * This method retrieves the names of active players currently in the game.
     *
     * @return A vector of usernames representing active players.
     */
    vector<string> GetActivePlayersNames();

    /**
     * @brief Leave the game.
     *
     * This method allows a player to leave the game.
     *
     * @param playerName The username of the player leaving the game.
     */
    void LeaveGame(const string& playerName);

    /**
     * @brief Friend class declaration for GameManager.
     */
    friend class GameManager;

private:
    /**
     * @brief Get the game data.
     *
     * This method retrieves the game data.
     *
     * @return A reference to the game data.
     */
    GameData& getGameData();

    /**
     * @brief Get the current question.
     *
     * This method retrieves the JSON representation of the current question.
     *
     * @return The JSON representation of the current question.
     */
    Json getCurrentQuestion();

    /**
     * @brief Get the current points.
     *
     * This method retrieves the JSON representation of the current points.
     *
     * @return The JSON representation of the current points.
     */
    Json getCurrentPoints();

	GameData _gameData;
	vector<Question> _questions;
	atomic<int> _submitedAnswers;
	int _id;
	mutex _mutex;
	condition_variable _conditionWaitForSubmit;
	condition_variable _conditionWaitForAll;
	string _owner;
	int _currentQuestion;
	vector<string> _activePlayers;
	bool _waitForPlayers = true;
};
