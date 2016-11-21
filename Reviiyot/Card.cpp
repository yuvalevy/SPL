#include <string>
#include <iostream>
#include "Card.h"

Card::~Card(){

}

Card::Card(Shape s):shape(s)
{
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

FigureCard::FigureCard(Figure f, Shape s):Card(s), figure(f)
{
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

NumericCard::NumericCard(int n,Shape s):Card(s), number(n)
{
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

