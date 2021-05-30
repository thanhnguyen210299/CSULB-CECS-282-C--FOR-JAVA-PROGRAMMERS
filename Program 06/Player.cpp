#include "Player.h"

Player::Player()
{
	battles_played = 0;
	battles_won = 0;
}

void Player::increasePlayedBattles()
{
	battles_played++;
}

void Player::increaseWonBattles()
{
	battles_won++;
}

double Player::getFierceness()
{
	if (pile.size() == 0)
		return 0;
	int sum = 0;
	for (int i = 0; i < pile.size(); i++)
		sum += pile[i].getValue();
	return (double)sum / pile.size();
}

int Player::getPlayedBattles()
{
	return battles_played;
}

int Player::getWonBattles()
{
	return battles_won;
}