#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card
{
private:
	char rank; // {A, 1, 2, ..., T, J, Q, K}
	char suit; // {S, H, D, C}
	int value; // {1, 2, ..., 10}

	void setValue(); // set the point value to the card
public:
	Card(); // Create a blank card
	Card(char r, char s); // Create a card, setting the rank and suit
	void setCard(char r, char s); // Set an existing blank card to a particular value
	int getValue(); // Return the point value of the card
	void showCard(); // Display the card using two fields
};

#endif // CARD_H