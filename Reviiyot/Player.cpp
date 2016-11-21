#include "Player.h"

Player::Player(string name, int pos):Hand(), pos(pos),name(name)
{
}

pair<int, Card&>  Player::getTheMostOf()
{
	vector<Card*> handCards = Hand::getCards();
	pair<int, Card&> max = countValue(0,handCards);
	int pos = max.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card&> ismax = countValue(pos, handCards);
	
		if (ismax.first > max.first)
		{
			max = ismax;
		}
		else if (ismax.first == max.first)
		{
			if(ismax.second.compareTo(max.second) == 1)
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

	return max;
}

vector<Card&> Player::bulkSearch(int pos, vector<Card*> handCards)
{
	vector<Card&> vec = vector<Card&>();
	vec.push_back(*(handCards.at(pos)));
	
	Card* firstCard = handCards.at(pos);
	pos++;
	bool toStop = false;

	while (!toStop)
	{
		if (handCards.at(pos)->compareTo(*firstCard) == 0)
		{
			vec.push_back(*(handCards.at(pos)));
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

	return vec;
}

pair<int, Card&> Player::getTheLeastOf()
{
	vector<Card*> handCards = Hand::getCards();
	pair<int, Card&> min = countValue(0, handCards);
	int pos = min.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card&> ismin = countValue(pos, handCards);

		if (ismin.first < min.first)
		{
			min = ismin;
		}
		else if (ismin.first == min.first)
		{
			if (ismin.second.compareTo(min.second) == -1)
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

	return min;
}

//
//Card * Player::getTheLeastOf()
//{
//	vector<Card*> handCards = Hand::getCards();
//	pair<int, Card*> min = countValue(0, handCards);
//	int pos = min.first;
//	bool end = false;
//	while (!end)
//	{
//		pair<int, Card*> ismin = countValue(pos, handCards);
//
//		if (ismin.first < min.first)
//		{
//			min = ismin;
//		}
//		else if (ismin.first == min.first)
//		{
//			if (ismin.second->compareTo(*(min.second)) == -1)
//			{
//				min = ismin;
//			}
//		}
//
//		pos = pos + ismin.first;
//		if (pos == handCards.size() - 1)
//		{
//			end = true;
//		}
//	}
//
//	return min.second;
//}
int Player::countReviiyot() {

	pair<int, Card&>  crds = getTheMostOf();
	int count = 0;

	while (crds.first==4)
	{
		count++;
		Hand::deleteValue(crds.second);
		crds = getTheMostOf();
	}

	return count;
}

/*
Counts the amount of cards of the current value (represented by pos parameter)
@param pos index at the vector
@param vector of cards
*/
pair<int, Card&> Player::countValue(int pos, vector<Card*> handCards)
{
	Card* firstCard = handCards.at(pos);
	int count = 1;
	pos++;
	bool toStop = false;

	while (!toStop)
	{
		if (handCards.at(pos)->compareTo(*firstCard) == 0 )
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

	return pair<int, Card&>(count,*firstCard);
}

int Player::getPos()
{
	return pos;
}

string Player::getName()
{
	return name;
}