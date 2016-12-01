#include "Player.h"

Player::Player(string name, unsigned long pos):Hand(),name(name),pos(pos)
{
}

Player::Player(const Player & other):Hand(other),name(other.name), pos(other.pos)
{
}

//Player & Player::operator=(const Player & other)
//{
//	Hand::Hand(other);
//	//TODO is it possible
//	return *this;
//}

Player::~Player()
{
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
}

PlayerType1::PlayerType1(const Player& other) : Player(other)
{
	cout << "player 1 created" << endl;
}

PlayerType1::~PlayerType1()
{
}

pair<unsigned long, Card&> PlayerType1::ask(vector<unsigned long> state)
{
	// Descover who
	int who = 0;
	if (pos == 0)
	{
		who = 1;
	}

	for (unsigned long i = 0; i < state.size(); i++)
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

Player * PlayerType1::copy()
{
	PlayerType1* p = new PlayerType1(*this);
	return p;
}

PlayerType2::PlayerType2(string name, unsigned long pos) :Player(name, pos)
{
}

PlayerType2::~PlayerType2()
{
}

PlayerType2::PlayerType2(const Player& other) : Player(other)
{
	cout << "player 2 created" << endl;
}


pair<unsigned long, Card&> PlayerType2::ask(vector<unsigned long> state)
{
	// Descover who
	unsigned long who = 0;
	if (pos == 0)
	{
		who = 1;
	}

	for (unsigned long i = 0; i < state.size(); i++)
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

Player * PlayerType2::copy()
{
	return new PlayerType2(*this);
}

PlayerType3::PlayerType3(string name, unsigned long pos) :Player(name, pos),nextAsk(0)
{
}

PlayerType3::~PlayerType3()
{
}

PlayerType3::PlayerType3(const Player& other) : Player(other),nextAsk(0)
{
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

Player * PlayerType3::copy()
{
	PlayerType3* p = new PlayerType3(*this);
	p->nextAsk = nextAsk;
	return p;
}

PlayerType4::PlayerType4(string name, unsigned long pos):Player(name,pos),nextAsk(0)
{
}

PlayerType4::~PlayerType4()
{
}

PlayerType4::PlayerType4(const Player& other) : Player(other),nextAsk(0)
{
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

Player* PlayerType4::copy()
{
	PlayerType4* p =new PlayerType4(*this);
	p->nextAsk = nextAsk;
	return p;
}
