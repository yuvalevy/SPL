#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
protected:
	const int pos;
public:
	Player(string name, int pos);
	~Player();
	string getName();   //Returns the name of the player
	virtual pair<int, Card&> ask(vector<int> state) = 0; // Returning from how (int) and what (Card) he wants to ask from
	string toString();
};

class PlayerType1 : public Player {
public:
	PlayerType1(string name, int pos);
	~PlayerType1();
	virtual pair<int, Card&> ask(vector<int> state) override;
};

class PlayerType2 : public Player {
public:
	PlayerType2(string name, int pos);
	~PlayerType2();
	virtual pair<int, Card&> ask(vector<int> state) override;
};

class PlayerType3 : public Player {
private:
	int nextAsk;
public:
	PlayerType3(string name, int pos);
	~PlayerType3();
	virtual pair<int, Card&> ask(vector<int> state) override;
};

class PlayerType4 : public Player {
private:
	int nextAsk;
public:
	PlayerType4(string name, int pos);
	~PlayerType4();
	virtual pair<int, Card&> ask(vector<int> state) override;
};

#endif