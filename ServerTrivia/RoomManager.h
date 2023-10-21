#pragma once
#include "Room.h"


/**
 * @brief Manages game rooms and their associated data.
 *
 * This class is responsible for managing game rooms, including creating, deleting, and retrieving
 * information about rooms. It provides methods to create rooms, check if a room exists, delete rooms,
 * get a list of players in a room, retrieve a list of available rooms, and more.
 */
class RoomManager {
public:
    /**
     * @brief Constructor for RoomManager.
     */
    RoomManager();

    /**
     * @brief Create a new game room.
     *
     * This method creates a new game room with the provided owner and room data.
     *
     * @param user The owner of the room.
     * @param rd The room data.
     * @return A reference to the newly created room.
     */
    Room& createRoom(const LoggedUser& user, RoomData&& rd);

    /**
     * @brief Check if a room with the specified name exists.
     *
     * This method checks if a game room with the given name exists.
     *
     * @param roomName The name of the room to check.
     * @return True if a room with the name exists, false otherwise.
     */
    bool checkIfRoomExists(const string roomName);

    /**
     * @brief Delete a room by its unique identifier.
     *
     * This method deletes a game room with the specified unique identifier.
     *
     * @param id The unique identifier of the room to delete.
     * @return True if the room was successfully deleted, false otherwise.
     */
    bool deleteRoom(const unsigned int id);

    /**
     * @brief Get a list of players names in a room.
     *
     * This method retrieves the list of players names in a game room with the specified unique identifier.
     *
     * @param id The unique identifier of the room.
     * @return A vector of usernames representing the players in the room.
     */
    vector<string> getPlayersInRoom(const unsigned int id) const;

    /**
     * @brief Get a list of available rooms.
     *
     * This method retrieves a list of available game rooms.
     *
     * @return A vector of RoomData objects representing available rooms.
     */
    vector<RoomData> getRooms();

    /**
     * @brief Get a room by its owner's username.
     *
     * This method retrieves a game room owned by the specified username.
     *
     * @param userName The username of the room owner.
     * @param roomPtr A pointer to the retrieved room.
     * @return The unique identifier of the room, or ERROR_ROOM_OWNER_NOT_FOUND if not found.
     */
    unsigned int getRoomByOwner(const string userName, Room*& roomPtr);

    /**
     * @brief Get a room by its unique identifier.
     *
     * This method retrieves a game room with the specified unique identifier.
     *
     * @param id The unique identifier of the room.
     * @return A reference to the retrieved room.
     */
    Room& getRoom(const unsigned int id);

    /**
     * @brief Get the unique identifier of a room by its owner's username.
     *
     * This method retrieves the unique identifier of a room owned by the specified username.
     *
     * @param userName The username of the room owner.
     * @return The unique identifier of the room, or ERROR_ROOM_OWNER_NOT_FOUND if not found.
     */
    int getIdByOwner(const string userName);

    /**
     * @brief Get a room by its unique identifier.
     *
     * This method retrieves a game room with the specified unique identifier and assigns it to roomPtr.
     *
     * @param id The unique identifier of the room.
     * @param roomPtr A pointer to the retrieved room.
     * @return SUCCESS_ROOM_FOUND if the room is found, ERROR_ROOM_NOT_FOUND if not found.
     */
    int getRoom(const unsigned int id, Room*& roomPtr);

private:
	map<unsigned int, Room> _rooms;
	static unsigned int _roomId;
	mutex _mutex;
	unique_lock<mutex> _roomLock;
};

