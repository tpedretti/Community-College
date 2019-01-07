#ifndef _MAMMAL_H_
#define _MAMMAL_H_


#include "Animal.h"

class Mammal : protected Animal
{
private:
	string _hairColor;
public:
	Mammal() {}
	Mammal(string name, string hairColor, double weight) {
		_name = name;
		_weight = weight;
		_hairColor = hairColor;
	}
	~Mammal() {}
	void displayMammal() {
		cout << "Mammals are vertebrates in the Mammalia class. \n";
		cout << "This " << _hairColor << " " << _name << " weights " << _weight << ".\n";
	}
};
#endif