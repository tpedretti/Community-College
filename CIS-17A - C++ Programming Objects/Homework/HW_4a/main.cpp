//========================================
// File: HW_4
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/15/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>

using namespace std;

int getNum(int num);
void displayBin(int num);
void decToBinary(int num);


int main()
{
	int num = 0;
	int remainder = 0;

	num = getNum(num);
	displayBin(num);

	system("PAUSE");
	return 0;
}

int getNum(int num)
{
	cout << "Enter a non-negative integer value: ";
	cin >> num;
	return num;
}

void displayBin(int num)
{
	if(num < 0) {
		cout << "Decimal " << num << " = Invalid entry.";
	}
	else {
		cout << "Decimal " << num << " converted to binary is: ";
		decToBinary(num);
		cout << endl;
	}
}

void decToBinary(int num)
{
	int remainder;
	if(num <= 1) {
		cout << num;
		return;
	}
	remainder = num % 2;
	decToBinary(num >> 1);
	cout << remainder;
}
