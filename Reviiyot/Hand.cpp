#include "Hand.h"

//The hand is sorted
Hand::Hand():handCards(new vector<Card*>())
{
}

Hand::~Hand()
{
	while (handCards->size() != 0 )
	{
		Card* temp = handCards->at(0);
		handCards-> erase(handCards->begin());
		delete temp;
	}

	delete handCards;
}

/*
Adding the new card to the hand, in sorted order
*/
bool Hand::addCard(Card &card) {
	
	bool finished = false;
	size_t i = 0;
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
	size_t i = 0;

	while (i != handCards->size() && !finished) {
		if (card.compareTo(*(handCards->at(i))) == 0) {
			handCards->erase(handCards->begin() + i);
			finished = true;
		}
		i++;
	}
	return finished;
}

Hand::Hand(const Hand & other):handCards(new vector<Card*>())
{
	for (size_t i = 0; i < other.handCards->size(); i++)
	{
		Card* copied = other.handCards->at(i);
		handCards->push_back(copied->copy());
	}
}

Hand & Hand::operator=(const Hand & other)
{
	while (handCards->size()!=0)
	{
		Card* card = handCards->at(0);
		handCards->erase(handCards->begin());
		delete card;
	}
	
	for (size_t i = 0; i < other.handCards->size(); i++)
	{
		Card* copied = other.handCards->at(i);
		handCards->push_back(copied->copy());
	}

	return *this;
}

/*
Search all cards by the value of 'card'
*/
vector<Card*> Hand::search(Card & card)
{
	vector<Card*> vec = vector<Card*>();
	bool toStop = false;
	size_t i = 0;

	while (!toStop && i < handCards->size())
	{
		Card* cur = handCards->at(i);
		if (cur->compareTo(card) == 0)
		{
			vec.push_back(cur);
		}
		else if(cur->compareTo(card) == 1)
		{
			toStop = true;
		}
		i++;
	}
	
	return vec;
}

/*
Returns the number of cards in the hand
*/
int Hand::getNumberOfCards() {
	return static_cast<int>(handCards->size());
}

/*
Counts the amount of cards of the current value (represented by pos parameter)
@param pos index at the vector
*/
pair<int, Card*> Hand::countValue(size_t pos)
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

pair<int, Card&> Hand::getTheMost()
{
	pair<int, Card*> max = countValue(0);

	size_t pos = max.first;
	
	while (pos != handCards->size())
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
	}

	return pair<int,Card&>(max.first, *max.second);
}

pair<int, Card&> Hand::getTheLeast()
{
	pair<int, Card*> min = countValue(0);

	size_t pos = min.first;
	while (pos != handCards->size())
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
	
	}

	return pair<int, Card&>(min.first, *min.second);
}

bool Hand::removeReviiyot() {

	// no cards to remove
	if (handCards->size() == 0)
	{
		return false;
	}

	pair<int, Card&>  crds = getTheMost();

	if(crds.first == 4)
	{
		Card* copied = crds.second.copy();
		deleteValue(*copied);
		delete copied;
		return true;
	}
	return false;
}

/*
Deleting all cardss in hand that has 'card' value
*/
void Hand::deleteValue(Card& card) {
	
	size_t i = 0;
	int compare = handCards->at(i)->compareTo(card);
	while (compare <= 0) // the hand is sorded by value and therefor at the moment we reeached the last card with the given value, we can stop looking
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

Card* Hand::getHighestCard()
{
	return handCards->at(handCards->size() - 1);
}

Card* Hand::getLowestCard()
{
	return handCards->at(0);
}

string Hand::toString() {
	string ret = "";
	for (size_t i = 0; i < handCards->size(); i++) {
		ret += handCards->at(i)->toString() + " ";
	}
	return ret;
}
