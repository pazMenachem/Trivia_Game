#include "RequestFactory.h"


IRequest* RequestFactory::createRequest(const unsigned char identifier) const
{
    switch (static_cast<int>(identifier)) {
    case CODE_SIGNUP:
        return new SignUpRequest();
    case CODE_LOGIN:
        return new LoginRequest();
    case CODE_JOIN_ROOM:
        return new JoinRoomRequest();
    case CODE_CREATE_ROOM:
        return new CreateRoomRequest();
    case CODE_CHAT_MESSAGE:
        return new ChatMessageRequest();
    case CODE_SUBMIT_ANSWER:
        return new SubmitAnswerRequest();
    case CODE_LEAVE_ROOM:
    case CODE_GET_PLAYERS_IN_ROOM:
    case CODE_LOGOUT:
    case CODE_GET_HIGHSCORE:
    case CODE_GET_STATISTICS:
    case CODE_CLOSE_ROOM:
    case CODE_START_GAME:
    case CODE_GET_ROOM_STATE:
    case CODE_GET_ROOMS_DATA:
    case CODE_GET_GAME_STATS:
    case CODE_LEAVE_GAME:
    case CODE_CLOSE_GAME:
        return new ProxyRequest();
    default:
        throw exception("Code does Not exists");
    }
}
