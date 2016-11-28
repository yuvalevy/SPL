#include "Game.h"



Game::Game(char* configurationFile)
{
	//TODO parse config
	string deckLine = "KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD";
	int playersCount = 3;
	int highest = 3;

	//TODO: Change to PlayerType
	players.push_back(new PlayerType1("Alice", 0));
	players.push_back(new PlayerType2("Bob", 1));
	players.push_back(new PlayerType3("Charlie", 2));

	deck = Deck(deckLine);

	//cout << deck.toString() << endl;
	//cout << deck.getNumberOfCards() << endl;
	/*Player p1 = Player("Linoy",1);
	for (int i = 0; i < 10; i++)
	{
		Card* c = deck.fetchCard();
		p1.addCard(*c);
	}
	NumericCard card = NumericCard(3, Shape::Heart);
	vector<Card*> vec = p1.search(card);
*/
}

void Game::init() {

	cardCount = new vector<int>();

	// divide 7 cards for each player
	for (size_t i = 0; i < players.size(); i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			players.at(i)->addCard(*(deck.fetchCard()));
		}

		players.at(i)->removeReviiyot();
		cardCount->push_back(7);
	}
}

void Game::play()
{
	int currentPlayer = 0;
	bool isEnded = false;
	int turns = 0;
	while (!isEnded)
	{
		turns++;
		Player* pa = players.at(currentPlayer); // asking player
	
		pair<int, Card&> askedInfo = pa->ask(*cardCount);
		Player* pg = players.at(askedInfo.first); // getting player

		vector<Card*> givenCards = pg->search(askedInfo.second);
		
		// If the getting player doesn't has those cards
		if (givenCards.size() == 0)
		{
			Card* card = deck.fetchCard();
			if (card != 0)
				pa->addCard(*card);
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
					Card* card = deck.fetchCard();
					if (card != 0)
						pg->addCard(*card);
				}
			}
		}
	
		// Both playes removes all their Reviiyot
		pg->removeReviiyot();
		pa->removeReviiyot();

		cardCount->at(currentPlayer) = pa->getNumberOfCards();
		cardCount->at(askedInfo.first) = pg->getNumberOfCards();

		//Check for winners
		//TODO: Ajust for printing
		if (pg->getNumberOfCards() == 0)
		{
			isEnded = true;
		}
		if (pa->getNumberOfCards() == 0)
		{
			isEnded = true;
		}
		
		currentPlayer = (currentPlayer +1 ) % (players.size());
	}

	//TODO: Destructor
}

void Game::printState() {}      //Print the state of the game as described in the assignment.
void Game::printWinner() {}       //Print the winner of the game as describe in the assignment.
void Game::printNumberOfTurns() {}