#include "Hand.h"
//The hand is sorted
Hand::Hand():handCards(new vector<Card*>())
{
}

/*
Adding the new card to the hand, in sorted order
*/
bool Hand::addCard(Card &card) {
	
	bool finished = false;
	int i = 0;
	while (i != handCards->size() && !finished) {

		//if -> the new card is smaller than the next card, add it previusly
		if (card.compareTo( *(handCards->at(i)) , true) == -1) {
			handCards->insert(handCards->begin() + i, &card);
			finished = true;
		}
		i++;
	}

	if (!finished)
	{
		// Adding the card to the end of the hand
		handCards->push_back(&card);
		finished = true;
	}
	return finished;
}

/*
Removing the given card from the hand
*/
bool Hand::removeCard(Card &card) {
	bool finished = false;
	int i = 0;

	while (i != handCards->size() && !finished) {
		//TODO add this -> pointer 
		/*if (handCards->at(i) == &card)
		{
			handCards->erase(handCards->begin() + i);
			finished = true;
		}*/
		if (card.compareTo(*(handCards->at(i))) == 0) {
			handCards->erase(handCards->begin() + i);
			finished = true;
		}
		i++;
	}
	return finished;
}

/*
Returns the number of cards in the hand
*/
int Hand::getNumberOfCards() {
	return handCards->size();
}

vector<Card*> Hand::getCards()
{
	//TODO Copy constructor
	return *handCards;
}

string Hand::toString() {
	string ret = "";
	for (int i = 0; i < handCards->size(); i++) {
		ret += handCards->at(i)->toString()+" ";
	}
	return ret;
}

/*
Counts the amount of cards of the current value (represented by pos parameter)
@param pos index at the vector
*/
pair<int, Card*> Hand::countValue(int pos)
{
	Card* firstCard = handCards->at(pos);
	int count = 1;
	pos++;
	bool toStop = false;

	while (!toStop && pos < handCards->size())
	{
		if (handCards->at(pos)->compareTo(*firstCard) == 0)
		{
			count++;
		}
		else
		{
			toStop = true;
		}
		pos++;
	}

	return pair<int, Card*>(count, firstCard);
}

pair<int, Card&>  Hand::getTheMostOf()
{
	pair<int, Card*> max = countValue(0);

	int pos = max.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card*> ismax = countValue(pos);

		if (ismax.first > max.first)
		{
			max = ismax;
		}
		else if (ismax.first == max.first)
		{
			if (ismax.second->compareTo(*(max.second)) == 1)
			{
				max = ismax;
			}
		}

		pos = pos + ismax.first;
		if (pos == handCards->size())
		{
			end = true;
		}
	}

	return pair<int,Card&>(max.first, *(max.second));
}


pair<int, Card&>  Hand::getTheLeastOf()
{
	pair<int, Card*> min = countValue(0);

	int pos = min.first;
	bool end = false;
	while (!end)
	{
		pair<int, Card*> ismin = countValue(pos);

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
		if (pos == handCards->size())
		{
			end = true;
		}
	}

	return pair<int, Card&>(min.first, *(min.second));
}

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
int Hand::countReviiyot() {

	pair<int, Card&>  crds = getTheMostOf();
	int count = 0;

	while (crds.first == 4)
	{
		count++;
		deleteValue(crds.second);
		crds = getTheMostOf();
	}

	return count;
}

void Hand::deleteValue(Card& card) {

	int i = 0;
	int compare = handCards->at(i)->compareTo(card);
	while (compare <= 0)
	{
		if (compare == -1)
		{
			i++;
		}
		else {
			Card* temp = handCards->at(i);
			handCards->erase(handCards->begin() + i);
			delete temp;
		}

		if (i == handCards->size()) {
			compare = 1;
		}
		else {
			compare = handCards->at(i)->compareTo(card);
		}
	}
}