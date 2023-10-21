#include "RoomManager.h"

unsigned int RoomManager::_roomId = 1;

RoomManager::RoomManager() : _rooms(),
							 _mutex(),
							 _roomLock(_mutex, defer_lock) {};


Room& RoomManager::createRoom(const LoggedUser& user, RoomData&& rd)
{
	rd._id = _roomId++;
	Room newRoom(rd);
	newRoom.addUser(user);
	_rooms[rd._id] = newRoom;

	return _rooms[rd._id];
}

bool RoomManager::deleteRoom(const unsigned int id)
{
	return _rooms.erase(id);
}

vector<RoomData> RoomManager::getRooms()
{
	vector<RoomData> res;
	for (auto& it : _rooms)
		res.emplace_back(it.second.getRoomData());
	return res;
}

Room& RoomManager::getRoom(const unsigned int id)
{
	return _rooms.find(id)->second;
}

vector<string> RoomManager::getPlayersInRoom(const unsigned int id) const
{
	return move(_rooms.find(id)->second.getAllUsers());
}

// USE THIS TO GET ROOM
// Unless the room exist for sure.
int RoomManager::getRoom(const unsigned int id, Room*& roomPtr)
{
	roomPtr = &_rooms[id];
	if (!roomPtr)
		return ERROR_ROOM_NOT_FOUND;
	
	return SUCCESS_ROOM_FOUND;
}

int RoomManager::getIdByOwner(const string userName)
{
	for (auto& iter : _rooms)
		if (iter.second.getRoomData()._owner == userName)
			return iter.second.getRoomData()._id;
	return ERROR_ROOM_OWNER_NOT_FOUND;
}

bool RoomManager::checkIfRoomExists(const string roomName)
{
	for (auto& room : _rooms)
		if (room.second.getRoomData()._roomName == roomName)
			return true;
	return false;
}

unsigned int RoomManager::getRoomByOwner(const string userName, Room*& roomPtr)
{
	int id = getIdByOwner(userName);

	if (id == ERROR_ROOM_OWNER_NOT_FOUND)
		return ERROR_ROOM_OWNER_NOT_FOUND;

	return getRoom(id, roomPtr);
}
