#include "MegaDeck.h"

MegaDeck::MegaDeck(int n)
{
	srand(time(NULL)); // Function to set the seed of the random number

	for (int i = 0; i < n; i++)
	{
		Deck temp;
		temp.shuffle();
		decks.push_back(temp);
	}
}

void MegaDeck::displayDecks()
{
	for (int i = 0; i < decks.size(); i++)
	{
		cout << "Deck " << i + 1 << ": ";
		decks[i].showDeck();
		cout << endl;
	}
}

Card MegaDeck::deal()
{
	int i = decks.size() - 1;
	while (decks[i].cardsLeft() == 0)
		i--;
	return decks[i].deal();
}

int MegaDeck::cardsLeft()
{
	int sum = 0;
	for (int i = 0; i < decks.size(); i++)
		sum += decks[i].cardsLeft();
	return sum;
}
