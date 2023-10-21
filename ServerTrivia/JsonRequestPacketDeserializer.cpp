#include "JsonRequestPacketDeserializer.h"

JsonRequestPacketDeserializer* JsonRequestPacketDeserializer::_instance = nullptr;

JsonRequestPacketDeserializer* JsonRequestPacketDeserializer::getDeserializer()
{
    if (!_instance)
        _instance = new JsonRequestPacketDeserializer();
    return _instance;
}

IRequest* JsonRequestPacketDeserializer::deserializeRequest(const Buffer buffer, const unsigned char code)
{
    try {
        Json data = Json::parse(buffer);
        IRequest* result = _instance->_reqFact->createRequest(code);
        result->convertMessageToStruct(data);
        return result;
    }
    catch (const exception& e){
        cerr << e.what() << endl;
        return nullptr;
    }
}

void JsonRequestPacketDeserializer::deleteJsonDeserializer(){delete _instance;}

JsonRequestPacketDeserializer::~JsonRequestPacketDeserializer(){delete _reqFact;}

JsonRequestPacketDeserializer::JsonRequestPacketDeserializer() :_reqFact(new RequestFactory()){}

void JsonRequestPacketDeserializer::getCode(unsigned char& code, const Buffer& buffer){
    memcpy(&code, buffer.c_str(), AMOUNT_OF_BYTES_FOR_CODE);
}

void JsonRequestPacketDeserializer::convert4BytesToInt(const char* buffer, unsigned int& msgSize)
{
    memcpy(&msgSize, buffer, AMOUNT_OF_BYTES_FOR_INT);
    msgSize = ntohl(msgSize);
}
