#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	vector<int> *cardCount;		// Struct to count the player's card amounts.
	
public:
	Game(char* configurationFile);
	~Game();
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
	void printNumberOfTurns(); //Print the number of played turns at any given time.  
};

#endif
