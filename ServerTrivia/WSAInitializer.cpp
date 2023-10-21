#include "WSAInitializer.h"

WSAInitializer::WSAInitializer()
{
	WSADATA wsa_data = { };
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
      throw std::exception(__FUNCTION__ " - socket");
}

WSAInitializer::~WSAInitializer()
{
	try
	{
		WSACleanup();
	}
	catch (const std::exception& e) { std::cout << "WSA clean up error " << e.what() << std::endl;}
}
