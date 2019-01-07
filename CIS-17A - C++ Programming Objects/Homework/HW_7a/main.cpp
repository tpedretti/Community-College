#include "Date.h"

int main()
{
	Date today(5, 16, 2011);
	Date payDay;
	int month;
	int day;
	int year;

	cout << "Please enter in your pay date: \n";
	cout << "MONTH: ";
	cin >> month;
	cout << "DAY: ";
	cin >> day;
	cout << "YEAR: ";
	cin >> year;

	payDay.setDate(month, day, year);

	cout << "Today's date is: ";
	//today.displayDate(month, day, year);
	time_t current = time(0);
	cout << ctime(&current);
	
	

	cout << "Your pay date is: ";
	payDay.displayDate(month, day, year);


	
	payDay.addDays(0, 7, 0);
	cout << "One week added to your pay date: ";
	payDay.displayDate(month, day, year);
	cout << endl;


	system("PAUSE");
	return 0;
}