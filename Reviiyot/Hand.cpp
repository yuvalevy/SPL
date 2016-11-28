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
Deleting all cardss in hand that has 'card' value
*/
void Hand::deleteValue(Card& card) {
	int i = 0;
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