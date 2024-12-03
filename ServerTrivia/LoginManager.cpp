#include "LoginManager.h"

LoginManager::LoginManager(IDataBase* dataBase) :_dataBase(dataBase),
												 _loggedUsers(), 
												 _mutex(), 
												 _loginLock(_mutex, defer_lock),
												 _userNameSock()
{}

int LoginManager::signUp(const string& userName, const string& password, const string& email)
{
	if (_dataBase->doesUserExist(userName))
	{
		cout << "User already exists." << endl;
		return ERROR_USER_ALREADY_EXISTS;
	}
	_dataBase->addNewUser(userName, password, email);

	return SUCCESS_SIGNUP;
}

int LoginManager::logIn(const string& userName, const string& password, SOCKET& clientSock)
{
	if (!_dataBase->doesUserExist(userName))
	{
		cout << "User doesn't exists." << endl;
		return ERROR_USER_DOESNT_EXSITS;
	}
	if (!_dataBase->doesPasswordMatch(userName, password))
	{
		cout << "Password doesn't match." << endl;
		return ERROR_WRONG_PASSWORD;
	}
	if(getLoggedUser(userName))
		return ERROR_USER_ALREADY_LOGGED_IN;

	_loginLock.lock();
	_userNameSock[userName] = clientSock;
	_loggedUsers.push_back(LoggedUser(userName));
	_loginLock.unlock();

	return SUCCESS_LOGIN;
}

int LoginManager::logOut(const string& userName)
{
	if (!_dataBase->doesUserExist(userName))
	{
		cout << "User doesn't exists." << endl;
		return ERROR_USER_DOESNT_EXSITS;
	}

	for (auto it = _loggedUsers.begin(); it != _loggedUsers.end(); it++) 
		if (it->getUserName() == userName)
		{
			_loginLock.lock();
			_userNameSock.erase(userName);
			_loggedUsers.erase(it);
			_loginLock.unlock();
			break;
		}
	
	return SUCCESS_LOGOUT;
}

string LoginManager::getUserName(const SOCKET& sock)
{
	for (auto& iter : _userNameSock)
		if (iter.second == sock)
			return iter.first;

	return "";
}

LoggedUser* LoginManager::getLoggedUser(const string& userName)
{
	for (auto& user : _loggedUsers)
		if (user.getUserName() == userName)
			return &user;
	return nullptr;
}

SOCKET& LoginManager::getUserSocket(const string& userName)
{
	return _userNameSock.at(userName);
}
