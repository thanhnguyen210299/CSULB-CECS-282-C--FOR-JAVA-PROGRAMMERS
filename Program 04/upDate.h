#ifndef UPDATE_H
#define UPDATE_H

#include <string>
#include <iostream>
using namespace std;

class upDate
{
private:
	int* date;
	static int dateCount;
	string months[12] = { "January", "February","March","April","May","June","July","August","September","October","November","December" };
public:
	// Static function
	static int GetDateCount();

	// Constructor
	upDate(); // default constructor
	upDate(int M, int D, int Y); // overloaded constructor
	upDate(int J); // overload constructor
	upDate(const upDate& obj);

	// Access to data
	void setDate(int M, int D, int Y);
	int getMonth(); // return the month in the integer form
	int getDay(); // return the day of the month
	int getYear(); // return the year
	string getMonthName(); // return the name of the month
	int julian(); // return thhe Julian integer represented by date

	// Operator
	upDate operator + (int N); // add N days to date

	upDate& operator ++ (); // increment date by one day - prefix style
	upDate operator ++ (int x); // increment date by one day - postfix style

	int operator - (const upDate& obj); // days between two days (negative/positive)
	upDate operator - (int N); // subtract N days from date

	upDate& operator -- (); // decrement date by one day - prefix style
	upDate operator -- (int x); // decrement date by one day - postfix style

	upDate& operator = (const upDate& obj); // assignment operator
	upDate& operator += (const int N); // add N days to date
	upDate& operator -= (const int N); // substract N days from date

	// Comparison Operator
	bool operator > (const upDate& obj);
	bool operator < (const upDate& obj);
	bool operator == (const upDate& obj);
	
	// Print
	friend ostream& operator << (ostream& os, const upDate& obj);

	// Destructor
	~upDate();
};

#endif // UPDATE_H
