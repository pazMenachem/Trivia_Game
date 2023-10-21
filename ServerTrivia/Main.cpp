#include "Server.h"
#pragma comment(lib,"WS2_32")
// _DEV_ is defined in Utils.h

int main() {
	try {
		Server server;
		server.run();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		cout << WSAGetLastError();
		cerr << "NO Great Success" << endl;
		exit(1);
	}

    #ifdef _DEV_
	if (_CrtDumpMemoryLeaks())
		cout << "psst... you got some memory leaked" << endl;
    #endif

	cout << "Great Success!" << endl;
	return 0;
}