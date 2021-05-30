#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "Function.h"

void printMenu(bool menu[]) // Display the menu
{
	cout << endl << "*** Welcome to Solitaire Prime! ***" << endl;
	cout << "______________ MENU _______________" << endl;
	if (menu[0])
		cout << "1. New Deck" << endl;
	if (menu[1])
		cout << "2. Display Deck" << endl;
	if (menu[2])
		cout << "3. Shuffle Deck" << endl;
	if (menu[3])
		cout << "4. Play Solitaire Prime" << endl;
	if (menu[4])
		cout << "5. Exit" << endl << endl;

	cout << "Your choice is: ";
}

bool isPrime(int n) // Check if n is prime
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	for (int i = 2; i < n - 1; i++)
		if (n % i == 0)
			return false;
	return true;
}

void showPile(vector<Card> pile, int total, bool isLast) // Show the card in one pile
{
	cout << "+++++++++++++++++++" << endl << "Pile: ";
	for (int i = 0; i < pile.size() - 1; i++)
	{
		pile.at(i).showCard();
		cout << ", ";
	}
	pile.back().showCard();
	cout << endl << "Prime: " << total << " " << endl;

	if (isLast)
	{
		if (isPrime(total))
			cout << endl << "YOU WIN!!!" << endl << endl;
		else
			cout << endl << "YOU LOSE!!!" << endl << endl;
	}
}

#endif // FUNCTION_CPP