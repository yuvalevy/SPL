#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Hand {
private:
	vector<Card*> *handCards;
	
public:
	Hand();
	virtual ~Hand();
	bool addCard(Card &card);
	bool removeCard(Card &card);
	Hand(const Hand& other);
	Hand& operator=(const Hand& other);
	vector<Card*> search(Card& card); // Search the cards with the same value of 'card' (returns them but doesn't removes them)
	int getNumberOfCards(); // Get the number of cards in hand
	Card * getLowestCard();
	string toString();
	pair<int, Card&> getTheMost();
	pair<int, Card&> getTheLeast();
	void deleteValue(Card & card);
	Card * getHighestCard();
	pair<int, Card*> countValue(size_t pos);
	bool removeReviiyot(); // returning true whe a Reviiya was deleted
};

#endif
