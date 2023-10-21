#include "JsonResponsePacketSerializer.h"

JsonResponsePacketSerializer* JsonResponsePacketSerializer::_instance = nullptr;

JsonResponsePacketSerializer::~JsonResponsePacketSerializer() {}

JsonResponsePacketSerializer::JsonResponsePacketSerializer(){}

void JsonResponsePacketSerializer::convertIntTo4Bytes(const size_t num, char* result)
{
	memcpy(result, &num, AMOUNT_OF_BYTES_TO_COPY);
}

void JsonResponsePacketSerializer::convertCodeToChar(const size_t num, char& result)
{
	result = static_cast<byte>(num);
}

JsonResponsePacketSerializer* JsonResponsePacketSerializer::getSerializer()
{
	if (!_instance)
		_instance = new JsonResponsePacketSerializer();
	return _instance;
}

void JsonResponsePacketSerializer::deleteSerializer()
{
	delete _instance;
}

Buffer JsonResponsePacketSerializer::convertMsgToClient(const char& code, 
													    const string& msg){
	Buffer res;
	size_t msgLength = msg.size();
	char msgLengthInBytes[AMOUNT_OF_BYTES_FOR_INT];
	JsonResponsePacketSerializer::convertIntTo4Bytes(msgLength, msgLengthInBytes);

	return code + 
		   string(msgLengthInBytes, AMOUNT_OF_BYTES_TO_COPY) + 
		   msg;
}
