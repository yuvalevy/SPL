#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	Game g = Game(argv[1]);

/*
	 char s[10];
	 std::cin >> s;
	 */
	/* 
	char* configurationFile = argv[1];
	
	Game game = Game(configurationFile);
	game.init();
	Game initializedGame = game;
	game.play();

	cout << std::endl;
	game.printWinner();
	game.printNumberOfTurns();
	cout << "----------" << endl;
	cout << "Initial State:" << endl;
	initializedGame.printState();
	cout << "----------" << endl;
	cout << "Final State:" << endl;
	game.printState();*/
	return 0;
}

