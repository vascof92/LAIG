


#include "CGFapplication.h"
#include "Scene.h"
#include "Interface.h"
#include <iostream>
#include <exception>
using std::cin;
using std::cout;
using std::exception;

int main(int argc, char* argv[]) {
	CGFapplication app = CGFapplication();

	try
	{
		app.init(&argc, argv);
		
		try {
			app.setScene(new Scene());
			app.setInterface(new Interface());
			app.run();
		}
		catch (GLexception& ex) {
			throw "Error: " + *ex.what();
		}
		catch (exception& ex) {
			throw "Unexpected error: " + *ex.what();
		}
	}
	catch (const char* msg) { //parse exception
		cout << "EXCEPTION: " << msg;
		exit(1);
	}

	return 0;
}