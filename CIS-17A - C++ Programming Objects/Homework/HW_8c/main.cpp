#include "FamousPeople.h"

int main()
{
	People pInfo1;
	People pInfo2;
	People pInfo3;
	string name;
	string quote;
	int month;
	int day;
	int year;

	cout << "Enter the first famous person: ";
	getline(cin, name);
	cout << "Enter the quotation: ";
	getline(cin, quote);
	cout << "Enter the birthdate:\n";
	cout << "MONTH: ";
	cin >> month;
	cout << "DAY: ";
	cin  >> day;
	cout  << "YEAR: ";
	cin >> year;
	cin.ignore();
	pInfo1.setDate(month, day, year);
	pInfo1.setName(name);
	pInfo1.setQuote(quote);

	system("CLS");

	cout << "Enter the second famous person: ";
	getline(cin, name);
	cout << "Enter the quotation: ";
	getline(cin, quote);
	cout << "Enter the birthdate:\n";
	cout << "MONTH: ";
	cin >> month;
	cout << "DAY: ";
	cin  >> day;
	cout  << "YEAR: ";
	cin >> year;
	pInfo2.setDate(month, day, year);
	pInfo2.setName(name);
	pInfo2.setQuote(quote);
	cin.ignore();

	system("CLS");

	cout << "Enter the third famous person: ";
	getline(cin, name);
	cout << "Enter the quotation: ";
	getline(cin, quote);
	cout << "Enter the birthdate:\n";
	cout << "MONTH: ";
	cin >> month;
	cout << "DAY: ";
	cin  >> day;
	cout  << "YEAR: ";
	cin >> year;
	pInfo3.setDate(month, day, year);
	pInfo3.setName(name);
	pInfo3.setQuote(quote);
	cin.ignore();

	system("CLS");

	cout << "Here are the famous people:\n ";

		pInfo1.displayPerson(name, quote);
		pInfo1.displayDate(month, day, year);
		pInfo2.displayPerson(name, quote);
		pInfo2.displayDate(month, day, year);
		pInfo3.displayPerson(name, quote);
		pInfo3.displayDate(month, day, year);

	system("PAUSE");
	return 0;
}