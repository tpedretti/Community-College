#include "Cat.h"

void Cat::setWeight(float weight) {
	_weight = weight;
}
float Cat::weight() {
	return _weight;
}

void Cat::setColor(string color) {
	_color = color;
}
string Cat::color() {
	return _color;
}

void Cat::setName(string name) {
	_name = name;
}
string Cat::name() {
	return _name;
}