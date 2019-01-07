#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
#include "cat.h"


int main()
{
	Cat catInfo;
	fstream catInfoFile;

	catInfoFile.open("cats.bin", ios::out | ios::in | ios::binary);

	cout << "Enter 3 cat records.\n";

	for(int i = 0; i < 3; i++) {
		cout << "Enter information about a cat:\n";
		cout << "NAME: ";
		cin.getline(catInfo.name, 50);
		cout << "AGE: ";
		cin >> catInfo.age;
		cin.ignore();

		catInfoFile.write(reinterpret_cast<char *>(& catInfo), sizeof(catInfo));
	}

	cout << "Record written to file.\n\n";
	
	cout << "Enter in one more record:\n";
	cout << "NAME: ";
	cin.getline(catInfo.name, 50);
	cout << "AGE: ";
	cin >> catInfo.age;

	catInfoFile.write(reinterpret_cast<char *>(& catInfo),sizeof(catInfo));
	
	catInfoFile.seekp(0L, ios::beg);

	cout << "Here is a list of all cats:\n";
	for(int p = 0; p < 4; p++) {
		catInfoFile.read(reinterpret_cast<char *>(& catInfo), sizeof(catInfo));
		cout << setw(10) << left << catInfo.name << catInfo.age;
		cout << endl;
	}

	catInfoFile.close();

	system("PAUSE");
	return 0;
}