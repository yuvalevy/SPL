#include "Game.h"



Game::Game(char* configurationFile)
{
	//TODO parse config
	string deckLine = "KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD";
	int playersCount = 3;
	int highest = 3;
	
	//TODO: Change to PlayerType
	players.push_back(new Player("Alice", 1));
	players.push_back(new Player("Bob", 2));
	players.push_back(new Player("Charlie", 3));

	deck = Deck(deckLine);


	//cout << deck.toString() << endl;
	//cout << deck.getNumberOfCards() << endl;
	//Player p1 = Player("Linoy",1);
	//for (int i = 0; i < 10; i++)
	//{
	//	Card* c = deck.fetchCard();
	//	p1.addCard(*c);
	//}
	//pair<int,Card&> resultMost = p1.getTheMostOf(); //A
	//pair<int, Card&> resultLeast = p1.getTheLeastOf();//2
}

void Game::init() {

	// divide 7 cards for each player
	for (size_t i = 0; i < players.size(); i++)
	{
		for (int i = 1; i <= 7; i++)
		{
			players.at(i)->addCard(*(deck.fetchCard()));
		}

		players.at(i)->removeReviiyot();
	}

}

void Game::play()
{
	int currentPlayer = 1;
	bool isEnded = false;

	while (!isEnded)
	{
		Player* pa = players.at(currentPlayer); // asking player
	
		pair<int, Card&> stage1 = pa->ask();
		Player* pg = players.at(stage1.first); // getting player

		vector<Card*> givenCards = pg->search(stage1.second);
		
		// If the getting player doesn't has those cards
		if (givenCards.size() == 0)
		{
			pa->addCard(*deck.fetchCard());
		}
		else {
			// If player2 gives all his cards. he doesn't draw more cards
			bool toAdd = true;
			if (pg->getNumberOfCards() - givenCards.size() == 0)
			{
				toAdd = false;
			}

			// Remove from pg and add to pa
			for each (Card* card in givenCards)
			{
				pa->addCard(*card);
				pg->removeCard(*card);
				if (toAdd)
				{
					pg->addCard(*deck.fetchCard());
				}
			}
		}
	
		// Both playes removes all their Reviiyot
		pg->removeReviiyot();
		pa->removeReviiyot();

		//Check for winners
		//TODO: Ajust for printing
		if (pg->getNumberOfCards() == 0 )
		{
			isEnded = true;
		}
		if (pa->getNumberOfCards() == 0)
		{
			isEnded = true;
		}
	}

	//TODO: Destructor
}
void Game::printState() {}      //Print the state of the game as described in the assignment.
void Game::printWinner() {}       //Print the winner of the game as describe in the assignment.
void Game::printNumberOfTurns() {}