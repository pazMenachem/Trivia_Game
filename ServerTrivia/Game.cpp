#include "Game.h"

Game::Game(const Game&& res): _gameData(res._gameData), // Might need Move here
							  _questions(res._questions), // Might need Move here
							  _submitedAnswers(0),
							  _id(res._id),
							  _mutex(),
							  _conditionWaitForSubmit(),
							  _conditionWaitForAll(),
							  _owner(res._owner),
							  _currentQuestion(0),
							  _activePlayers(res._activePlayers){}

Game::Game(Room& room, vector<Question>&& questions) :_gameData(room.getAllUsers()),
													  _questions(questions),
													  _submitedAnswers(0),
													  _id(room.getRoomData()._id),
													  _mutex(),
													  _conditionWaitForSubmit(),
													  _conditionWaitForAll(),
													  _owner(room.getRoomData()._owner),
													  _currentQuestion(0),
													  _activePlayers(room.getAllUsers()){}

int Game::submitAnswer(const int answerNumber, const int time, const string userName)
{
	try {
		_gameData._amountOfQuestions.at(userName)++;
		_gameData._totalTime.at(userName) += time;

		if (_questions[_currentQuestion].checkAnswer(answerNumber)) // Right answer
		{
			_gameData._playersPoints.at(userName) += (120 - time) * 10;
			_gameData._correctAnswers.at(userName)++;
		}
		
		unique_lock<std::mutex> lock(_mutex); // Need to wait for all to answer
		_submitedAnswers++;

		_conditionWaitForSubmit.wait(lock, [&]() {
			if (_submitedAnswers == _activePlayers.size() || !_waitForPlayers)
			{
				_submitedAnswers--;
				_waitForPlayers = false;
				_conditionWaitForSubmit.notify_all();
				return true;
			}
			return false;
		});

		if (!_submitedAnswers)
		{
			_currentQuestion++;
			_waitForPlayers = true;
			_conditionWaitForAll.notify_all();
		}

		_conditionWaitForAll.wait(lock, [&]() {
			return _waitForPlayers;
		});
		
		return SUCCESS_SUBMITTING_ANSWER;
	}
	catch (const exception& e) {
		cout << __FUNCTION__ " Something went wrong " << e.what() << endl;
		return ERROR_SUBMITTING_ANSWER;
	}
}

int Game::getGameStats(Json& data)
{
	try {
		data[PLAYER_STATS]     = getCurrentPoints();
		data[CURRENT_QUESTION] = getCurrentQuestion();
		data[ACTIVE_PLAYERS]   = getNamesFromContainer(_activePlayers);
	}
	catch (const exception& e) {
		cout << __FUNCTION__ " something went wrong" << e.what() << endl;
		return ERROR_GETTING_GAME_STATS;
	}

	return SUCCESS_GETTING_GAME_STATS;
}

Json Game::getCurrentQuestion()
{
	Json data;
	// Game finished
	if (_currentQuestion == _questions.size())
	{
		data[FINISH_GAME] = true;
		return data;
	}
	Question& question   = _questions[_currentQuestion];
	data[QUESTION]		 = question._question;
	data[ANSWER_ONE]	 = question._answers[0];
	data[ANSWER_TWO]     = question._answers[1];
	data[ANSWER_THREE]	 = question._answers[2];
	data[ANSWER_FOUR]	 = question._answers[3];
	data[CORRECT_ANSWER] = question._correctAnswer;
	return data;
}

Json Game::getCurrentPoints()
{
	Json data;

	for_each(_gameData._playersPoints.begin(), _gameData._playersPoints.end(), [&](const pair<string, int>& iter) {
		data[iter.first] = iter.second;
	});
	return data;
}

//Private
GameData& Game::getGameData()
{
	return _gameData;
}

int Game::getGameId() const
{
	return _id;
}

string Game::getGameOwner() const
{
	return _owner;
}

vector<string> Game::GetActivePlayersNames()
{
	unique_lock<std::mutex> lock(_mutex);
	vector<string> res(_activePlayers);
	lock.unlock();

	return res;
}

void Game::LeaveGame(const string& playerName)
{
	unique_lock<std::mutex> lock(_mutex);
	for (auto iter = _activePlayers.begin(); iter != _activePlayers.end(); iter++)
		if (*iter == playerName)
		{
			_activePlayers.erase(iter);
			break;
		}
	lock.unlock();
	_conditionWaitForSubmit.notify_all();
}
