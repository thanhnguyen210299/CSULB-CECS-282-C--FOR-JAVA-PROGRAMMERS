#ifndef PLAYER_H
#define PLAYER_H

#include "CardPile.h"

class Player : public CardPile
{
private:
	int battles_played;
	int battles_won;
public:
	Player();
	void increasePlayedBattles();
	void increaseWonBattles();
	double getFierceness();
	int getPlayedBattles();
	int getWonBattles();
};
#endif // !PLAYER_H
