#include "Clocktype.h"

int main()
{
	ClockType myClock;
	ClockType yourClock;
	ClockType myOtherClock(0, 0, 0);

	myClock.setTime(3, 30, 0);
	yourClock.setTime(10, 0, 15);

	cout << "The time on my clock is: ";
	myClock.displayPrintTime();

	cout << "The time on your clock is: ";
	yourClock.displayPrintTime();

	cout << "The times of my clock and your clock are ";
	if(myClock.areTimesEqual(myClock, yourClock)) {
		cout << " equal. \n";
	}
	else
		cout << " not equal. \n";

	cout << "The time on my other clock is: ";
	myOtherClock.displayPrintTime();

	cout << endl;

	cout << "I am going to add 1 minute and 1 second to my other clock.";
	cout << endl;

	myOtherClock.incrementSeconds();
	myOtherClock.incrementMinutes();

	cout << "the time on my other clock is: ";
	myOtherClock.displayPrintTime();

	cout << endl;

	system("PAUSE");
	return 0;
}