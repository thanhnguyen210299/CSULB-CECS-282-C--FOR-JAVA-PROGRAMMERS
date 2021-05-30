// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 6 - Inheritance (Mega War)
// December 07, 2020

#include "MegaDeck.h"
#include "Player.h"
#include <Windows.h>

using namespace std;

int main()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

	// Enter number of players and number of decks
	int nPlayers, nDecks;
	cout << "Enter number of players: ";
	cin >> nPlayers;
	cout << "Enter number of decks: ";
	cin >> nDecks;

	// Generate Mega Deck and Players
	MegaDeck t(nDecks);
	t.displayDecks();
	cout << endl;

	// Generate players
	Player* players = new Player[nPlayers];

	// Dividing cards to players
	int index = nPlayers - 1;
	while (t.cardsLeft() > 0)
	{
		players[index].addCard(t.deal());
		index--;
		if (index == -1)
			index = nPlayers - 1;
	}

	// Display cards on players's hands
	for (int i = 0; i < nPlayers; i++)
	{
		cout << "Player " << i + 1 << ": ";
		players[i].displayCards();
		cout << endl;
	}

	// Starting War
	int count, max, value, count_Battles = 0, countRounds = 0;
	CardPile cards_deal;
	WarPile warPile;
	LostAndFound lf;
	bool isStop = false, isPossible;
	vector<int> players_index, positions;
	Card temp;

	while (!isStop)
	{
		countRounds++;
		SetConsoleTextAttribute(hConsoleColor, 12); //RED
		cout << "************************************ Round " << countRounds << " ************************************" << endl;
		SetConsoleTextAttribute(hConsoleColor, 15); //WHITE

		// Every player puts down 1 card
		positions.clear();
		for (int i = 0; i < nPlayers; i++)
			if (!players[i].isEmpty())
			{
				cards_deal.addCard(players[i].removeCard());
				positions.push_back(i);
			}
		SetConsoleTextAttribute(hConsoleColor, 11); //LIGHT BLUE
		cout << "Cards in Pile: ";
		SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
		cards_deal.displayCards();
		cout << endl;
		// Find the highest Card and count number of players have the highest card
		max = 0;
		index = 0;
		count = 1;
		for (int i = 0; i < cards_deal.cardsLeft(); i++)
		{
			value = cards_deal.getCard(i).getValue();
			if (value > max)
			{
				max = value;
				count = 1;
				index = positions[i];
			}
			else
				if (value == max)
					count++;
		}
		// Check if just one player has the highest card
		if (count == 1)
		{
			SetConsoleTextAttribute(hConsoleColor, 12); //DARK BLUE
			cout << "Player " << index + 1 << " win!!!" << endl;
			SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
			while (!cards_deal.isEmpty())
				players[index].addCard(cards_deal.removeCard());
		}
		// If there 2 or more players have the highest card => WAR
		else
		{
			// Find those players
			/*for (int i = 0; i < cards_deal.cardsLeft(); i++)
				if (cards_deal.getCard(i).getValue() == max)
					players[positions[i]].increasePlayedBattles();*/
			do
			{
				// Find those players
				players_index.clear();
				for (int i = 0; i < cards_deal.cardsLeft(); i++)
					if (cards_deal.getCard(i).getValue() == max)
					{
						players_index.push_back(positions[i]);
						players[positions[i]].increasePlayedBattles();
					}
				// Check if all players don't have enough card
				isPossible = false;
				for (int i = 0; i < players_index.size(); i++)
					if (players[players_index[i]].cardsLeft() >= 3)
					{
						isPossible = true;
						break;
					}
				// If all players can't join the war => Cards go into LostAndFound
				if (!isPossible)
				{
					// Cards in cards_deal => LostAndFound
					while (!cards_deal.isEmpty())
						lf.addCard(cards_deal.removeCard());
					// All players's cards => LostAndFound
					for (int i = 0; i < players_index.size(); i++)
						while (!players[players_index[i]].isEmpty())
							lf.addCard(players[players_index[i]].removeCard());
				}
				else
				{
					// Cards in cards_deal => WarPile
					while (!cards_deal.isEmpty())
						warPile.addCard(cards_deal.removeCard());
					// Get 3 more cards from each player
					max = 0;
					count = 0;
					for (int i = 0; i < players_index.size(); i++)
						// If player doesn't have enough card => lose
						if (players[players_index[i]].cardsLeft() < 3)
						{
							while (!players[players_index[i]].isEmpty())
								warPile.addCard(players[players_index[i]].removeCard());
						}
						else
						{
							warPile.addCard(players[players_index[i]].removeCard());
							warPile.addCard(players[players_index[i]].removeCard());
							// the fourth card is used as a battle card
							temp = players[players_index[i]].removeCard();
							if (temp.getValue() > max)
							{
								max = temp.getValue();
								index = players_index[i];
								count = 1;
							}
							else
								if (temp.getValue() == max)
								{
									count++;
								}
							cards_deal.addCard(temp);
							positions[cards_deal.cardsLeft() - 1] = players_index[i];
						}
					SetConsoleTextAttribute(hConsoleColor, 14); //YELLOW
					cout << "Battle Cards: ";
					SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
					cards_deal.displayCards();
					cout << endl;
				}
				if (count != 1)
				{
					// Print player's status after each battle
					count_Battles++;
					SetConsoleTextAttribute(hConsoleColor, 9); //DARK BLUE
					cout << "Battle " << count_Battles << " stats: " << endl;
					SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
					for (int i = 0; i < nPlayers; i++)
					{
						cout << "Player " << i + 1 << ": ";
						SetConsoleTextAttribute(hConsoleColor, 9); //DARK BLUE
						cout << "Fierceness = " << players[i].getFierceness();
						cout << "\t Cards = " << players[i].cardsLeft();
						cout << "\t Battles = " << players[i].getPlayedBattles();
						cout << "\t Won = " << players[i].getWonBattles() << endl;
						SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
					}
				}
			} while (count != 1);
			// Found the winner
			SetConsoleTextAttribute(hConsoleColor, 12); //DARK BLUE
			cout << "Player " << index + 1 << " win!!!" << endl;
			SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
			// Cards in cards_deal go into winner hand
			while (!cards_deal.isEmpty())
				players[index].addCard(cards_deal.removeCard());
			// Cards in WarPile go into winner hand
			while (!warPile.isEmpty())
				players[index].addCard(warPile.removeCard());
			// Cards in LostAndFound go into winner hand
			while (!lf.isEmpty())
				players[index].addCard(lf.removeCard());
			// Update Player's Status
			players[index].increaseWonBattles();

			// Print player's status after each battle
			count_Battles++;
			SetConsoleTextAttribute(hConsoleColor, 9); //DARK BLUE
			cout << "Battle " << count_Battles << " stats: " << endl;
			SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
			for (int i = 0; i < nPlayers; i++)
			{
				cout << "Player " << i + 1 << ": ";
				SetConsoleTextAttribute(hConsoleColor, 9); //DARK BLUE
				cout << "Fierceness = " << players[i].getFierceness();
				cout << "\t Cards = " << players[i].cardsLeft();
				cout << "\t Battles = " << players[i].getPlayedBattles();
				cout << "\t Won = " << players[i].getWonBattles() << endl;
				SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
			}
		}
		count = 0;
		for (int i = 0; i < nPlayers; i++)
		{
			if (!players[i].isEmpty())
			{
				count++;
				cout << "Player " << i + 1 << ": ";
				players[i].displayCards();
				cout << endl;
			}
		}
		if (count == 1)
		{
			isStop = true;
			SetConsoleTextAttribute(hConsoleColor, 12); //RED
			cout << "Player " << index + 1 << " wins in final round!";
			SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
		}
	}

	return 0;
}