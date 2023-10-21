#include "IRequest.h"


void SignUpRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _userName = jsonRequest[USERNAME].get<string>();
    _password = jsonRequest[PASSWORD].get<string>();
    _email    = jsonRequest[EMAIL].get<string>();
}

void LoginRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _userName = jsonRequest[USERNAME].get<string>();
    _password = jsonRequest[PASSWORD].get<string>();
}

void JoinRoomRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _ownerName = jsonRequest[OWNER_NAME].get<string>();
}

void CreateRoomRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _roomName      = jsonRequest[ROOM_NAME].get<string>();
    _maxUsers      = jsonRequest[MAX_USERS].get<int>();
    _questionCount = jsonRequest[QUESTIONS_COUNT].get<int>();
    _answerTimeOut = jsonRequest[ANSWER_TIME_OUT].get<int>();
}

void ChatMessageRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _sender  = jsonRequest[USERNAME].get<string>();
    _message = jsonRequest[MESSAGE].get<string>();
}

void SubmitAnswerRequest::convertMessageToStruct(const Json& jsonRequest)
{
    _time         = jsonRequest[TIME].get<int>();
    _answerNumber = jsonRequest[ANSWER].get<int>();
}
