#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <stdlib.h> // srand, rand 
#include <time.h>   // time 

class Deck
{
private:
	Card cards[52];
	char ranks[13] = { 'A', '2', '3', '4','5','6','7','8','9','T','J','Q','K' };
	char suits[4] = { 'S', 'H','D','C' };
	int topCards;

	void createNewDeck();
public:
	Deck(); // Create a deck of 52 cards
	void refreshDeck(); // Reset the deck so it looks like a new deck
	Card deal(); // Deal a card from the top of the deck
	void shuffle(); // Shuffle the cards in the deck
	int cardsLeft(); // Return the number of cards left in the deck
	void showDeck(); // Show all the cards in the deck
};

#endif // DECK_H

