#include "ResponseFactory.h"

unique_ptr<IResponse> ResponseFactory::createResponse(const Json& data)
{
    switch (data[CODE].get<int>()) {
    case CODE_LOGIN:
        return make_unique<LoginResponse>();
    case CODE_SIGNUP:
        return make_unique<SignUpResponse>();
    case CODE_LOGOUT:
        return make_unique<LogoutResponse>();
    case CODE_CREATE_ROOM:
        return make_unique<CreateRoomResponse>();
    case CODE_JOIN_ROOM:
        return make_unique<JoinRoomResponse>();
    case CODE_GET_ROOMS:
        return make_unique<GetRoomResponse>(data[ROOMS].get<string>());
    case CODE_GET_PLAYERS_IN_ROOM:
        return make_unique<GetPlayersInRoomResponse>(data[PLAYERS_IN_ROOM].get<string>());
    case CODE_GET_HIGH_SCORE:
        return make_unique<HighScoreResponse>(data[HIGHSCORES].get<string>());
    case CODE_GET_STATISTICS:
        return make_unique<GetPersonalStatsResponse>(data[ANSWERS].get<int>(),
                                                     data[CORRECT_ANSWERS].get<int>(),
                                                     data[GAMES].get<int>(),
                                                     data[AVERAGE_TIME].get<float>(),
                                                     data[POINTS].get<int>());
    case CODE_GET_ROOM_STATE:
        return make_unique<GetRoomStateResponse>(data[HAS_GAME_BEGUN],
                                                 data[PLAYERS_IN_ROOM],
                                                 data[ANSWER_TIME_OUT]);
    case CODE_CLOSE_ROOM:
        return make_unique<CloseRoomResponse>();
    case CODE_START_GAME:
        return make_unique<StartGameResponse>();
    case CODE_LEAVE_ROOM:
        return make_unique<LeaveRoomResponse>();
    case CODE_ERROR:
        return make_unique<ErrorResponse>(data[MESSAGE].get<string>());
    default:
        cerr << "Code Error At Response Factory" << endl;
        return nullptr;
    }
}
