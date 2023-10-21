#pragma once
#include "LoggedUser.h"


/**
 * @brief Represents data for a game room.
 *
 * This struct holds essential information about a game room, including its unique identifier,
 * name, maximum number of players, number of questions in the game, time per question,
 * current number of players, and the room owner's username.
 */
struct RoomData {
	unsigned int _id;
	string _roomName;
	unsigned int _maxPlayers;
	unsigned int _numOfQuestionsInGame;
	unsigned int _timePerQuestion;
	unsigned int _numberOfCurrentPlayers = 0;
	string _owner;
};

/**
 * @brief Represents a game room.
 *
 * This class is responsible for managing a game room, including adding and removing users,
 * retrieving information about the room, and checking if the room has available space.
 */
class Room
{
public:
    /**
    * @brief Default constructor for Room.
    */
    Room() = default;

    /**
     * @brief Constructor for Room with provided room data.
     *
     * @param roomData The room data to initialize the room.
     */
    Room(const RoomData& roomData);

    /**
     * @brief Add a user to the room.
     *
     * This method adds a user to the game room and returns the updated number of players.
     *
     * @param user The user to add to the room.
     * @return SUCCESS_ADDING_USER or ERROR_NO_SPACE_IN_ROOM if room is full.
     */
    unsigned int addUser(const LoggedUser& user);

    /**
     * @brief Remove a user from the room.
     *
     * This method removes a user from the game room and returns the updated number of players.
     *
     * @param user The user to remove from the room.
     * @return SUCCESS_REMOVING_USER or ERROR_USER_NOT_IN_ROOM.
     */
    unsigned int removeUser(const LoggedUser& user);

    /**
     * @brief Get a list of all users in the room.
     *
     * This method retrieves a vector of usernames representing all users in the room.
     *
     * @return A vector of usernames of users in the room.
     */
    vector<string> getAllUsers() const;

    /**
     * @brief Get the room data.
     *
     * This method retrieves the room data, including its settings and owner.
     *
     * @return A reference to the room data.
     */
    RoomData& getRoomData();

    /**
     * @brief Get the username of the room owner.
     *
     * This method retrieves the username of the room owner.
     *
     * @return The username of the room owner.
     */
    string getRoomOwner() const;


private:
    /**
    * @brief Check if the room has available space for new users.
    *
    * This method checks if there is available space for new users to join the room.
    *
    * @return True if there is space, false otherwise.
    */
	bool checkIfRoomHasSpace() const;

    RoomData _roomData;
    vector<LoggedUser> _users;
};