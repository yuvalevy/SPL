#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const int pos;
	const string name;
public:
	Player(string name, int pos);
	int getPos();		//Returns the possition of the player
	string getName();   //Returns the name of the player
	//TODO: make abstruct
	 pair<int, Card&> ask(); // Returning from how (int) and what (Card) he wants to ask
};

class PlayerType1 : public Player {
};

class PlayerType2 : public Player { 
};

class PlayerType3 : public Player {  
};

class PlayerType4 : public Player { 
};

#endif