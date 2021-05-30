// Thanh Nguyen _ ID: 026843815
// CECS 282-01
// Prog 05 - BigInt
// November 23rd, 2020

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class BigInt
{
private:
	vector<char> number;
public:
	BigInt();
	BigInt(int n);
	BigInt(string n);
	BigInt(const BigInt& obj);
	BigInt operator++(int x);
	bool operator<=(const int& value);
	bool operator<=(const BigInt& obj);
	bool operator==(const int& value);
	bool operator==(const BigInt & obj);
	BigInt operator-(int value);
	BigInt operator+(const BigInt& obj);
	BigInt operator+(const int& value);
	BigInt& operator=(const BigInt& obj);
	bool operator<(const int& value);
	bool operator<(const BigInt& obj) const;
	friend ostream& operator<<(ostream& os, const BigInt& obj);
	~BigInt();
	void print();
};

BigInt goldRabbits(BigInt bigN)
{
	static map<BigInt, BigInt> results;
	if (bigN == 0 || bigN == 1)
		results[bigN] = BigInt(1);
	else
	{
		//cout << bigN - 1 << " " << bigN - 2 << endl;
		results[bigN] = results[bigN - 1] + results[bigN - 2];
	}
	return results[bigN];
}


int goldRabbits(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int t1 = 1;
	int t2 = 1;
	int temp;
	for (int i = 2; i < n; i++)
	{
		temp = t1 + t2;
		if (temp < 0)
		{
			throw "Overflow Error - goldRabbits overflowed using " + to_string(i);
		}
		t1 = t2;
		t2 = temp;
	}
	return temp;
}

void pause()
{
	cout << "Press Enter to continue..."; 
	getchar(); 
}

int main()
{
	ofstream out;
	out.open("output.txt");
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	pause();
	cout << "\nB1:";
	B1.print();
	cout << endl;
	pause();

	//bool isPrint = true;
	BigInt result;
	for (BigInt index = 0; index <= 3000; index++)
	{
		/*if (index == 8 || index == 67)
		{
			isPrint = false;
			cout << endl << "(some lines removed)" << endl << endl;
		}
		if (index == 56 || index == 2994)
			isPrint = true;*/
		result = goldRabbits(index);
		out << "The GoldRabbit of (" << index << ") is " << result << endl;
		//if (isPrint)
			cout << "The GoldRabbit of (" << index << ") is " << result << endl;
	}
	pause();

	cout << "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 = goldRabbits(BigInt(3000));
	gR3000.print();

	pause();

	int n = 500;
	try {

		cout << "The value of goldRabbits(n) is:" << goldRabbits(n) << endl;
	}
	catch (string error)
	{
		cout << error << endl;
		cout << "Transitioning to BigInt\n";
		cout << goldRabbits(BigInt(n)) << endl;
	}

	pause();
	out.close();
}

BigInt::BigInt()
{
	number.push_back('0');
}

BigInt::BigInt(int n)
{
	if (n == 0)
		number.push_back('0');
	while (n > 0)
	{
		number.insert(number.begin(), n % 10 + 48);
		n /= 10;
	}
}

BigInt::BigInt(string n)
{
	for (int i = 0; i < n.size(); i++)
		number.push_back(n[i]);
}

BigInt::BigInt(const BigInt& obj)
{
	// Copy data from obj
	for (int i = 0; i < obj.number.size(); i++)
		number.push_back(obj.number.at(i));
}


// Overload Operator
BigInt BigInt::operator + (const int& value)
{
	return *this + BigInt(value);
}

BigInt BigInt::operator + (const BigInt& obj)
{
	BigInt result;
	result.number.clear();
	int temp, carry = 0;
	int i = number.size() - 1;
	int j = obj.number.size() - 1;
	do
	{
		if (i >= 0 && j >= 0)
			temp = number.at(i) + obj.number.at(j) - 96 + carry;
		else
		{
			if (i < 0)
				temp = obj.number.at(j) - 48 + carry;
			if (j < 0)
				temp = number.at(i) - 48 + carry;
		}
		result.number.insert(result.number.begin(), temp % 10 + 48);
		carry = temp / 10;
		i--;
		j--;
	} while (i >= 0 || j >= 0);
	if (carry > 0)
		result.number.insert(result.number.begin(), carry + 48);
	return result;
}

BigInt BigInt::operator ++ (int x)
{
	*this = *this + BigInt(1);
	return *this;
}

BigInt BigInt::operator - (int value)
{
	BigInt result;
	result.number.clear();
	int i = number.size() - 1;
	int carry = 0, temp;
	int value_temp;
	while (i >= 0)
	{
		value_temp = value % 10;
		temp = number.at(i) - 48;
		if (temp < value_temp + carry)
		{
			temp = temp + 10 - value_temp - carry;
			carry = 1;
		}
		else
		{
			temp = temp - value_temp - carry;
			carry = 0;
		}
		result.number.insert(result.number.begin(), temp + 48);
		i--;
		value /= 10;
	}
	if (result.number[0] == '0' && result.number.size() > 1)
		result.number.erase(result.number.begin());
	return result;
}

bool BigInt::operator < (const int& value)
{
	return *this < BigInt(value);
}

bool BigInt::operator < (const BigInt& obj) const
{
	if (this->number.size() != obj.number.size())
		return (this->number.size() < obj.number.size()) ? true : false;
	else
		for (int i = 0; i < number.size(); i++)
			if (this->number[i] != obj.number[i])
				return (this->number[i] < obj.number[i]) ? true : false;
	return false;
}

bool BigInt::operator == (const int& value)
{
	return *this == BigInt(value);
}

bool BigInt::operator == (const BigInt& obj)
{
	bool isEquals = false;
	if (this->number.size() == obj.number.size())
	{
		isEquals = true;
		for (int i = 0; i < this->number.size(); i++)
			if (this->number[i] != obj.number[i])
				isEquals = false;
	}
	return isEquals;
}

bool BigInt::operator <= (const int& value)
{
	return (*this < value || *this == value) ? true : false;
}

bool BigInt::operator <= (const BigInt &obj)
{
	return (*this < obj || *this == obj) ? true : false;
}

BigInt& BigInt::operator = (const BigInt& obj)
{
	number.clear();
	for (int i = 0; i < obj.number.size(); i++)
		number.push_back(obj.number[i]);
	return *this;
}

// Print
ostream& operator << (ostream& os, const BigInt& obj)
{
	if (obj.number.size() < 13)
	{
		for (int i = 0; i < obj.number.size(); i++)
			os << obj.number[i];
	}
	else
	{
		int exp = obj.number.size();
		os << obj.number[0] << ".";
		for (int i = 1; i < 11; i++)
			os << obj.number[i];
		os << "e" << exp;
	}
	return os;
}

void BigInt::print()
{
	for (int i = 0; i < number.size(); i++)
		cout << number[i];
	cout << endl;
}

// Destructor
BigInt::~BigInt()
{
	number.clear();
}
