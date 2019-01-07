//========================================
// File: HW_5b
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
	char chars;


	fstream nums("data.txt", ios::in);
	fstream results("results.txt", ios::out);

	if(nums.fail()) {
		cout << "Error! Data has failed to open!\n";
		return 1;
	}
	if(results.fail()) {
		cout << "Error! Results failed to open.\n";
		return 1;
	}

	nums.get(chars);

	while(nums != '\0') {
		results.put(chars);
		nums.get(chars);
	}

	cout << "The thing have been moved.\n";

	nums.close();
	results.close();

	system("PAUSE");
	return 0;
}