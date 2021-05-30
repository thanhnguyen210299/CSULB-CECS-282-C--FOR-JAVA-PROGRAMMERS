#ifndef DECK_CPP
#define DECK_CPP

#include "Deck.h"

Deck::Deck() 
{
	/* 
		Ace of Spades on top
		followed by the rest of the spades in order
		followed by Hearts, Diamonds and Clubs
	*/

	srand(time(NULL)); // Function to set the seed of the random number

	createNewDeck();
}

void Deck::createNewDeck() // Create a deck of 52 cards
{
	int count = 0;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4; j++)
		{
			cards[count].setCard(ranks[i], suits[j]);
			count++;
		}
	topCards = 0;
}

void Deck::refreshDeck() // Reset the deck so it looks like a new deck
{
	createNewDeck();
}

Card Deck::deal() // Deal a card from the top of the deck
{
	topCards++;
	return cards[topCards - 1];
}

void Deck::shuffle() // Shuffle the cards in the deck
{
	/*
		At each time, get random 2 cards, and then swap them. Do it 100 times.
	*/
	
	int firstCard, secondCard;
	Card tmp;

	for (int i = 0; i < 100; i++)
	{
		firstCard = rand() % 52;
		secondCard = rand() % 52;

		tmp = cards[firstCard];
		cards[firstCard] = cards[secondCard];
		cards[secondCard] = tmp;
	}
	cout << "The deck is shuffle!!!" << endl << endl;
}

int Deck::cardsLeft() // Return the number of cards left in the deck
{
	return 52 - topCards;
}

void Deck::showDeck() // Show all the cards in the deck
{
	// Show table 13 columns and 4 rows
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 52; j += 4)
		{
			cards[j].showCard();
			cout << " ";
		}
		cout << endl;
	}
}

#endif // DECK_CPP