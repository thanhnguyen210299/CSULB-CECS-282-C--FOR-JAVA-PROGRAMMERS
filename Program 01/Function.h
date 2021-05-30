#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <iostream>
#include "Card.h"
using namespace std;

void printMenu(bool menu[]); // Display the menu
bool isPrime(int n); // Check if n is prime
void showPile(vector<Card> pile, int total, bool isLast); // Show the card in one pile

#endif // FUNCTION_H