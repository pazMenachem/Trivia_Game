#pragma once
#include "IDataBase.h"


/**
 * @brief Manages user statistics and high scores.
 *
 * This class is responsible for managing user statistics and high scores. It provides methods
 * to retrieve high scores and user-specific statistics, such as performance metrics and game data.
 * 
 * Notes - Default Constructor is deleted, valid dataBase pointer need to be provided.
 */
class StatisticsManager {
public:
    /**
     * @brief Constructor for StatisticsManager.
     *
     * @param db A pointer to the database used for data storage.
     */
    StatisticsManager(IDataBase* db);

    /**
    * @brief Constructor is deleted to prevent creating Handler with out proper data.
    */
    StatisticsManager() = delete;

    /**
     * @brief Get the high scores.
     *
     * This method retrieves the high scores, which are represented as pairs of usernames and scores.
     *
     * @return A vector of pairs containing usernames and their corresponding scores.
     */
    vector<pair<string, int>> getHighScore();

    /**
     * @brief Get user-specific statistics.
     *
     * This method retrieves statistics specific to a given user, such as performance metrics and game data.
     *
     * @param userName The username for which statistics are requested.
     * @return A map containing user-specific statistics.
     * 
     * Notes - the statistics are: #answers, #correct answers, #games, average time for question, #points.
     */
    map<string, float> getUserStatistics(const string& userName);

private:
	IDataBase* _db;
};

