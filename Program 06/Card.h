#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
public:
	enum ranks { RBlank = 0, Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13 };
	enum suits { SBlank, Space, Heart, Diamond, Club };
	Card(); // Create a blank card
	Card(ranks r, suits s); // Create a card, setting the rank and suit
	void setCard(ranks r, suits s); // Set an existing blank card to a particular value
	int getValue(); // Return the point value of the card
	void showCard(); // Display the card using two fields

private:
	ranks rank; // {A, 1, 2, ..., T, J, Q, K}
	suits suit; // {S, H, D, C}
	int value; // {1, 2, ..., 10}

	void setValue(); // set the point value to the card
};

#endif // CARD_H