#include "Player.h"

Player::Player(string name, int pos):pos(pos),name(name)
{
	Hand::Hand();
}

Card* Player::getTheMostOf()
{
	vector<Card*> handCards = Hand::getCards();
	pair<int, Card*> max = countNext(0,handCards);
	int pos = max.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card*> ismax = countNext(pos, handCards);
	
		if (ismax.first > max.first)
		{
			max = ismax;
		}
		else if (ismax.first == max.first)
		{
			if(ismax.second->compareTo(*(max.second)) == 1)
			{
				max = ismax;
			}
		}

		pos = pos + ismax.first;
		if (pos == handCards.size()-1)
		{
			end = true;
		}
	}

	return max.second;
}

Card * Player::getTheLeastOf()
{
	vector<Card*> handCards = Hand::getCards();
	pair<int, Card*> min = countNext(0, handCards);
	int pos = min.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card*> ismin = countNext(pos, handCards);

		if (ismin.first < min.first)
		{
			min = ismin;
		}
		else if (ismin.first == min.first)
		{
			if (ismin.second->compareTo(*(min.second)) == -1)
			{
				min = ismin;
			}
		}

		pos = pos + ismin.first;
		if (pos == handCards.size() - 1)
		{
			end = true;
		}
	}

	return min.second;
}

pair<int, Card*> Player::countNext(int pos, vector<Card*> handCards)
{
	Card* firstCard = handCards.at(pos);
	int count = 1;
	pos++;
	bool toStop = false;

	while (!toStop)
	{
		if (handCards.at(pos)->compareTo(*firstCard,true) == 0 )
		{
			count++;
		}
		else
		{
			toStop = true;
		}
		pos++;
		if (pos == handCards.size())
		{
			toStop = true;
		}
	}

	return pair<int, Card*>(count,firstCard);
}

int Player::getPos()
{
	return pos;
}

string Player::getName()
{
	return name;
}