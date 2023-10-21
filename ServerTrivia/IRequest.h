#pragma once
#include "Utils.h"

/**
 * @brief Abstract base class for request objects.
 *
 * This class defines an abstract base for request objects, providing a pure
 * virtual function for converting a JSON message to a specific request structure.
 */
struct IRequest {
	/**
	* @brief Convert a JSON message to the specific request structure.
	*
	* This pure virtual function must be implemented in derived classes to
	* parse and initialize the request object from a JSON message.
	*
	* @param jsonRequest The JSON message representing the request.
	*/
	virtual void convertMessageToStruct(const Json& jsonRequest) = 0;
};

/**
 * @brief Represents a Login request structure.
 * Inherits from IRequest.
 */
struct LoginRequest : public IRequest {
	string _userName;
	string _password;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a SignUp request structure.
 * Inherits from IRequest.
 */
struct SignUpRequest : public IRequest {
	string _userName;
	string _password;
	string _email;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a JoinRoom request structure.
 * Inherits from IRequest.
 */
struct JoinRoomRequest : public IRequest {
	string _ownerName;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a Login request structure.
 * Inherits from IRequest.
 */
struct CreateRoomRequest : public IRequest {
	string _roomName;
	unsigned int _maxUsers;
	unsigned int _questionCount;
	unsigned int _answerTimeOut;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a Login request structure.
 * Inherits from IRequest.
 */
struct ChatMessageRequest : public IRequest {
	string _sender;
	string _message;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a Login request structure.
 * Inherits from IRequest.
 */
struct SubmitAnswerRequest : public IRequest {
	int _answerNumber;
	int _time;
	void convertMessageToStruct(const Json& jsonRequest) override;
};

/**
 * @brief Represents a Proxy request structure.
 * Inherits from IRequest.
 * Includes the following requests:
 * Logout
 * HighScore
 * Close room
 * Get room state
 * Get players in the room
 * Leave Room
 * Start Game
 * Leave Game
 * Close Game
 * Get Game stats
 */
struct ProxyRequest: public IRequest {
	void convertMessageToStruct(const Json& jsonRequest) override {};
};
