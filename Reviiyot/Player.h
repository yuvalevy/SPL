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
	pair<int, Card&> getTheMostOf();
	//vector<Card*> bulkSearch(int pos, vector<Card*> handCards);
	//pair<int, Card&> getTheLeastOf();
	int countReviiyot();
	pair<int, Card&> countValue(int pos, vector<Card*> handCards);
	int getPos(); //Returns the possition of the player
	string getName();   //Returns the name of the player
};

class PlayerType1 : public Player {
};

class PlayerType2 : public Player {  //For strategy 2
									 //...
};

class PlayerType3 : public Player {  //For strategy 3
									 //...
};

class PlayerType4 : public Player {  //For strategy 4
									 //...
};

#endif
