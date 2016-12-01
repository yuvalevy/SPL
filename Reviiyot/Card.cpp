#include <string>
#include <iostream>
#include "Card.h"

Card::~Card(){
	cout << "card deleted" << endl;
}

Shape Card::getShape() const
{
	return shape;
}

void Card::setShape(Shape shape)
{
	shape = shape;
}

Card::Card(Shape s):shape(s)
{
	cout << "card created" << endl;
}

int Card::compareTo(Card& other, bool compareShape)
{
	if (shape < other.shape)
	{
		return -1;
	}
	else if (shape > other.shape)
	{
		return 1;
	}
	return 0;
}

string Card::toString() {
	
	string ret;
	switch (shape) {
		case Shape::Club: ret =  "C"; break;
		case Shape::Diamond: ret =  "D"; break;
		case Shape::Heart: ret= "H"; break;
		case Shape::Spade: ret= "S"; break;
		default: ret =  "EE";
	}
	return ret;
}

FigureCard::~FigureCard() {
	cout << "figure card deleted" << endl;

}

FigureCard::FigureCard(Figure f, Shape s):Card(s), figure(f)
{
	cout << "figure card created" << endl;

}

FigureCard::FigureCard(const FigureCard & other):Card(other.getShape())
{
	figure = other.figure;
}

FigureCard & FigureCard::operator=(const FigureCard & other)
{
	if (this != &other) {
		figure = other.figure;
		setShape(other.getShape());
	}
	return *this;
}

Card* FigureCard::copy()
{
	return new FigureCard(figure, getShape());
}

/*
Compares two cards. if oncompareShape is true, compares the shapes too
*/
int FigureCard::compareTo(Card& other, bool compareShape)
{
	if (NumericCard* p = dynamic_cast<NumericCard*>(&other))
	{
		return 1;
	}
	else
	{
		FigureCard* fcother = dynamic_cast<FigureCard*>(&other);

		if (figure < fcother->figure)
		{
			return -1;
		}
		else if (figure > fcother->figure)
		{
			return 1;
		}
		else {

			if (compareShape)
			{
				return Card::compareTo(other);
			}

			return 0;
		}
	}
}

string FigureCard:: toString() {

	string ret;
	
	switch (figure) {
	case Figure::Ace:
		ret = "A"; break;
	case Figure::Jack:
		ret = "J"; break;
	case Figure::King:
		ret =  "K"; break;
	case Figure::Queen:
		ret = "Q"; break;
	}

	return  ret + "" + Card::toString();
}

NumericCard::~NumericCard()
{
	cout << "numeric card deleted" << endl;
}

NumericCard::NumericCard(int n,Shape s):Card(s), number(n)
{
	cout << "numeric card created" << endl;

}


NumericCard::NumericCard(const NumericCard & other):Card(other.getShape())
{
	number = other.number;
}

NumericCard & NumericCard::operator=(const NumericCard & other)
{
	if (this != &other) {
		number = other.number;
		setShape(other.getShape());
	}
	return *this;
}


/*
Copy constructor
*/
Card* NumericCard::copy()
{
	return new NumericCard(number, getShape());
}

/*
Compares two cards. if oncompareShape is true, compares the shapes too
*/
int NumericCard::compareTo(Card& other, bool compareShape)
{
	if (FigureCard* p = dynamic_cast<FigureCard*>(&other))
	{
		return -1;
	}
	else
	{
		NumericCard* ncother = dynamic_cast<NumericCard*>(&other);
		if (number < ncother->number)
		{
			return -1;
		}
		else if (number > ncother->number)
		{
			return 1;
		}
		else
		{
			if (compareShape)
			{
				return Card::compareTo(other);
			}
			return 0;
		}
	}
}

string NumericCard ::toString() {
	
	return std::to_string(number)  + "" + Card::toString();
}

