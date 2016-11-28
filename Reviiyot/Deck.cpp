#include "Deck.h"
#include <string>
using namespace std;

Deck::Deck()
{
	cout << "deck(D) created" << endl;
}

Deck::Deck(string deckLine):cards(new stack<Card*>())
{
	cout << "deck created" << endl;

	string s = deckLine;
	string delimiter = " ";

	size_t pos = s.length()-1;
	string token;

	while ((pos = s.find_last_of(delimiter)) != string::npos) {

		token = s.substr(pos+1, s.length()-1);
		addToStack(token);
		s.erase(pos, s.length()-1);
	}

	addToStack(s);
}

Deck::~Deck() {

	cout << "deck deleted" << endl;

	while (cards->size() != 0)
	{
		Card* temp = cards->top();
		cards->pop();
		delete temp;
	}

	delete cards;
}

/*
Deletes and returns the top card from the deck
*/
Card* Deck::fetchCard() {
	if (cards->size() != 0) {
		Card* card = cards->top();
		cards->pop();
		return card;
	}
	return 0;
}

/*
Returns the number of cards in the deck
*/
int Deck::getNumberOfCards() {
	return cards->size();
}

/*
Adds a card to the deck according to the token value
*/
void Deck::addToStack(string token)
{
	char cshape = token.at(token.length() - 1);
	string value = token.erase(token.length() - 1);
	Shape shape;

	switch (cshape)
	{
		case 'D': shape = Shape::Diamond; break;
		case 'H': shape = Shape::Heart; break;
		case 'C': shape = Shape::Club; break;
		case 'S': shape = Shape::Spade; break;
	}

	try
	{
		//tryparse to int
		int num = stoi(value);
		cards->push(new NumericCard(num, shape));
	}
	catch (const invalid_argument)
	{
		//value is not a number, it is a single char as a figure
		switch (value.at(0))
		{
			case 'A': cards->push(new FigureCard(Figure::Ace, shape)); break;
			case 'J': cards->push(new FigureCard(Figure::Jack, shape)); break;
			case 'K': cards->push(new FigureCard(Figure::King, shape)); break;
			case 'Q': cards->push(new FigureCard(Figure::Queen, shape)); break;
		}
	}

}

string Deck::toString() {
	string ret = "";
	stack<Card*> temp = stack<Card*>();
	while (!(cards->empty()))
	{
		Card* top = cards->top();
		cards->pop();
		ret+= top->toString() + " ";
		temp.push(top);
	}
	while (!(temp.empty()))
	{
		Card* top = temp.top();
		temp.pop();
		cards->push(top);
	}
	return ret;
}