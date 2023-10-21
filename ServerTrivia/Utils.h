#pragma once

#define _CRTDBG_MAP_ALLOC
#define _DEV_

#pragma warning(push)
#pragma warning(disable : 4005)
#pragma warning(disable : 4706)
#pragma warning(disable : 4707)
#pragma warning(disable : 26495)

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <memory>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <WinSock2.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <random>

#include "Json.h"

#define Buffer string
using namespace std;
using Json = nlohmann::json;
class IRequestHandler;

// General
#define CLOSED_SOCKET               0
#define AMOUNT_OF_BYTES_FOR_CODE	1
#define PASS_CODE_MESSAGE_LENGTH	5
#define AMOUNT_OF_BYTES_FOR_INT		4
#define CODE_ERROR					0 // Response
#define CODE_SUCCESS				1 // Response

// Action Success 20 - 40
// Game
#define SUCCESS_SUBMITTING_ANSWER    20
#define SUCCESS_GETTING_GAME_STATS   21

// Room								 
#define SUCCESS_ADDING_USER			 22
#define SUCCESS_REMOVING_USER		 23
#define SUCCESS_ROOM_FOUND			 24
#define SUCCESS_CREATING_ROOM		 25

// Login Manager					 
#define SUCCESS_SIGNUP				 26
#define SUCCESS_LOGIN				 27
#define SUCCESS_LOGOUT				 28				

// Errors 50 - 80
#define ERROR_ROOM_NOT_FOUND		  -1
#define	ERROR_ROOM_OWNER_NOT_FOUND    -2
#define ERROR_UNVALID_CODE			  50
#define ERROR_CODE_NOT_RELEVANT		  51
#define ERROR_USER_ALREADY_EXISTS	  52
#define ERROR_USER_DOESNT_EXSITS	  53
#define ERROR_WRONG_PASSWORD		  54
#define ERROR_USER_ALREADY_LOGGED_IN  55
#define ERROR_NO_SPACE_IN_ROOM		  56
#define ERROR_USER_NOT_IN_ROOM		  57
#define ERROR_ROOM_NAME_ALREADY_TAKEN 58
#define ERROR_SUBMITTING_ANSWER       59
#define ERROR_GETTING_GAME_STATS      60

// Requests Codes 100 - 130
#define CODE_SIGNUP					 102
#define CODE_LOGIN					 103
#define CODE_LOGOUT					 104
#define CODE_JOIN_ROOM				 105
#define CODE_CREATE_ROOM			 106
#define CODE_GET_ROOMS_DATA			 107
#define CODE_GET_PLAYERS_IN_ROOM	 108
#define CODE_GET_HIGHSCORE			 109
#define CODE_GET_STATISTICS          110
#define CODE_CLOSE_ROOM				 111
#define CODE_START_GAME				 112
#define CODE_GET_ROOM_STATE			 113
#define CODE_LEAVE_ROOM				 114
#define CODE_CHAT_MESSAGE			 115
#define CODE_SUBMIT_ANSWER			 116
#define CODE_LEAVE_GAME				 117
#define CODE_GET_GAME_STATS			 118	
#define CODE_CLOSE_GAME				 119
#define CODE_JOIN_GAME				 120

// BroadCast Codes 200 - 210
#define CODE_BC_PLAYER_JOINED_LEFT	 200
#define CODE_BC_NEW_CHAT_MESSAGE	 201
#define CODE_BC_GAME_STARTED		 202
#define CODE_BC_ROOM_CLOSED			 203
#define CODE_BC_GAME_CLOSED			 204
						
// General Strings
#define BROADCAST					 "broadCast"
#define USERNAME                     "userName"
#define PASSWORD                     "password"
#define EMAIL                        "email"
#define ROOMID                       "roomId"
#define ROOM_NAME                    "roomName"
#define MAX_USERS                    "maxUsers"
#define QUESTIONS_COUNT              "questionCount"
#define ANSWER_TIME_OUT              "answerTimeOut"
#define STATUS						 "status"
#define MESSAGE						 "message"
#define ROOMS						 "rooms"
#define PLAYERS_IN_ROOM				 "playersInRoom"
#define HIGHSCORES					 "highScores"
#define ANSWERS						 "answers"
#define GAMES						 "games"
#define CORRECT_ANSWERS				 "correctAnswers"
#define AVERAGE_TIME				 "averageTime"
#define POINTS						 "points"
#define HAS_GAME_BEGUN				 "hasGameBegun"
#define CODE						 "code"
#define OWNER_NAME					 "ownerName"		
#define REQUEST_CODE				 "requestCode"
#define PLAYER_STATS				 "playerStats"
#define CURRENT_QUESTION		     "currentQuestion"
#define QUESTION					 "question"
#define ANSWER_ONE					 "answerOne"
#define ANSWER_TWO					 "answerTwo"
#define	ANSWER_THREE				 "answerThree"
#define	ANSWER_FOUR					 "answerFour"
#define CORRECT_ANSWER				 "correctAnswer"
#define ANSWER						 "answer"
#define TIME						 "time"
#define PLAYER_NAME					 "playerName"
#define ACTIVE_PLAYERS			     "activePlayers"
#define FINISH_GAME					 "finish"
#define ERROR_UNKNOWN(functionName)	 functionName " oops...Something went Wrong"

// Handlers type 250 - 255
#define HANDLER_LOGIN 250 
#define HANDLER_MENU  251
#define HANDLER_ROOM  252
#define HANDLER_GAME  253

/**
 * @brief Concatenates elements from a one-element based container into a comma-separated string.
 *
 * This function takes a generic container with one element per entry and concatenates its
 * elements into a single string where elements are separated by commas. The resulting string
 * does not end with a trailing comma.
 *
 * @note This function is designed for containers with a single element per entry and may not
 * work correctly with pair-based containers or more complex data structures.
 *
 * @tparam Container The type of the input container.
 * @param container The input container containing elements to be concatenated.
 * @return A string containing the concatenated elements.
 */
template <typename Container>
string getNamesFromContainer(const Container& container) {

	string res = "";
	
	for (auto name : container)
		res += name + ',';
	res.erase(res.find_last_of(','));
	
	return res;
}