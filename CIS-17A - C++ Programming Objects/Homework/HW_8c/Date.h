#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int _month;
	int _day;
	int _year;
public:
	Date() {
		_month = 0;
		_day = 0;
		_year = 0;
	}
	Date(int month, int day, int year) {
		/*_month = month;
		_day = day;
		_year = year;*/
	}
	~Date() {}
	void setDate(int month, int day, int year) {
		_month = month;
		_day = day;
		_year = year;
	}
	void displayDate(int month, int day, int year) {
		cout << "Brithdate: " <<  _month << "/" << _day << "/" << _year << endl;
	}
};