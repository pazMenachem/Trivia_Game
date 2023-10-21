#pragma once
#include "LoggedUser.h"
#include "SqliteDataBase.h"


using socketUserMap = std::map<string, SOCKET>;


/**
 * @brief Manages user authentication and session information.
 *
 * This class is responsible for managing user authentication, including signing up, logging in, and logging out.
 * It also maintains information about logged-in users, their sockets, and usernames.
 * Notes - Default Constructor is deleted, Valid dataBase pointer is needed.
 */
class LoginManager {
public:
    /**
     * @brief Constructor for LoginManager.
     *
     * @param dataBase A pointer to the database used for user data.
     */
    LoginManager(IDataBase* dataBase);

    /**
    * @brief Constructor is deleted to prevent creating Handler with out proper data.
    */
    LoginManager() = delete;

    /**
     * @brief Sign up a new user.
     *
     * This method allows a new user to sign up with the provided username, password, and email.
     *
     * @param userName The desired username for the new user.
     * @param password The password for the new user.
     * @param email The email address of the new user.
     * @return An integer representing the result of the sign-up operation.
     */
    int signUp(const string& userName, const string& password, const string& email);

    /**
     * @brief Log in a user.
     *
     * This method allows a user to log in with the provided username and password, associating their session
     * with a socket.
     *
     * @param userName The username of the user trying to log in.
     * @param password The password for the user.
     * @param clientSock The socket associated with the user's session.
     * @return An integer representing the result of the log-in operation.
     */
    int logIn(const string& userName, const string& password, SOCKET& clientSock);

    /**
     * @brief Log out a user.
     *
     * This method allows a user to log out, ending their session and disassociating the socket.
     *
     * @param userName The username of the user to log out.
     * @return An integer representing the result of the log-out operation.
     */
    int logOut(const string& userName);

    /**
     * @brief Get the username associated with a socket.
     *
     * This method retrieves the username associated with a given socket.
     *
     * @param sock The socket for which the username is requested.
     * @return The username associated with the socket.
     */
    string getUserName(const SOCKET& sock);

    /**
     * @brief Get information about a logged-in user.
     *
     * This method retrieves information about a logged-in user based on their username.
     *
     * @param userName The username of the user.
     * @return A pointer to a LoggedUser object, or nullptr if the user is not logged in.
     */
    LoggedUser* getLoggedUser(const string& userName);

    /**
     * @brief Get the socket associated with a username.
     *
     * This method retrieves the socket associated with a given username.
     *
     * @param userName The username for which the socket is requested.
     * @return A reference to the socket associated with the username.
     */
    SOCKET& getUserSocket(const string& userName);
private:
	IDataBase* _dataBase;
	vector<LoggedUser> _loggedUsers;
	mutex _mutex;
	unique_lock<mutex> _loginLock;
	socketUserMap _userNameSock;
};

