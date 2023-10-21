#pragma once
#include "RequestFactory.h"


//JsonResponsePacketDeserializer Singleton class, which is responsible for De serializing buffer to Requests.
class JsonRequestPacketDeserializer
{
public:
	// Get deserializer instance.
	static JsonRequestPacketDeserializer* getDeserializer();
	// Deserialize request from buffer.
	IRequest* deserializeRequest(const Buffer buffer, const unsigned char);

	// Destructor which deletes Request factory instance.
	~JsonRequestPacketDeserializer();

	// Singleton requirements.
	JsonRequestPacketDeserializer(const JsonRequestPacketDeserializer&) = delete;
	JsonRequestPacketDeserializer& operator=(const JsonRequestPacketDeserializer&) = delete;

	// Delete deserializer instance
	void deleteJsonDeserializer();

	// Get code from the buffer
	static void getCode(unsigned char&, const Buffer&);

	// Get number from the buffer and put it in the int variable that is provided.
	static void convert4BytesToInt(const char*, unsigned int&);
private:
	RequestFactory* _reqFact;
	static JsonRequestPacketDeserializer* _instance;

	// Constructor, initialize Request Factory.
	JsonRequestPacketDeserializer();
};

