#ifndef MYDATE_H
#define MYDATE_H

#include <string>
#include <iostream>
using namespace std;

class myDate
{
private:
	string months[12] = { "January", "February","March","April","May","June","July","August","September","October","November","December" };
	string dates[7] = { "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday", "Sunday" };
	int day;
	int month;
	int year;
	int JD;
public:
	myDate(); // default constructor
	myDate(int M, int D, int Y); // overloaded constructor
	void display(); // display the date in the following format
	void increaseDate(int N); // increment the date by N days
	void decreaseDate(int N); // decrement the date by N days
	int daysBetween(myDate D); // return the number of days between this date and the date D
	int getMonth(); // return the month in the integer form
	int getDay(); // return the day of the month
	int getYear(); // return the year
	int dayOfYear(); // return the number of days since the current year began
	string dayName(); //return Monday, Tuesday... according to the day of the week

};

#endif // MYDATE_H
