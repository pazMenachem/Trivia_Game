#pragma once
#include "IDataBase.h"
#include "sqlite3.h"
#include <fstream>
#include <sstream>


#define QUESTION_FILE_NAME "Questions.txt"
#define DB_NAME "TriviaDB.db"
#define AMOUNT_OF_ROWS_TO_TEST 5
#define AMOUNT_OF_ANSWERS 4

/**
 * @brief Represents a database using SQLite for data storage.
 *
 * This class implements the IDataBase interface and provides methods for interacting with an SQLite database.
 * It supports operations like user authentication, question retrieval, statistics management, and more.
 * 
 * Notes - Inherit from IDataBase
 */
class SqliteDataBase : public IDataBase {
public:
    /**
     * @brief Open the database connection.
     *
     * This method opens a connection to the SQLite database.
     *
     * @return True if the connection is successfully opened, false otherwise.
     */
    bool open() override;

    /**
     * @brief Close the database connection.
     *
     * This method closes the connection to the SQLite database.
     *
     * @return True if the connection is successfully closed, false otherwise.
     */
    bool close() override;

    /**
     * @brief Check if a user exists in the database.
     *
     * This method checks whether a user with the specified username exists in the database.
     *
     * @param userName The username to check.
     * @return True if the user exists, false otherwise.
     */
    bool doesUserExist(const string&) override;

    /**
     * @brief Check if a password matches a user's record.
     *
     * This method verifies if a provided password matches the stored password for a given username.
     *
     * @param userName The username for which to check the password.
     * @param pass The password to check.
     * @return True if the password matches, false otherwise.
     */
    bool doesPasswordMatch(const string&, const string&) override;

    /**
     * @brief Add a new user to the database.
     *
     * This method adds a new user with a username, password, and email to the database.
     *
     * @param userName The username of the new user.
     * @param pass The password of the new user.
     * @param email The email address of the new user.
     * @return True if the user is successfully added, false otherwise.
     */
    bool addNewUser(const string& userName, const string& pass, const string& email) override;

    /**
     * @brief Get a vector of questions from the database.
     *
     * This method retrieves a vector of questions from the database based on the specified number of questions.
     *
     * @param numOfQuestions The number of questions to retrieve.
     * @return A vector of Question objects.
     */
    vector<Question> getQuestions(int numOfQuestions) const override;


    /**
     * @brief Delete the instance of the database.
     */
    void deleteInstance();

    /**
     * @brief Get the singleton instance of the database.
     *
     * @return A pointer to the database instance.
     */
    static IDataBase* getInstance();

    // Statistics
    float getPlayerAverageAnswerTime(const string& userName) const override;
    int getNumOfCorrectAnswers(const string& userName) const override;
    int getNumOfTotalAnswers(const string& userName) const override;
    int getNumOfPlayerGames(const string& userName) const override;
    int getPlayerScore(const string& userName) const override;
    vector<pair<string, int>> getHighScores() const override;
    bool updateUserStatistics(const GameData& gameData, const string& userName) const override;

private:
	bool runQuery(const char* query);
	void createTables();
	bool addQuestionsToDB();
	bool readQuestionsFromFile();
	void addTestInfo(int amount);
	bool checkForErrorMessage() const;
	void addUserToStatisticsTable(const string userName) const;

	// Table Creation
	bool createStatisticsTable() override;
	bool createQuestionTable() override;
	bool createUserTable() override;

	// Default Constructor
	SqliteDataBase() = default;
	sqlite3* _dbPtr = nullptr;
	vector<Question> _questions;
};
