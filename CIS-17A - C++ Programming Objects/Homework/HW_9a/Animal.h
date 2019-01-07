#include <iostream>
#include <string>

using namespace std;

#ifndef _ANIMAL_H_
#define _ANIMAL_H_


class Animal
{
protected:
	string _name;
	double _weight;
public:
	Animal() {}
	Animal(string name, double weight) {
		_name = name;
		_weight = weight;
	}
	~Animal() {}
};
#endif