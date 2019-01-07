//========================================
// File: HW_5c
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/24/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string numbers;
	char addInNumbers;

	fstream numsInFile("results.txt", ios::in | ios::out);
	fstream numsOutFile("results.txt", ios::app);

	if(numsInFile.fail()) {
		cout << "Error!\n";
		return 1;
	}

	cout << "Here are the numbers in the file: \n";

	getline(numsInFile, numbers, '\0');

	cout << numbers << endl;

	cout << "Enter 3 more numbers:\n";

	for(int i = 0; i < 3; i++) {
		cin >> addInNumbers;
		numsOutFile << addInNumbers << endl;
	}

	cout << "The numbers have been written (appended) to results.txt.\n";

	numsInFile.close();
	numsOutFile.close();

	system("PAUSE");
	return 0;
}