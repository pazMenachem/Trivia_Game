#pragma once
#include "Utils.h"

/**
 * @brief Represents a trivia question.
 *
 * This struct holds a trivia question, including the question text, possible answers, and the correct answer.
 */
struct Question {
    string _question; 
    string _answers[4]; 
    int _correctAnswer; 

    /**
     * @brief Check if an answer is correct.
     *
     * This method checks if the provided answer index is correct.
     *
     * @param answer The index of the answer to check.
     * @return True if the answer is correct, false otherwise.
     */
    bool checkAnswer(const int answer) { return _correctAnswer == answer; }
};

/**
 * @brief Represents game data.
 *
 * This struct holds game data, including player points, correct answers, total time, and the number of questions answered for each player.
 */
struct GameData {
    // User name  & number(points, amount of answer etc...)
    map<string, int> _playersPoints; 
    map<string, int> _correctAnswers; 
    map<string, int> _totalTime; 
    map<string, int> _amountOfQuestions;

    /**
     * @brief Default constructor for GameData.
     */
    GameData() = default;

    /**
     * @brief Constructor for GameData with player names.
     *
     * @param playerNames A vector of player usernames to initialize the game data.
     */
    GameData(const vector<string>&& playerNames) {
        for_each(playerNames.begin(), playerNames.end(), [this](const string& playerName) {
            _playersPoints[playerName] = 0;
            _correctAnswers[playerName] = 0;
            _totalTime[playerName] = 0;
            _amountOfQuestions[playerName] = 0;
            });
    }
};

/**
 * @brief Interface for database interactions.
 *
 * This interface defines methods for interacting with a database, including user authentication, statistics management, question retrieval, and more.
 * 
 * IMPORTANT NOTE - Databases that Inherit need to implement GetInstance and DeleteInstance.
 */
class IDataBase {
public:
    virtual bool open() = 0; /**< Open the database connection. */
    virtual bool close() = 0; /**< Close the database connection. */
    virtual bool doesUserExist(const string&) = 0; /**< Check if a user exists in the database. */
    virtual bool doesPasswordMatch(const string&, const string&) = 0; /**< Check if a password matches a user's record. */
    virtual bool addNewUser(const string& userName, const string& pass, const string& email) = 0; /**< Add a new user to the database. */
    virtual void deleteInstance() = 0; /**< Delete the database instance. */

    virtual float getPlayerAverageAnswerTime(const string& userName) const = 0; /**< Get a player's average answer time. */
    virtual int getNumOfCorrectAnswers(const string& userName) const = 0; /**< Get the number of correct answers for a player. */
    virtual int getNumOfTotalAnswers(const string& userName) const = 0; /**< Get the total number of answers for a player. */
    virtual int getNumOfPlayerGames(const string& userName) const = 0; /**< Get the number of games played by a player. */
    virtual int getPlayerScore(const string& userName) const = 0; /**< Get a player's score. */
    virtual vector<pair<string, int>> getHighScores() const = 0; /**< Get high scores. */
    virtual vector<Question> getQuestions(int numOfQuestions) const = 0; /**< Get questions from the database. */
    virtual bool updateUserStatistics(const GameData& gameData, const string& userName) const = 0; /**< Update user statistics. */

	virtual ~IDataBase() = default;
	IDataBase(const IDataBase&) = delete;
	IDataBase& operator=(const IDataBase&) = delete;
protected:
	virtual bool createQuestionTable() = 0;
	virtual bool createUserTable() = 0;
	virtual bool createStatisticsTable() = 0;
	IDataBase() = default;
	static IDataBase* _instance;
};
