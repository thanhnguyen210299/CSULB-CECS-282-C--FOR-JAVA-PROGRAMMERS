// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 0 – Happy Birthday
// August 31st, 2020

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	int age;
	int birthYear;
	char thisYear;

	cout << "What is your name? ";
	getline(cin, name); // Use it to get all the string (include blank space)

	cout << "How old are you " << name << "? ";
	cin >> age;

	cout << name << ", have you had your birthday yet this year (y/n)? ";
	cin >> thisYear;

	if (thisYear == 'y' || thisYear == 'Y')
		birthYear = 2020 - age;
	else
		birthYear = 2020 - age - 1;

	cout << endl << "Hi " << name << "!!!\n\nI guess that you were born in " << birthYear << endl;

	cout << "\n\nPress 'Enter' to continue:"; 
	
	getchar(); // this line will clear out the input buffer - there is a leftover carriage return
	getchar(); // this line will cause the program to pause until you press the Enter key
	
	return 0;
}
