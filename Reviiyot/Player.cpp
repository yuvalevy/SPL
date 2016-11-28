#include "Player.h"

Player::Player(string name, int pos):Hand(), pos(pos),name(name)
{
}

//int Player::getPos()
//{
//	return pos;
//}

string Player::getName()
{
	return name;
}

PlayerType1::PlayerType1(string name, int pos):Player(name,pos)
{
}

pair<int, Card&> PlayerType1::ask(vector<int> state)
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

PlayerType2::PlayerType2(string name, int pos) :Player(name, pos)
{
}

pair<int, Card&> PlayerType2::ask(vector<int> state)
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
	pair<int, Card&> what = getTheLeast();

	return pair<int, Card&>(who, what.second);
}

PlayerType3::PlayerType3(string name, int pos) :Player(name, pos)
{
	nextAsk = 0;
}

pair<int, Card&> PlayerType3::ask(vector<int> state)
{
	// Descover who
	int who = nextAsk;
	if (pos == who)
	{
		who = (who + 1) % state.size();
		nextAsk = who;
	}
	nextAsk = (nextAsk + 1) % state.size();
	
	// Descover what
	Card& what = *getHighestCard();

	return pair<int, Card&>(who, what);
}

PlayerType4::PlayerType4(string name, int pos):Player(name,pos)
{
	nextAsk = 0;
}

pair<int, Card&> PlayerType4::ask(vector<int> state)
{
	// Descover who
	int who = nextAsk;
	if (pos == who)
	{
		who = (who + 1) % state.size();
		nextAsk = who;
	}
	nextAsk = (nextAsk + 1) % state.size();

	// Descover what
	Card& what = *getLowestCard();

	return pair<int, Card&>(who, what);
}