// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 03 - Structs and Pointers (Student Structure)
// October 12th, 2020

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <Windows.h>
using namespace std;

/******************************
 * Functions For myDate Class *
 ******************************/

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

/*******************************
 *         myDate Class        *
 *******************************/

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
	myDate() // default constructor
	{
		// Set the date to May 11, 1959
		day = 11;
		month = 5;
		year = 1959;
		JD = Greg2Julian(month, day, year);
	}

	myDate(int M, int D, int Y) // overloaded constructor
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

	void display() // display the date in the following format
	{
		cout << months[month - 1] << " " << day << ", " << year;
	}

	void increaseDate(int N) // increment the date by N days
	{
		// change the new JD (JD + N) to GD
		JD += N;
		Julian2Greg(JD, month, day, year);
	}

	void decreaseDate(int N) // decrement the date by N days
	{
		// change the new JD (JD - N) to GD
		JD -= N;
		Julian2Greg(JD, month, day, year);
	}

	int daysBetween(myDate D) // return the number of days between this date and the date D
	{
		return D.JD - this->JD;
	}
	
	int getMonth() // return the month in the integer form
	{
		return month;
	}

	int getDay() // return the day of the month
	{
		return day;
	}

	int getYear() // return the year
	{
		return year;
	}
	int dayOfYear() // return the number of days since the current year began
	{
		return JD - Greg2Julian(1, 1, year) + 1;
	}

	string dayName() //return Monday, Tuesday... according to the day of the week
	{
		return dates[JD % 7];
	}

	string toString()
	{
		return months[month - 1] + " " + to_string(day) + ", " + to_string(year);
	}
};

/*******************************
 *      Student Structure      *
 *******************************/

struct Student
{
	char *name;
	int ID; // unique random value between 1000 and 9999
	char grade; // values A thru F
	myDate birthday; // random value range 1/1/2000 to 12/31/2005
	string hometown;
};

/*******************************
 *    Functions For Student    *
 *******************************/

void swapElements(Student &a, Student &b)
{
	Student temp = a;
	a = b;
	b = temp;
}

void sortList(Student* list, int choice) // bubble sort
{ 
	for (int i = 0; i < 9;i++)
		for (int j = 0; j < 9 - i; j++)
		{
			switch (choice)
			{
			case 1: //Name
				if (strcmp(list[j].name, list[j + 1].name) > 0)
					swapElements(list[j], list[j + 1]);
				break;
			case 2: //Student ID
				if (list[j].ID > list[j + 1].ID)
					swapElements(list[j], list[j + 1]);
				break;
			case 3: //Grade
				if (list[j].grade > list[j + 1].grade)
					swapElements(list[j], list[j + 1]);
				break;
			case 4: //Birthday
				if (list[j].birthday.daysBetween(list[j + 1].birthday) < 0)
					swapElements(list[j], list[j + 1]);
				break;
			case 5: //Home Town
				if (list[j].hometown.compare(list[j + 1].hometown) > 0)
					swapElements(list[j], list[j + 1]);
				break;
			}
		}
}

void display(Student* list, HANDLE hConsoleColor)
{
	SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
	cout << "***********************************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsoleColor, 12); //RED
	cout << left << setw(15) << "Number" << setw(25) << "Name" << setw(15) << "Student ID" << setw(10) << "Grade" << setw(25) << "Birthday" << setw(25) << "Home Town" << endl;
	SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
	for (int i = 0; i < 10; i++)
	{
		cout << left << setw(15) << i + 1 << setw(25)<< list[i].name << setw(15) << list[i].ID << setw(10) << list[i].grade << setw(25) << list[i].birthday.toString() << setw(25) << list[i].hometown << endl;
	}
	cout << "***********************************************************************************************************" << endl;
}

myDate returnRandomBirthday()
{
	int JD_min = Greg2Julian(1, 1, 2000);
	int JD_max = Greg2Julian(12, 31, 2005);

	int JD = rand() % (JD_max - JD_min + 1) + JD_min;
	int day, month, year;
	Julian2Greg(JD, month, day, year);
	myDate birthday(month, day, year);
	return birthday;
}

void populate(Student* list)
{
	int markedList[9000] = { 0 };
	char gradeList[5] = { 'A','B','C','D','F' };
	string nameList[10] = {"Tom Thumb", "Fred Flintstone", "Thanh Nguyen", "Sponge Bob", "Suki Lee", "Miyafuji Yoshika", "Deng Lun", "Fiona Le", "Andries Grobler", "Emma Thompson"};
	string homeTownList[10] = {"Small Ville", "Bedrock", "Vietnam", "Bikini Bottom", "Korea", "Japan", "China", "Vietnam", "California", "New York"};


	for (int i = 0; i < 10; i++)
	{
		//Create name
		list[i].name = new char[nameList[i].length() + 1];
		strcpy(list[i].name, nameList[i].c_str());

		//Create student ID
		list[i].ID = rand() % 9000 + 1000;
		while (markedList[list[i].ID - 1000]) // this ID has been used
		{
			list[i].ID = rand() % 9000;
		}
		markedList[list[i].ID - 1000] = 1; // marked the ID is used

		//Create grade
		list[i].grade = gradeList[rand() % 5];

		//Create birthday
		list[i].birthday = returnRandomBirthday();

		//Create hometown
		list[i].hometown = homeTownList[i];
	}
}

void printMenu(HANDLE hConsoleColor)
{
	SetConsoleTextAttribute(hConsoleColor, 11); //BLUE
	cout << endl<<"______________ MENU _______________" << endl;
	cout << "1. Display list sorted by Name" << endl;
	cout << "2. Display list sorted by Student ID" << endl;
	cout << "3. Display list sorted by Grade" << endl;
	cout << "4. Display list sorted by Birthday" << endl;
	cout << "5. Display list sorted by Home Town" << endl;
	cout << "6. Exit" << endl;
	SetConsoleTextAttribute(hConsoleColor, 14); //YELLOW
	cout << "Your choice is: ";
}

int main()
{
	srand(time(NULL));
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Create pointer
	Student* list = new Student[10];
	// Generate the Student List
	populate(list);
	display(list, hConsoleColor);
	bool isEnd = false;

	while (!isEnd)
	{
		// Print menu and read user's choice
		int choice;
		printMenu(hConsoleColor);
		cin >> choice;
		SetConsoleTextAttribute(hConsoleColor, 15); //WHITE
		cout << endl;

		// If users typed the wrong number, ask the user to re-enter
		while (choice < 1 || choice > 6)
		{
			cout << "It is not valuable. Please select again!!!" << endl << endl << endl;
			printMenu(hConsoleColor);
			cin >> choice;
		}

		if (choice == 6)
			isEnd = true;
		else
		{
			sortList(list, choice);
			display(list, hConsoleColor);
		}
	}

	// Delete dynamic arrays
	for (int i = 0; i < 10; i++)
		delete[] list[i].name;
	delete[] list;
	
	return 0;
}