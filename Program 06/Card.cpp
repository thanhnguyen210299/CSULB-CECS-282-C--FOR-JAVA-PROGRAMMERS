#ifndef CARD_CPP
#define CARD_CPP

#include "Card.h"

Card::Card() // Create a blank card
{
	rank = RBlank;
	suit = SBlank;
	value = 0;
}

Card::Card(ranks r, suits s) // Create a card, setting the rank and suit
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
	case Ace:
		value = 1;
		break;
	case Jack:
		value = 11;
		break;
	case Queen:
		value = 12;
		break;
	case King:
		value = 13;
		break;
	default:
		value = rank;
	}
}

void Card::setCard(ranks r, suits s) // Set an existing blank card to a particular value
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
	char r, s;
	switch (rank)
	{
	case Ace:
		r = 'A';
		break;
	case Jack:
		r = 'J';
		break;
	case Queen:
		r = 'Q';
		break;
	case King:
		r = 'K';
		break;
	case Ten:
		r = 'T';
		break;
	default:
		r = rank + 48;
	}

	switch (suit)
	{
	case Space:
		s = 'S';
		break;
	case Heart:
		s = 'H';
		break;
	case Diamond:
		s = 'D';
		break;
	default:
		s = 'C';
	}
	if (r == 'T')
		cout << "10" << s;
	else
		cout << r << s;
}

#endif // CARD_CPP
