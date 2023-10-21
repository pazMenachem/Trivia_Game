#pragma once
#include "Utils.h"


#define AMOUNT_OF_BYTES_TO_COPY 4
#define AMOUNT_OF_BYTES_FOR_NUM 5
#define BYTE 1


//JsonResponsePacketSerializer Singleton class, which is responsible for serializing responses to JSON.
class JsonResponsePacketSerializer
{
public:
	// Static method that returns the singleton instance of JsonResponsePacketSerializer.
	static JsonResponsePacketSerializer* getSerializer();
	// Converts a response to a buffer.
	static Buffer convertMsgToClient(const char& code, const string& message);
	// Converts an integer to 4 bytes and stores the result in the given character array.
	static void convertIntTo4Bytes(const size_t, char*);
	// Converts a code to a character.
	static void convertCodeToChar(const size_t, char&);

	//Singleton requirements.
	JsonResponsePacketSerializer(const JsonResponsePacketSerializer&) = delete;
	JsonResponsePacketSerializer operator=(const JsonResponsePacketSerializer&) = delete;
	//Deletes the ResponseFactory instance.
	~JsonResponsePacketSerializer();
	// Deletes the singleton instance of JsonResponsePacketSerializer.
	void deleteSerializer();
private:
	static JsonResponsePacketSerializer* _instance;

	//constructor: Initializes the ResponseFactory object.
	JsonResponsePacketSerializer();
};

