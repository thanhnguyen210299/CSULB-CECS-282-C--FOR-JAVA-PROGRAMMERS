#include "CardPile.h"

void CardPile::addCard(Card c)
{
	pile.push_back(c);
}


Card CardPile::removeCard()
{
	Card result = pile.back();
	pile.pop_back();
	return result;
}

void CardPile::displayCards()
{
	for (int i = 0; i < pile.size(); i++)
	{
		pile[i].showCard();
		cout << " ";
	}
}

int CardPile::cardsLeft()
{
	return pile.size();
}

bool CardPile::isEmpty()
{
	if (pile.size() == 0)
		return true;
	return false;
}

Card CardPile::getCard(int i)
{
	return pile[i];
}

CardPile::~CardPile()
{
	pile.clear();
}
