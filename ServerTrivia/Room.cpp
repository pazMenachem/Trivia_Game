#include "Room.h"

Room::Room(const RoomData& roomData):_roomData(roomData), _users(){}

unsigned int Room::addUser(const LoggedUser& user)
{
	if (!checkIfRoomHasSpace())
		return ERROR_NO_SPACE_IN_ROOM;

	_roomData._numberOfCurrentPlayers++;
	_users.push_back(user);
	return SUCCESS_ADDING_USER;
}

unsigned int Room::removeUser(const LoggedUser& user)
{
	for (auto it = _users.begin(); it != _users.end(); it++)
		if (it->getUserName() == user.getUserName())
		{
			_users.erase(it);
			_roomData._numberOfCurrentPlayers--;
			return SUCCESS_REMOVING_USER;
		}
	return ERROR_USER_NOT_IN_ROOM;
}

vector<string> Room::getAllUsers() const
{
	vector<string> res;
	transform(_users.begin(), _users.end(), back_inserter(res),
		[](const LoggedUser& user) { return user.getUserName(); });
	return res;
}

RoomData& Room::getRoomData()
{
	return _roomData;
}

string Room::getRoomOwner() const
{
	return _roomData._owner;
}

bool Room::checkIfRoomHasSpace() const
{
	return _users.size() < _roomData._maxPlayers;
}
