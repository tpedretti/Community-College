#include "Class.h"
#include "Binary Search.h"
#include "Find.h"
#include "Reverse.h"

int main()
{
	Algorithms aObject;
	const int SIZE = 8;
	int userEnter;
	int numberArray[SIZE] = {32,71,12,45,26,80,53,33};
	vector<int> myArray (numberArray, numberArray+8);
	vector<int>::iterator it;

	cout << "The Array before being sorted: \t";
	for (int i = 0; i < SIZE; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
	
	sort (myArray.begin(), myArray.end(), aObject);
	
	cout << "The Array after being sorted: \t";
	for (it=myArray.begin(); it!=myArray.end(); ++it) {
		cout << " " << *it;
	}
	cout << endl;


	cout << "Looking for a 12 within the array... ";
	if (binary_search (myArray.begin(), myArray.end(), 12, aObject)) {
		cout << "found!\n";
	}
	else {
		cout << "Not found.\n";
	}
	
	cout << "Looking for a 25 within the array... ";
	if (binary_search (myArray.begin(), myArray.end(), 25, aObject)) {
		cout << "found!\n";
	}
	else {
		cout << "Not found.\n";
	}

	cout << "Looking for a 80 within the array... ";
	if (binary_search (myArray.begin(), myArray.end(), 80, aObject)) {
		cout << "found!\n";
	}
	else {
		cout << "Not found.\n";
	}

	cout << "Looking for a 100 within the array... ";
	if (binary_search (myArray.begin(), myArray.end(), 100, aObject)) {
		cout << "found!\n";
	}
	else {
		cout << "Not found.\n";
	}

	cout << "What number would you like to look for within the Array? : ";
	cin >> userEnter;

	cout << "Looking for a " << userEnter << " within the array... ";
	if(binary_search (myArray.begin(), myArray.end(), userEnter, aObject)) {
		cout << "found!\n";
	}
	else {
		cout << "Not found. \n";
	}

	it = find (myArray.begin(), myArray.end(), 53);
	it++;
	cout << "The element following 53 is " << *it << endl;

	it = find (myArray.begin(), myArray.end(), 12);
	it++;
	cout << "The element following 12 is " << *it << endl;

	reverse(myArray.begin(), myArray.end());

	cout << "The Array in reverse: ";
	for(it = myArray.begin(); it != myArray.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;


	system("PAUSE");
	return 0;
}