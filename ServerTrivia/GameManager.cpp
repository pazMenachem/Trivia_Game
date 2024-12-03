#include "GameManager.h"

void GameManager::CreateGame(Room& room)
{
    auto&& questions = _db->getQuestions(room.getRoomData()._numOfQuestionsInGame);
    _games.emplace(room.getRoomData()._id, Game(room, move(questions)));
}

void GameManager::deleteGame(const int Id)
{
    auto& gameData = _games[Id].getGameData();
    for (auto& player : gameData._playersPoints) 
        _db->updateUserStatistics(gameData, player.first);
    
    _games.erase(Id);
}

Game& GameManager::getGameById(int gameId)
{
    return _games[gameId];
}
