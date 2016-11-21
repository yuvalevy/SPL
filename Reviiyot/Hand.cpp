#include "Hand.h"
//The hand is sorted
Hand::Hand()
{
	handCards = new vector<Card*>();
}

bool Hand::addCard(Card &card) {
	
	bool finished = false;
	int i = 0;
	while (i != handCards->size() && !finished) {

		if (card.compareTo( *(handCards->at(i))) == -1) {
			handCards->insert(handCards->begin() + i, &card);
			finished = true;
		}
		i++;
	}
	
	if (!finished)
	{
		handCards->push_back(&card);
		finished = true;
	}
	return finished;
}

bool Hand::removeCard(Card &card) {
	bool finished = false;
	int i = 0;
	while (i != handCards->size() && !finished) {

		if (card.compareTo(*(handCards->at(i))) == 0) {
			handCards->erase(handCards->begin() + i);
			finished = true;
		}
		i++;
	}
	return finished;
}

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
