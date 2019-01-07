#include "Presidents.h"

int main()
{
	const int SIZE = 3;
	Presidents preInfo[SIZE];
	int number;
	string name;
	string quote;

	for(int i = 0; i < SIZE; i++) {

		cout << "Enter the first president's number: ";
		cin >> number;
		cin.ignore();
		cout << "Enter his name: ";
		getline(cin, name);
		cout << "Enter his quote: ";
		getline(cin, quote);

		cout << endl;

		preInfo[i].setNumber(number);
		preInfo[i].setName(name);
		preInfo[i].setQuote(quote);	
	}

	cout << "The presidents are: \n";
	for(int p = 0; p < SIZE; p++) {
		preInfo[p].displayPresidents();
	//for(int p = SIZE - 1; p >= 0; p--) {	
		//preInfo[p].displayPresidents();
	
	}


	//cout << preInfo.getName << "," << preInfo.getNumber << "the president, said: " << preInfo.getQuote << ".";

	system("PAUSE");
	return 0;
}