#ifndef CARDPILE_H
#define CARDPILE_H

#include "Card.h"
#include <vector>

using namespace std;

class CardPile
{
protected:
	vector<Card> pile;

public:
	void addCard(Card c);
	Card removeCard();
	void displayCards();
	int cardsLeft();
	bool isEmpty();
	Card getCard(int i);
	~CardPile();
};


class WarPile : public CardPile
{};

class LostAndFound : public CardPile
{};

#endif // !CARDPILE_H
