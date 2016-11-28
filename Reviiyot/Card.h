#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
	Shape shape;
public:
	virtual string toString() = 0;
	virtual ~Card();
	virtual Card* copy() =0;
	Shape getShape() const;
	Card(Shape s);
	virtual int compareTo(Card& other, bool compareShape = false); // 0-equal, 1-the first is grater, -1 - the first is smaller
};

class FigureCard : public Card {
private:
	Figure figure;
public:
	FigureCard(Figure f, Shape s);
	virtual Card* copy() override;
	virtual int compareTo(Card & other, bool compareShape = false) override;
	virtual string toString() override;
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(int n,Shape s);
	virtual Card* copy() override;
	virtual int compareTo(Card & other, bool onlyType = false) override;
	virtual string toString() override;
};

#endif
