#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Deck.h"

using namespace std;

enum ConfigState
{
	VERBAL,
	HIGHESTNUMVAL,
	DECK,
	PLAYERS
};

class Game {

private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	vector<int> *cardCount;		// Struct to count the player's card amounts.
	const char* conf;

	unsigned int verbalConfig;
	unsigned int highestNum;

public:
	Game(char* configurationFile);
	~Game();
	void init();
	void play();
	void printTurn(int turn);
	void printAsk(string p1, string p2, Card & card);
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
	void printNumberOfTurns(); //Print the number of played turns at any given time.  
	void parseConfig();
	Player * createPlayer(char type, string name, int pos);
};

#endif
