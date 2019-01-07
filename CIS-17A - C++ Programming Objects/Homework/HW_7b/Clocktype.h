#include <iostream>
#include <iomanip>

using namespace std;

class ClockType
{
private:
	int _hrs;
	int _mins;
	int _secs;
public:
	ClockType() {
		_hrs = 0;
		_mins = 0;
		_secs = 0;
	}
	ClockType(int hours, int minutes, int seconds) {
		_hrs = hours;
		_mins = minutes;
		_secs = seconds;
	}
	~ClockType() {}
	void setTime(int hours, int minutes, int seconds) {
		_hrs = hours;
		_mins = minutes;
		_secs = seconds;	
	}
	void incrementSeconds() {
		_secs++;
		//return _secs;
	}
	void incrementMinutes() {
		_mins++;
		//return _mins;
	}
	int incrementHours(int hours) {
		hours++;
		return _hrs;
	}
	void displayPrintTime() {
		cout.fill('0');
		cout << setw(2) << _hrs << ":" << setw(2) << _mins << ":" << setw(2) << _secs << endl;
	}
	bool areTimesEqual(ClockType myClock, ClockType yourClock) {
		return(myClock._hrs == yourClock._hrs && myClock._mins == yourClock._mins && myClock._secs == yourClock._secs);
	}
};
