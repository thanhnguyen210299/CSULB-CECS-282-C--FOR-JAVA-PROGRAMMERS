#include "Deck.h"

Deck::Deck()
{
	/*
		Ace of Spades on top
		followed by the rest of the spades in order
		followed by Hearts, Diamonds and Clubs
	*/
	createNewDeck();
}

void Deck::createNewDeck() // Create a deck of 52 cards
{
	for (const auto i : { Card::Ace, Card::Two, Card::Three, Card::Four, Card::Five, Card::Six, Card::Seven, Card::Eight, Card::Nine, Card::Ten, Card::Jack, Card::Queen, Card::King })
		for (const auto j : { Card::Space, Card::Heart, Card::Diamond, Card::Club })
			pile.push_back(Card(i, j));
}

void Deck::refreshDeck() // Reset the deck so it looks like a new deck
{
	createNewDeck();
}

Card Deck::deal() // Deal a card from the top of the deck
{
	return removeCard();
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

		tmp = pile[firstCard];
		pile[firstCard] = pile[secondCard];
		pile[secondCard] = tmp;
	}
}

void Deck::showDeck() // Show all the cards in the deck
{
	displayCards();
}