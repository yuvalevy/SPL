#include "Deck.h"
#include <string>
using namespace std;

Deck::Deck():cards(new stack<Card*>())
{
}

Deck::Deck(const Deck & other):cards(new stack<Card*>())
{
	stack<Card*> temp = *other.cards;
	stack<Card*> reverse = stack<Card*>();

	//perform deep copy
	while (!temp.empty())
	{
		Card* copied = temp.top();
		temp.pop();
		reverse.push(copied->copy());
	}

	while (!reverse.empty())
	{
		Card* copied = reverse.top();
		reverse.pop();
		cards->push(copied);
	}
}

Deck & Deck::operator=(const Deck & other)
{
	if (this != &other)
	{
		// Delete current cards
		while (!cards->empty())
		{
			Card* card = cards->top();
			cards->pop();
			delete card;
		}

		stack<Card*> temp = *other.cards;
		stack<Card*> reverse = stack<Card*>();

		//perform deep copy
		while (!temp.empty())
		{
			Card* copied = temp.top();
			temp.pop();
			reverse.push(copied->copy());
		}

		while (!reverse.empty())
		{
			Card* copied = reverse.top();
			reverse.pop();
			cards->push(copied);
		}
	}

	return *this;
}

void Deck::createDeck(string deckLine)
{
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
	return nullptr;
}

/*
Returns the number of cards in the deck
*/
int Deck::getNumberOfCards() {
	return static_cast<int>(cards->size());
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
	catch (const exception&)
	{
		//value is not a number, it is a single char as a figure
		switch (value.at(0))
		{
			case 'A': cards->push(new FigureCard(Figure::Ace, shape)); break;
			case 'J': cards->push(new FigureCard(Figure::Jack, shape)); break;
			case 'K': cards->push(new FigureCard(Figure::King, shape)); break;
			case 'Q': cards->push(new FigureCard(Figure::Queen, shape)); break;
			default: break;
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