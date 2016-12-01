#include "Game.h"
#include <fstream>

Game::Game(char* configurationFile) :deck()
{
	conf = configurationFile;
}

Game::Game(const Game & other)
{
	conf = other.conf;
	deck = other.deck;

	for (size_t i = 0; i < other.players.size(); i++)
	{
		Player* get = other.players.at(i);
		Player* copied = get->copy();
		players.push_back(copied);
	}

	cardCount = new vector<unsigned long>();
	for (size_t i = 0; i < other.cardCount->size(); i++)
	{
		cardCount->push_back(other.cardCount->at(i));
	}

	turns = other.turns;
	verbalConfig = other.verbalConfig;
	highestNum = other.highestNum;
}

Game & Game::operator=(const Game & other)
{
	deck = other.deck;

	//delete current
	while (!players.empty())
	{
		Player* player = players.at(0);
		players.erase(players.begin());
		delete player;
	}

	for (size_t i = 0; i < other.players.size(); i++)
	{
		Player* get = other.players.at(0);
		players.push_back(get->copy());
	}

	cardCount->clear();

	for (size_t i = 0; i < other.cardCount->size(); i++)
	{
		cardCount->push_back(other.cardCount->at(i));
	}

	turns = other.turns;
	verbalConfig = other.verbalConfig;
	highestNum = other.highestNum;

	return *this;
}

Game & Game::operator=(Game && other)
{
	return *this;
}

Game::~Game()
{
	// delete players
	while (players.size() != 0)
	{
		Player* temp = players.at(0);
		players.erase(players.begin());
		delete temp;
	}

	// delete card count

		delete cardCount;
	
	//deck is on the stuck so after poping it the destructor will be called
	//delete deck;
}

void Game::init() {

	parseConfig();
	//card count for each player
	cardCount = new vector<unsigned long>();

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
	unsigned long currentPlayer = 0;
	bool isEnded = false;
	while (!isEnded)
	{
		turns++;
	
		Player* pa = players.at(currentPlayer); // asking player
	
		pair<unsigned long, Card&> askedInfo = pa->ask(*cardCount);
		Player* pg = players.at(askedInfo.first); // getting player

		if (verbalConfig == 1)
		{
			printTurn(turns);
			printAsk(pa->getName(), pg->getName(), askedInfo.second);
		}

		vector<Card*> givenCards = pg->search(askedInfo.second);
		
		// If the getting player doesn't has those cards
		if (givenCards.size() == 0)
		{
			Card* card = deck.fetchCard();
			if (card != nullptr)
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
					if (card != nullptr)
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
}

void Game::printTurn(unsigned long turn)
{
	cout << "" << endl;
	cout << "Turn " << turn << endl;
	printState();
}

void Game::printAsk(string p1, string p2, Card& card)
{
	string cs = card.toString();
	cs = cs.substr(0, cs.size() - 1);
	cout << p1 << " asked " << p2 << " for the value " << cs << endl;
}

void Game::printState() //Print the state of the game as described in the assignment.
{
	cout << "Deck: " << deck.toString() << endl;
	for (size_t i = 0; i < players.size(); i++)
	{
		cout << players.at(i)->toString() << endl;
	}
}

void Game::printWinner() {
	string s1 = "";
	string s2 = "";

	for (size_t i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getNumberOfCards() == 0)
		{
			if (s1.compare("") == 0)
			{
				s1 = players.at(i)->getName();
			}
			else {
				s2 = players.at(i)->getName();
				break;
			}
		}
	}

	if (s2.compare("") == 0) {
		cout << "***** The Winner is: " << s1 << " *****" << endl;
	}
	else {
		cout << "***** The winners are: " << s1 << " and " << s2 << " *****" << endl;
	}
}       //Print the winner of the game as describe in the assignment.

void Game::printNumberOfTurns() 
{
	cout << "Number of turns: " << turns << endl;
}

void Game::parseConfig()
{
	ifstream file;
	file.open(conf);
	string line;
	ConfigState state = VERBAL;
	unsigned long playersCount = 0;

	while (!file.eof())
	{
		getline(file, line);
		if (line == "") {
			continue;
		}
		if (line.at(0) == '#') {
			continue;
		}
		//TODO check if need to trim
		switch (state) {

			case VERBAL:
			{
				verbalConfig = stol(line);
				state = HIGHESTNUMVAL;
				break;
			}
			case HIGHESTNUMVAL:
			{
				highestNum = stol(line);
				state = DECK;
				break;
			}
			case DECK:
			{
				deck.createDeck(line);
				state = PLAYERS;
				break;
			}
			case PLAYERS:
			{
				char typePlayer = line.at(line.length() - 1);
				string name = line.substr(0, line.length() - 2);
				
				Player* p = createPlayer(typePlayer, name,playersCount);
				playersCount++;
				players.push_back(p);
				break;
			}
			default:
				break;

		}

	}
	
}

Player* Game::createPlayer(char type, string name, unsigned long pos)
{
	Player* player;

	switch (type)
	{
		case '1':
		{
			player = new PlayerType1(name, pos);
			break;
		}
		case '2':
		{
			player = new PlayerType2(name, pos);
			break;
		}
		case '3':
		{
			player = new PlayerType3(name, pos);
			break;
		}
		case '4':
		{
			player = new PlayerType4(name, pos);
			break;
		}
		default:
			break;		
	}

	return player;
}


