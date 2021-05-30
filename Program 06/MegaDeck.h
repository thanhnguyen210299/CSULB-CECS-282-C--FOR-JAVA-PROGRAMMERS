#ifndef MEGADECK_H
#define MEGADECK_H

#include "Deck.h"
#include <stdlib.h> // srand, rand 
#include <time.h>   // time 

class MegaDeck
{
private:
	vector<Deck> decks;
public:
	MegaDeck(int n);
	void displayDecks();
	Card deal();
	int cardsLeft();
};

#endif // !MEGADECK_H
