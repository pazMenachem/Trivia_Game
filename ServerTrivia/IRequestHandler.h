#pragma once
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"


class RequestHandlerFactory;

/**
 * @brief Result structure for request handling.
 *
 * This structure holds the result of handling a request, including the response message,
 * result code, request code, broadcast flag, and a new request handler if applicable.
 */
struct RequestResult {
    RequestResult() = default;

    Buffer _responseMsg; /**< The response message to be sent. */
    unsigned char _resultCode; /**< The result code indicating the outcome of the request. */
    unsigned char _requestCode; /**< The code identifying the type of request. */
    bool _broadCast; /**< A flag indicating if the response should be broadcasted. */
    unique_ptr<IRequestHandler> _newHandler = nullptr; /**< A new request handler if a change is required. */
};

/**
 * @brief Data structure for request handling.
 *
 * This structure contains data related to request handling, including the client socket,
 * the request object, request code, and the time of receival.
 */
struct RequestData {
    RequestData(SOCKET& sock) : _clientSock(sock) {};

    // Data
    SOCKET& _clientSock; /**< The client's socket for communication. */
    IRequest* _request = nullptr; /**< The request object to be handled. */
    unsigned int _code; /**< The code identifying the type of request. */
    chrono::system_clock::time_point _receivalTime; /**< The time of request receival. */

    ~RequestData() { delete _request; }
    void reset() { delete _request; _request = nullptr; }
};

/**
 * @brief Interface for request handler.
 *
 * This interface defines the contract for handling different types of requests.
 * It includes methods for checking if a request is relevant, handling the request,
 * and setting the request result.
 */
class IRequestHandler {
public:
    /**
     * @brief Constructor for IRequestHandler.
     *
     * @param type The handler type.
     */
    IRequestHandler(unsigned char type);

    /**
     * @brief Check if the request is relevant for this handler.
     *
     * This method determines whether the given request code is relevant for this handler.
     *
     * @param requestData Contains the request code.
     * @return True if the request is relevant, false otherwise.
     */
    virtual bool isRequestRelevant(const RequestData& requestData) const = 0;

    /**
     * @brief Handle the incoming request.
     *
     * This method processes the incoming request based on its type and provides
     * a response through the RequestResult.
     *
     * @param requestData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    virtual void handleRequest(RequestData& requestData, RequestResult& reqRes) = 0;

    /**
     * @brief Destructor for IRequestHandler.
     */
    virtual ~IRequestHandler() = default;

    /**
     * @brief Set the request result.
     *
     * This method sets the result of handling a request, including the response message,
     * result code, request code, based on the provided JSON data.
     *
     * @param reqRes The result of handling the request.
     * @param data The JSON data used to set the result.
     */
    void setRequestResult(RequestResult& reqRes, Json& data) const;

    /**
     * @brief Get the type of the request handler.
     *
     * @return The type of the request handler.
     */
    unsigned char getType() const;

protected:
    JsonRequestPacketDeserializer* _deserializer;
    JsonResponsePacketSerializer* _serializer;
    RequestHandlerFactory& _requestHandlerFactory;
    unsigned char _handlerType;
};