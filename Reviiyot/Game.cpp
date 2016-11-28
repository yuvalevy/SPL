#include "Game.h"



Game::Game(char* configurationFile)
{
	//TODO: cut the configurationFile to have string deck like this:
	string de = "KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD";
	deck = Deck(de);
	cout << deck.toString() << endl;
	cout << deck.getNumberOfCards() << endl;
	Player p1 = Player("Linoy",1);
	for (int i = 0; i < 8; i++)
	{
		Card* c = deck.fetchCard();
		p1.addCard(*c);
	}
	pair<int,Card&> resultMost = p1.getTheMostOf(); //A
	//pair<int, Card&> resultLeast = p1.getTheLeastOf(); //2 
}

void Game::init() {}
void Game::play() {}
void Game::printState() {}      //Print the state of the game as described in the assignment.
void Game::printWinner() {}       //Print the winner of the game as describe in the assignment.
void Game::printNumberOfTurns() {}