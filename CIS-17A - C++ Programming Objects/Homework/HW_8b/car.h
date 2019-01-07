#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string _model;
	int _year;
	static int _carCount;
public:
	Car() {
		_model = "";
		_year = 0;
		_carCount++;
	}
	Car(string model, int year) {
		_model = model;
		_year = year;
		_carCount++;
	}
	~Car() {}
	void setCar(string model, int year) {
		_model = model;
		_year = year;
	}
	static int getCount() {
		cout << _carCount << " cars have have been declared.\n";
		return _carCount;
	}
	void displayCar() {
		cout << "MODEL: " << _model << endl;
		cout << "YEAR: " << _year << endl;
	}
	bool operator == (Car & yourCar) {
		return (_model == yourCar._model);
	}
};