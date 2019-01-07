//========================================
// File: HW_2b
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/1/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>

void displayInfo(char fullName[], int age);

using namespace std;

int main()
{
	char firstName[10] = "Tom";
	char lastName[10] = "";
	char fullName[20] = "";
	int age = 0;

	cout << "Enter your Age: ";
	cin >> age;
	cout << "Enter the last name: ";
	cin.ignore();
	cin.getline(lastName, 10);

	strcpy(fullName, firstName);
	strcat(fullName, " ");
	strcat(fullName, lastName);

	displayInfo(fullName, age);

	system("PAUSE");
	return 0;
}

void displayInfo(char fullName[], int age)
{
	cout << "Hello " << fullName << ". You are " << age << " years old.\n";
}