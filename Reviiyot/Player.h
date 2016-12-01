#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
protected:
	const unsigned long pos;
public:
	Player(string name, unsigned long pos);
	Player(const Player& other);
	Player& operator=(const Player& other);
	virtual Player* copy() = 0;
	~Player();
	string getName();   //Returns the name of the player
	virtual pair<unsigned long, Card&> ask(vector<unsigned long> state) = 0; // Returning from how (int) and what (Card) he wants to ask from
	string toString();
};

class PlayerType1 : public Player {
public:
	PlayerType1(string name, unsigned long pos);
	PlayerType1(const Player & other);
	~PlayerType1();
	virtual pair<unsigned long, Card&> ask(vector<unsigned long> state) override;
	virtual Player* copy() override;
};

class PlayerType2 : public Player {
public:
	PlayerType2(string name, unsigned long pos);
	~PlayerType2();
	PlayerType2(const Player & other);
	virtual pair<unsigned long, Card&> ask(vector<unsigned long> state) override;
	virtual Player* copy() override;
};

class PlayerType3 : public Player {
private:
	unsigned long nextAsk;
public:
	PlayerType3(string name, unsigned long pos);
	~PlayerType3();
	PlayerType3(const Player & other);
	virtual pair<unsigned long, Card&> ask(vector<unsigned long> state) override;
	virtual Player* copy() override;
};

class PlayerType4 : public Player {
private:
	unsigned long nextAsk;
public:
	PlayerType4(string name, unsigned long pos);
	~PlayerType4();
	PlayerType4(const Player & other);
	virtual pair<unsigned long, Card&> ask(vector<unsigned long> state) override;
	virtual Player* copy() override;
};

#endif