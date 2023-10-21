#pragma once
#include "Utils.h"


struct IResponse {
	IResponse(unsigned int status = CODE_SUCCESS) : _status(status) {};
	virtual void convertToMsg(string& message) const = 0;
	unsigned int _status;
};

struct CloseRoomResponse : public IResponse{
	CloseRoomResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {};
	void convertToMsg(string& message) const override;
};

struct StartGameResponse : public IResponse {
	StartGameResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {};
	void convertToMsg(string& message) const override;
};

struct GetRoomStateResponse : public IResponse {
	GetRoomStateResponse(bool hasGameBegun,
						 string players,
						 unsigned int answerTimeOut,
						 unsigned int status = CODE_SUCCESS) :
							IResponse(status),
							_hasGameBegun(hasGameBegun),
							_players(players),
							_AnswerTimeOut(answerTimeOut){};
	bool _hasGameBegun;
	string _players;
	unsigned int _AnswerTimeOut;

	void convertToMsg(string& message) const override;
};

struct LeaveRoomResponse : public IResponse {
	LeaveRoomResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {};
	void convertToMsg(string& message) const override;
};

struct LoginResponse : public IResponse {
	LoginResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {};
	void convertToMsg(string& message) const override;
};

struct SignUpResponse : public IResponse {
	SignUpResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {}
	void convertToMsg(string& message) const override;
};

struct ErrorResponse : public IResponse {
	ErrorResponse(const string& msg) :IResponse(CODE_ERROR), _message(msg) {};
	string _message;
	void convertToMsg(string& message) const override;
};
struct LogoutResponse : public IResponse {
	LogoutResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {}
	void convertToMsg(string& message) const override;
};

struct CreateRoomResponse : public IResponse {
	CreateRoomResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {}
	void convertToMsg(string& message) const override;
};

struct JoinRoomResponse : public IResponse {
	JoinRoomResponse(unsigned int status = CODE_SUCCESS) :IResponse(status) {}
	void convertToMsg(string& message) const override;
};

struct GetRoomResponse : public IResponse {
	GetRoomResponse(const string& msg, unsigned int status = CODE_SUCCESS ) :IResponse(status), _msg(msg) {};
	string _msg;
	void convertToMsg(string& message) const override;
};

struct GetPlayersInRoomResponse : public IResponse {
	GetPlayersInRoomResponse(const string& msg, unsigned int status = CODE_SUCCESS) :IResponse(status), _msg(msg) {};
	string _msg;
	void convertToMsg(string& message) const override;
};

struct HighScoreResponse : public IResponse {
	HighScoreResponse(const string& highScore,
					  unsigned int status = CODE_SUCCESS) :
					  IResponse(status),
					  _highScore(highScore) {};
	string _highScore;
	void convertToMsg(string& msg) const override;
};

struct GetPersonalStatsResponse : public IResponse {
	GetPersonalStatsResponse(const int answers,
							 const int correctAnswers,
							 const int games,
							 const float averageTime,
							 const int points,
							 unsigned int status = CODE_SUCCESS) :
							 IResponse(status),
							 _answers(answers),
							 _correctAnswers(correctAnswers), 
							 _games(games), 
							 _averageTime(averageTime), 
							 _points(points){};
	int _answers;
	int _correctAnswers;
	int _games;
	float _averageTime;
	int _points;
	void convertToMsg(string& message) const override;
};			