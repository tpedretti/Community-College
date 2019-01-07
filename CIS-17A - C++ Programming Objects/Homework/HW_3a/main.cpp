//========================================
// File: HW_3a
// =======================================
// Programmer: Taylor Pedretti
// Date: 3/10/2011
// Class: CIS 17A
// Instructor: Dennis Rainey
// =======================================
#include <iostream>
#include <iomanip>

using namespace std;

struct Time
{
	int seconds;
	int minutes;
	int hours;
};

void getTime(Time & time);
bool isTimeValid(Time & time);
void addOneSecond(Time & time);
void displayTime(Time time);

const int MAX_HOURS = 23;
const int MAX_MINS = 59;
const int MAX_SECS = 59;

int main()
{
	Time time;
	char again = 'Y';

	while(toupper(again) == 'Y') {
	getTime(time);
	addOneSecond(time);
	displayTime(time);
	cout << "Do it again? (Y/N) ";
	cin >> again;
	}

	system("PAUSE");
	return 0;
}

void getTime(Time & time)
{
	bool valid = false;
	do {
	cout << "Enter the time in \"militay time\", (24-hour format),\n in the following order: HH:MM:SS, (hours, Minutes, Seconds).\n";
	cout << "Hours: ";
	cin >> time.hours;
	cout << "Minutes: ";
	cin >> time.minutes;
	cout << "Seconds: ";
	cin >> time.seconds;
	valid = isTimeValid(time);
	if(valid == false) {
		cout << "Invalid data.";
	}
	} while (valid != true);
}

bool isTimeValid(Time & time)
{
	if ( ((time.hours >= 0) && (time.hours <= MAX_HOURS))	&& 
		 ((time.minutes >= 0) && (time.minutes <= MAX_MINS)) && 
		 ((time.seconds >= 0) && (time.seconds <= MAX_SECS)) )	{
		return true;
	}
	else
		return false;
}

void addOneSecond(Time & time)
{
	time.seconds++;

	if (time.seconds > MAX_SECS) {
		time.seconds = 0;
		time.minutes++;
		
		if (time.minutes > MAX_MINS) {
			time.minutes = 0;
			time.hours++;

			if (time.hours > MAX_HOURS) {
				time.hours = 0;
			}
		}
	}
}

void displayTime(Time time)
{
	cout << setw(2);

	cout.fill('0');
	cout << "After adding one second, the time is " << time.hours << ":" << time.minutes << ":" << time.seconds << ".\n";
}