#include "Deck.h"
#include <string>
using namespace std;

Deck::Deck()
{
}

Deck::Deck(string deckLine)
{	
	cards = new stack<Card*>();

	string s = deckLine;
	string delimiter = " ";

	size_t pos = s.length()-1;
	std::string token;

	while ((pos = s.find_last_of(delimiter)) != string::npos) {

		token = s.substr(pos+1, s.length()-1);
		addToStack(token);
		s.erase(pos, s.length()-1);
	}

	addToStack(s);
}

Card* Deck::fetchCard() {
	Card* card = cards->top();
	cards->pop();
	return card;
}

int Deck::getNumberOfCards() {
	return cards->size();
}

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
		int num = stoi(value);
		cards->push(new NumericCard(num, shape));
	}
	catch (const invalid_argument)
	{
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