#include "Player.h"

Player::Player(string name, int pos):Hand(), pos(pos),name(name)
{
}

//vector<Card&> Player::bulkSearch(int pos, vector<Card*> handCards)
//{
//	vector<Card&> vec = vector<Card&>();
//	vec.push_back(*(handCards.at(pos)));
//	
//	Card* firstCard = handCards.at(pos);
//	pos++;
//	bool toStop = false;
//
//	while (!toStop)
//	{
//		if (handCards.at(pos)->compareTo(*firstCard) == 0)
//		{
//			vec.push_back(*(handCards.at(pos)));
//		}
//		else
//		{
//			toStop = true;
//		}
//		pos++;
//		if (pos == handCards.size())
//		{
//			toStop = true;
//		}
//	}
//
//	return vec;
//}

int Player::getPos()
{
	return pos;
}

string Player::getName()
{
	return name;
}