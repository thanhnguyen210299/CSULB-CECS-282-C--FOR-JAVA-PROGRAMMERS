// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 04 - Overloading Operators (Update Object)
// November 2nd, 2020
// JULIAN AND GREGORIAN FUNCTIONS

#include "upDate.h"

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

// STATIC FUNCTION
int upDate::GetDateCount()
{
	return upDate::dateCount;
}

// CONSTRUCTORS
upDate::upDate() // default constructor
{
	// Dynamically allocate an array of three integers (Month - Day - Year)
	date = new int[3];
	// Increase dateCount
	dateCount++;
	// Set the date to May 11, 1959
	date[0] = 5;
	date[1] = 11;
	date[2] = 1959;
}

upDate::upDate(int M, int D, int Y) // overloaded constructor
{
	// Dynamically allocate an array of three integers (Month - Day - Year)
	date = new int[3];
	// Increase dateCount
	dateCount++;
	// Set the date
	date[0] = M;
	date[1] = D;
	date[2] = Y;
	
	int JD = this->julian();
	Julian2Greg(JD, M, D, Y);

	// check if the date which was passed into the constructor is the same as the result
	// the date is valid
	if (M == date[0] && D == date[1] && Y == date[2])
	{
	}
	// if invalid, use the default date (May 11, 1959)
	else
	{
		date[0] = 5;
		date[1] = 11;
		date[2] = 1959;
	}
}

upDate::upDate(int J) // overload constructor
{
	// Dynamically allocate an array of three integers (Month - Day - Year)
	date = new int[3];
	// Increase dateCount
	dateCount++;
	// Create a date using the Julian date
	Julian2Greg(J, date[0], date[1], date[2]);
}

upDate::upDate(const upDate& obj) // copy constructor
{
	// Dynamically allocate an array of three integers (Month - Day - Year)
	date = new int[3];
	// Increase dateCount
	dateCount++;
	// Copy data from obj
	for (int i = 0; i < 3; i++)
		date[i] = obj.date[i];
}

// FUNCTIONS TO ACCESS TO DATA
void upDate::setDate(int M, int D, int Y)
{
	date[0] = M;
	date[1] = D;
	date[2] = Y;

	int JD = this->julian();
	Julian2Greg(JD, M, D, Y);

	// check if the date which was passed into the constructor is the same as the result
	// the date is valid
	if (M == date[0] && D == date[1] && Y == date[2])
	{
	}
	// if invalid, use the default date (May 11, 1959)
	else
	{
		date[0] = 5;
		date[1] = 11;
		date[2] = 1959;
	}
}

int upDate::getMonth() // return the month in the integer form
{
	return date[0];
}

int upDate::getDay() // return the day of the month
{
	return date[1];
}

int upDate::getYear() // return the year
{
	return date[2];
}

string upDate::getMonthName() // return the name of the month
{
	return months[date[0] - 1];
}

int upDate::julian() // return thhe Julian integer represented by date
{
	return Greg2Julian(date[0], date[1], date[2]);
}

// OPERATORS
upDate upDate::operator + (const int N) // add N days to date
{
	int JD = this->julian() + N;
	int M, D, Y;
	Julian2Greg(JD, M, D, Y);
	return upDate(M, D, Y);
}

upDate& upDate::operator ++ () // increment date by one day - prefix style
{
	int JD = this->julian() + 1;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return *this;
}

upDate upDate::operator ++ (int x) // increment date by one day - postfix style
{
	upDate temp(*this);
	int JD = this->julian() + 1;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return temp;
}

int upDate::operator - (const upDate& obj) // days between two days (negative/positive)
{
	return this->julian() - Greg2Julian(obj.date[0], obj.date[1], obj.date[2]);
}

upDate upDate::operator - (int N) // subtract N days from date
{
	int JD = this->julian() - N;
	int M, D, Y;
	Julian2Greg(JD, M, D, Y);
	return upDate(M, D, Y);
}

upDate& upDate::operator -- () // decrement date by one day - prefix style
{
	int JD = this->julian() - 1;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return *this;
}

upDate upDate::operator -- (int x) // decrement date by one day - postfix style
{
	upDate temp(*this);
	int JD = this->julian() - 1;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return temp;
}

upDate& upDate::operator = (const upDate& obj) // assignment operator
{
	for (int i = 0; i < 3; i++)
		date[i] = obj.date[i];
	return *this;
}

upDate& upDate::operator += (const int N) // add N days to date
{
	int JD = this->julian() + N;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return *this;
}

upDate& upDate::operator -= (const int N) // substract N days from date
{
	int JD = this->julian() - N;
	Julian2Greg(JD, date[0], date[1], date[2]);
	return *this;
}

// COMPARISON CONSTRUCTOR
bool upDate::operator > (const upDate& obj)
{
	int JD1 = this->julian();
	int JD2 = Greg2Julian(obj.date[0], obj.date[1], obj.date[2]);
	if (JD1 > JD2)
		return true;
	return false;
}

bool upDate::operator < (const upDate& obj)
{
	int JD1 = this->julian();
	int JD2 = Greg2Julian(obj.date[0], obj.date[1], obj.date[2]);
	if (JD1 < JD2)
		return true;
	return false;
}

bool upDate::operator == (const upDate& obj)
{
	int JD1 = this->julian();
	int JD2 = Greg2Julian(obj.date[0], obj.date[1], obj.date[2]);
	if (JD1 == JD2)
		return true;
	return false;
}

upDate::~upDate()
{
	// Decrease dateCount
	dateCount--;
	// Delete memory
	delete[] date;
}