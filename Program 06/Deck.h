#ifndef DECK_H
#define DECK_H

#include "CardPile.h"

using namespace std;

class Deck: public CardPile
{
private:

	void createNewDeck();
public:
	Deck(); // Create a deck of 52 cards
	void refreshDeck(); // Reset the deck so it looks like a new deck
	Card deal(); // Deal a card from the top of the deck
	void shuffle(); // Shuffle the cards in the deck
	void showDeck(); // Show all the cards in the deck
};

#endif // DECK_H