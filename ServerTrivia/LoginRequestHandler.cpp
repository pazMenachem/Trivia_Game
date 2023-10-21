#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"


LoginRequestHandler::LoginRequestHandler() : IRequestHandler(HANDLER_LOGIN){}

bool LoginRequestHandler::isRequestRelevant(const RequestData& request) const
{
	if(request._code == CODE_LOGIN || request._code == CODE_SIGNUP)
		return true;
	return false;
}

void LoginRequestHandler::handleRequest(RequestData& reqData, RequestResult& reqRes)
{	
	if (reqData._code == CODE_LOGIN)
		loginRequest(dynamic_cast<LoginRequest*>(reqData._request),
												 reqRes,
												 reqData._clientSock);
	
	if (reqData._code == CODE_SIGNUP)
		signUpRequest(dynamic_cast<SignUpRequest*>(reqData._request),
												   reqRes);
}

void LoginRequestHandler::loginRequest(const LoginRequest* loginReq, RequestResult& reqRes, SOCKET& clientSock) const
{
	int res = _requestHandlerFactory.getLoginManager().logIn(loginReq->_userName, 
															loginReq->_password,
															clientSock);

	Json data;
	if (res == ERROR_WRONG_PASSWORD)
		data = {
				{CODE, ERROR_WRONG_PASSWORD},
				{MESSAGE, "Wrong password"},
	};
	if (res == ERROR_USER_DOESNT_EXSITS)
		data = {
				{CODE, ERROR_USER_DOESNT_EXSITS},
				{MESSAGE, "User doesn't exists"},
	};
	if (res == ERROR_USER_ALREADY_LOGGED_IN)
		data = {
				{CODE, ERROR_USER_ALREADY_LOGGED_IN},
				{MESSAGE, "User already logged in"}
	};
	if (res == SUCCESS_LOGIN)
	{
		data = {
			{CODE, CODE_SUCCESS}
		};
		reqRes._newHandler = _requestHandlerFactory.createMenuRequestHandler(loginReq->_userName);
	}

	setRequestResult(reqRes, data);
}

void LoginRequestHandler::signUpRequest(const SignUpRequest* signUpReq, RequestResult& reqRes) const
{
	int res = _requestHandlerFactory.getLoginManager().signUp(signUpReq->_userName, 
															 signUpReq->_password, 
															 signUpReq->_email);
	Json data;
	if (res == ERROR_USER_ALREADY_EXISTS)
		data = {
				{CODE, ERROR_USER_ALREADY_EXISTS},
				{MESSAGE, "User already exists"}
		};

	if (res == SUCCESS_SIGNUP)
		data = {
			{CODE, CODE_SUCCESS}
		};
	

	setRequestResult(reqRes, data);
}
