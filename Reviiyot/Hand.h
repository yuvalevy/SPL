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
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	vector<Card*> getCards();
	string toString();
	pair<int, Card&> getTheMostOf();
	pair<int, Card&> getTheLeastOf();
	void deleteValue(Card & card);
	pair<int, Card*> countValue(int pos);
	int countReviiyot();
	// Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
};

#endif
