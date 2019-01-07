//========================================
// File: HW_2c
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/1/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
void getInfo(char street[], char city[], char state[], char zip[]);
void displayAddress(char address[]);
using namespace std;

int main()
{
	char street[30] = "";
	char city[20] = "";
	char state[3] = "";
	char zip[6] = {0};
	char address[60] = "";
	char again = 'Y';

	while(toupper(again) == 'Y') {
	getInfo(street, city, state, zip);

	strcpy(address, street);
	strcat(address, ", ");
	strcat(address, city);
	strcat(address, ", ");
	strcat(address, state);
	strcat(address, ", ");
	strcat(address, zip);

	displayAddress(address);

	cout << "Do you want to run the program again (Y/N)? ";
	cin >> again;
	cin.ignore();
	}

	system("PAUSE");
	return 0;
}

void getInfo(char street[], char city[], char state[], char zip[])
{
	cout << "Enter your street address: ";
	cin.getline(street, 30);
	cout << "Enter your city: ";
	cin.getline(city, 20);
	cout << "Enter your state (2 digits): ";
	cin.getline(state, 3);
	cout << "Enter your 5-digit zip: ";
	cin.getline(zip, 6);
}

void displayAddress(char address[])
{
	cout << "Your full address is: \n \t " << address << endl;
}