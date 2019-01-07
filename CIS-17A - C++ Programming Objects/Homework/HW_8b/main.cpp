#include "car.h"


int main()
{
	Car myCar;
	Car yourCar("Toyota", 2007);

	cout << "My car:\n";
	myCar.displayCar();

	cout << "Your Car:\n";
	yourCar.displayCar();

	myCar.setCar("Ford", 2002);
	cout << "My new Car:\n";
	myCar.displayCar();

	if (myCar == yourCar)
		cout << "The cars are the same!\n";
	else
		cout << "The cars are not the same!\n";

	myCar.getCount();

	system("PAUSE");
	return 0;
}