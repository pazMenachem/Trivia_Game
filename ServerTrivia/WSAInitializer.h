#pragma once

#include <winsock2.h>
#include <Windows.h>
#include <exception>
#include <iostream>

// This class provides a convenient way to initialize and cleanup the Windows Sockets API (WSA).
class WSAInitializer
{
public:
	// Initializes the WSA by calling WSAStartup() with version 2.2.
	// If the initialization fails, throws a std::exception with the name of the function that failed.
	WSAInitializer();
	//Cleans up the WSA by calling WSACleanup().
   // Does not throw any exceptions.
	~WSAInitializer();
};

