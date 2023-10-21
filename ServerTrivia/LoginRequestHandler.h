#pragma once
#include "IRequestHandler.h"


/**
 * @brief Handles Login and Sign-Up requests.
 *
 * This class is responsible for handling login and sign-up requests from clients.
 * It checks the relevance of the request and processes it accordingly, returning
 * a response through the provided RequestResult.
 * 
 * Notes - Inherit from IRequestHandler
 */
class LoginRequestHandler : public IRequestHandler {
public:
    /**
     * @brief Constructor for the LoginRequestHandler.
     */
    LoginRequestHandler();

    /**
     * @brief Check if the request is relevant for this handler.
     *
     * This method determines whether the given request data is relevant for this handler.
     *
     * @param requestData The request data to be checked.
     * @return True if the request is relevant, false otherwise.
     */
    bool isRequestRelevant(const RequestData& requestData) const override;

    /**
     * @brief Handle the incoming request.
     *
     * This method processes the incoming request based on its type and provides
     * a response through the RequestResult.
     *
     * @param reqHanData The request data to be handled.
     * @param reqRes The result of handling the request.
     */
    void handleRequest(RequestData& reqHanData, RequestResult& reqRes) override;

private:
    /**
     * @brief Handle a LoginRequest.
     *
     * This method processes a LoginRequest and returns the result through the provided
     * RequestResult.
     *
     * @param loginReq The LoginRequest to be handled.
     * @param reqRes The result of handling the request.
     * @param clientSock The client's socket for communication.
     */
    void loginRequest(const LoginRequest* loginReq, RequestResult& reqRes, SOCKET& clientSock) const;

    /**
     * @brief Handle a SignUpRequest.
     *
     * This method processes a SignUpRequest and returns the result through the provided
     * RequestResult.
     *
     * @param signUpReq The SignUpRequest to be handled.
     * @param reqRes The result of handling the request.
     */
    void signUpRequest(const SignUpRequest* signUpReq, RequestResult& reqRes) const;
};
