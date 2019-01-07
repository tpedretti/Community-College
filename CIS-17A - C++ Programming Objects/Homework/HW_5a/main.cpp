//========================================
// File: HW_5a
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/24/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string numbers;

	fstream nums("data.txt", ios::in);

	if(nums.fail()) {
		cout << "Error!\n";
		return 1;
	}

	getline(nums, numbers, '\0');

	cout << numbers << endl;

	nums.close();

	system("PAUSE");
	return 0;
}