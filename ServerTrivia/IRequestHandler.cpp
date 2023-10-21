#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"


IRequestHandler::IRequestHandler(unsigned char type):_deserializer(JsonRequestPacketDeserializer::getDeserializer()),
													 _serializer(JsonResponsePacketSerializer::getSerializer()),
													 _requestHandlerFactory(*RequestHandlerFactory::getInstance()),
													 _handlerType(type)
{}
bool IRequestHandler::isRequestRelevant(const RequestData& requestData) const
{
	return false;
}

void IRequestHandler::setRequestResult(RequestResult& reqRes, Json& data) const
{
	data[REQUEST_CODE] = reqRes._requestCode;
	reqRes._resultCode = data[CODE].get<int>();
	reqRes._responseMsg = data.dump();
}

unsigned char IRequestHandler::getType() const
{
	return _handlerType;
}

