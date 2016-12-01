#include "Player.h"

Player::Player(string name, unsigned long pos):Hand(), pos(pos),name(name)
{
	cout << "player created" << endl;
}

Player::~Player()
{
	cout << "player deleted" << endl;
	//TODO check if entering hand
}

string Player::getName()
{
	return name;
}

string Player::toString()
{
	return name + ": " + Hand::toString();
}

PlayerType1::PlayerType1(string name, unsigned long pos):Player(name,pos)
{
	cout << "player 1 created" << endl;

}

PlayerType1::~PlayerType1()
{
	cout << "player 1 deleted" << endl;
}

pair<unsigned long, Card&> PlayerType1::ask(vector<unsigned long> state)
{
	// Descover who
	int who = 0;
	if (pos == 0)
	{
		who = 1;
	}

	for (size_t i = 0; i < state.size(); i++)
	{
		if (i != pos && state.at(i) >= state.at(who))
		{
			who = i;
		}
	}

	// Descover what
	pair<int, Card&> what = getTheMost();
	
	return pair<int, Card&>(who, what.second);
}

PlayerType2::PlayerType2(string name, unsigned long pos) :Player(name, pos)
{
	cout << "player 2 created" << endl;
}

PlayerType2::~PlayerType2()
{
	cout << "player 2 deleted" << endl;
}

pair<unsigned long, Card&> PlayerType2::ask(vector<unsigned long> state)
{
	// Descover who
	unsigned long who = 0;
	if (pos == 0)
	{
		who = 1;
	}

	for (size_t i = 0; i < state.size(); i++)
	{
		if (i != pos && state.at(i) >= state.at(who))
		{
			who = i;
		}
	}

	// Descover what
	pair<int, Card&> what = getTheLeast();

	return pair<unsigned long, Card&>(who, what.second);
}

PlayerType3::PlayerType3(string name, unsigned long pos) :Player(name, pos)
{
	cout << "player 3 created" << endl;

	nextAsk = 0;
}

PlayerType3::~PlayerType3()
{
	cout << "player 3 deleted" << endl;
}

pair<unsigned long, Card&> PlayerType3::ask(vector<unsigned long> state)
{
	// Descover who
	unsigned long who = nextAsk;
	if (pos == who)
	{
		who = (who + 1) % state.size();
		nextAsk = who;
	}
	nextAsk = (nextAsk + 1) % state.size();
	
	// Descover what
	Card& what = *getHighestCard();

	return pair<unsigned long, Card&>(who, what);
}

PlayerType4::PlayerType4(string name, unsigned long pos):Player(name,pos)
{
	cout << "player 4 created" << endl;

	nextAsk = 0;
}

PlayerType4::~PlayerType4()
{
	cout << "player 4 deleted" << endl;
}

pair<unsigned long, Card&> PlayerType4::ask(vector<unsigned long> state)
{
	// Descover who
	unsigned long who = nextAsk;
	if (pos == who)
	{
		who = (who + 1) % state.size();
		nextAsk = who;
	}
	nextAsk = (nextAsk + 1) % state.size();

	// Descover what
	Card& what = *getLowestCard();

	return pair<unsigned long, Card&>(who, what);
}