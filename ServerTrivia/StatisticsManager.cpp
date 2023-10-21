#include "StatisticsManager.h"

StatisticsManager::StatisticsManager(IDataBase* db):_db(db){}

vector<pair<string, int>> StatisticsManager::getHighScore()
{
	return _db->getHighScores();
}

map<string, float> StatisticsManager::getUserStatistics(const string& userName)
{	
	map<string, float> result;

	result[ANSWERS]			= static_cast<float>(_db->getNumOfTotalAnswers(userName));
	result[CORRECT_ANSWERS] = static_cast<float>(_db->getNumOfCorrectAnswers(userName));
	result[GAMES]			= static_cast<float>(_db->getNumOfPlayerGames(userName));
	result[AVERAGE_TIME]	= _db->getPlayerAverageAnswerTime(userName);
	result[POINTS]		    = static_cast<float>(_db->getPlayerScore(userName));

	return result;
}
