#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "Cat.h"


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

	cout << "Record written to file.\n";

	catInfoFile.close();

	system("PAUSE");
	return 0;
}