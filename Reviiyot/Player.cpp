#include "Player.h"

Player::Player(string name, int pos):Hand(), pos(pos),name(name)
{
}


int Player::getPos()
{
	return pos;
}

string Player::getName()
{
	return name;
}

pair<int, Card&> Player::ask()
{
	return pair<int, Card&>(5,NumericCard(3,Shape::Club));
}
