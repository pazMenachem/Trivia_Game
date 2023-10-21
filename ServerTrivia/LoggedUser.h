#pragma once
#include "Utils.h"


/**
 * @brief Represents a logged-in user.
 *
 * This class is a simple representation of a logged-in user, storing the user's username.
 */
class LoggedUser {
public:
    /**
     * @brief Default constructor for LoggedUser.
     */
    LoggedUser() = default;

    /**
     * @brief Constructor for LoggedUser with a provided username.
     *
     * @param userName The username of the logged-in user.
     */
    LoggedUser(const string& userName) : _userName(userName) {};

    /**
     * @brief Get the username of the logged-in user.
     *
     * This method retrieves the username of the logged-in user.
     *
     * @return The username of the logged-in user.
     */
    string getUserName() const { return _userName; };
private:
	string _userName;
};

