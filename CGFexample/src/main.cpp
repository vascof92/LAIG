


#include "CGFapplication.h"
#include "ChessScene.h"
#include "ChessInterface.h"
#include <iostream>
#include <exception>
using std::cin;
using std::cout;
using std::exception;

int main(int argc, char* argv[]) {

	CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);
		ChessScene* chess = new ChessScene();
		app.setScene(chess);
		app.setInterface(new ChessInterface(chess));
		
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Erro: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Erro inesperado: " << ex.what();
		return -1;
	}

	return 0;
}