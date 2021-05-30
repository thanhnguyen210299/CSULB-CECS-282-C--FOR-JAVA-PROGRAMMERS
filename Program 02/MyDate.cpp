#ifndef MYDATE_CPP
#define MYDATE_CPP

#include "MyDate.h"

//function
int Greg2Julian(int month, int day, int year)
{	
	//Formula from "Astronomical Applications"
	int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
	return JD;
}

void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I, J, K, L, N;

	//Equations from "Astronomical Applications"
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

//public
myDate::myDate() // default constructor
{
	// Set the date to May 11, 1959
	day = 11;
	month = 5;
	year = 1959;
	JD = Greg2Julian(month, day, year);
}

myDate::myDate(int M, int D, int Y) // overloaded constructor
{
	day = D;
	month = M;
	year = Y;
	JD = Greg2Julian(month, day, year);

	Julian2Greg(JD, M, D, Y);

	// check if the date which was passed into the constructor is the same as the result
	// the date is valid
	if (D == day && M == month && Y == year)
	{
	}
	// if invalid, use the default date (May 11, 1959)
	else
	{
		day = 11;
		month = 5;
		year = 1959;
		JD = Greg2Julian(month, day, year);
	}
}

void myDate::display() // display the date in the following format
{
	cout << months[month - 1] << " " << day << ", " << year;
}

void myDate::increaseDate(int N) // increment the date by N days
{
	// change the new JD (JD + N) to GD
	JD += N;
	Julian2Greg(JD, month, day, year);
}
void myDate::decreaseDate(int N) // decrement the date by N days
{
	// change the new JD (JD - N) to GD
	JD -= N;
	Julian2Greg(JD, month, day, year);
}

int myDate::daysBetween(myDate D) // return the number of days between this date and the date D
{
	return D.JD - this->JD;	
}

int myDate::getMonth() // return the month in the integer form
{
	return month;
}

int myDate::getDay() // return the day of the month
{
	return day;
}

int myDate::getYear() // return the year
{
	return year;
}

int myDate::dayOfYear() // return the number of days since the current year began
{
	return JD - Greg2Julian(1, 1, year) + 1;
}

string myDate::dayName() //return Monday, Tuesday... according to the day of the week
{
	return dates[JD % 7];
}

#endif // !MYDATE_CPP