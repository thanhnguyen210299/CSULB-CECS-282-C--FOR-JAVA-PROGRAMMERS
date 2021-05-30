#ifndef CARD_CPP
#define CARD_CPP

#include "Card.h"

Card::Card() // Create a blank card
{
	rank = 0;
	suit = 0;
	value = 0;
}

Card::Card(char r, char s) // Create a card, setting the rank and suit
{
	rank = r;
	suit = s;
	setValue();
}

void Card::setValue()
{
	/* 
		a value of A is 1
		with i = 2 .. 10, value is i
		a value of J, Q, K is 10
	*/
	switch (rank)
	{
	case 'A':
		value = 1;
		break;
	case 'J':
		value = 10;
		break;
	case 'Q':
		value = 10;
		break;
	case 'K':
		value = 10;
		break;
	case 'T':
		value = 10;
		break;
	default:
		value = rank - 48; // ASCII: '0' is 48
	}
}

void Card::setCard(char r, char s) // Set an existing blank card to a particular value
{
	rank = r;
	suit = s;
	setValue();
}

int Card::getValue() // Return the point value of the card
{
	return value;
}

void Card::showCard() // Display the card using two fields
{
	if (rank == 'T')
		cout << "10";
	else
		cout << rank;
	cout << suit;
}

#endif // CARD_CPP
