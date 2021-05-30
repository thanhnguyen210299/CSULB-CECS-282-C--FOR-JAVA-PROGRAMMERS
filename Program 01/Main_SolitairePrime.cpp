// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 1 - Solitaire Prime
// September 14th, 2020

#include "Deck.h"
#include "Function.h"

int main()
{
	Deck deck;
	int choice, count = 0, total = 0; // use count to get the number of pile, and total to get the sum point of each pile
	vector<Card> pile; // to save the cards in each pile
	bool isEnd = false; // isEnd = true when user wants to exit
	bool menu[5] = { true, true, true, true, true };


	while (!isEnd)
	{
		// Print menu and read user's choice
		printMenu(menu);
		cin >> choice;
		cout << endl;

		// If users typed the wrong number, ask the user to re-enter
		while (choice < 1 || choice > 5)
		{
			cout << "It is not valuable. Please select again!!!" << endl << endl << endl;
			printMenu(menu);
			cin >> choice;
		}

		switch (choice)
		{
		case 5: // Exit
			cout << "The game is end!!!" << endl;
			isEnd = true;
			break;
		
		case 4: // Play Solitaire Prime
			cout << endl << "Let's start!!!" << endl;

			// If still have card in deck
			while (deck.cardsLeft() > 0)
			{
				count++;
				while (!isPrime(total) && deck.cardsLeft() > 0)
				{
					
					pile.push_back(deck.deal()); // Deal a new card into the pile
					total += pile.back().getValue();
					//pile.back().showCard();
				} 

				if (deck.cardsLeft() > 0)
				{
					showPile(pile, total, false);
					pile.clear(); // Start the new pile
					total = 0;
				}
			}

			showPile(pile, total, true);
			cout << "Number of Piles: " << count << endl;
			
			menu[3] = false;
			menu[2] = false;
			menu[1] = false;
			break;
		
		case 3: // Shuffle
			deck.shuffle();
			deck.showDeck();
			break;
		
		case 2: // Display the deck
			deck.showDeck();
			break;
		
		case 1: // Refresh the deck
			menu[3] = true;
			menu[2] = true;
			menu[1] = true;
			
			deck.refreshDeck();
			
			pile.clear();
			count = 0;
			total = 0;
			break;
		}
	}
	return 0;
}