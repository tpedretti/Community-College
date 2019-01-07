#ifndef _BIRD_H_
#define _BIRD_H_

#include "Animal.h"

class Bird : protected Animal
{
private:
	string _featherColor;
public:
	Bird() {}
	Bird(string name, string featherColor, double weight) {
		_name = name;
		_weight = weight;
		_featherColor = featherColor;
	}
	~Bird() {}
	void displayBird() {
		cout << "Birds are vertebates in the Aves class. \n";
		cout << "This " << _name << " has " << _featherColor << " feathers and weights " << _weight << ",\n";
	}
};
#endif