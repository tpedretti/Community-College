#include <iostream>
#include <time.h>

using namespace std;

class Date
{
private:
	int _month;
	int _day;
	int _year;
public:
	Date() {}
	Date(int month, int day, int year) {
		_month = month;
		_day = day;
		_year = year;
	}
	~Date() {}
	void setDate(int month, int day, int year) {
		_month = month;
		_day = day;
		_year = year;		
	}
	void addDays(int month, int day, int year) {
		_day+= day;
		if(_day > 30) {
			_month++;
			_day -= 30;
		}
		if(_month > 12) {
			_year++;
			_month = 1;
		}
	}
	void displayDate(int month, int day, int year) {
		cout << _month << "/" << _day << "/" << _year << endl;
	}
};