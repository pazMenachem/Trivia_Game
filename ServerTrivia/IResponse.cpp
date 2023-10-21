#include "IResponse.h"

void LoginResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void SignUpResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void ErrorResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS,  _status}, {MESSAGE, _message} }).dump();
}

void LogoutResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void CreateRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void JoinRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void GetRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status}, {ROOMS, _msg} }).dump();
}

void GetPlayersInRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status}, {PLAYERS_IN_ROOM, _msg} }).dump();
}

void HighScoreResponse::convertToMsg(string& message) const
{
	message = Json::object({ { STATUS, _status }, {HIGHSCORES, _highScore} }).dump();
}

void GetPersonalStatsResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS,           _status},
							 {ANSWERS,			_answers},
							 {GAMES,			_correctAnswers},
							 {CORRECT_ANSWERS,	_correctAnswers},
							 {AVERAGE_TIME,		_averageTime},
							 {POINTS,			_points}
						   }).dump();
}

void CloseRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void StartGameResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}

void GetRoomStateResponse::convertToMsg(string& message) const
{		
		message = Json::object({ {STATUS, _status},
							     {HAS_GAME_BEGUN, _hasGameBegun},
							     {PLAYERS_IN_ROOM, _players},
							     {ANSWER_TIME_OUT, _AnswerTimeOut} }).dump();
}

void LeaveRoomResponse::convertToMsg(string& message) const
{
	message = Json::object({ {STATUS, _status} }).dump();
}
