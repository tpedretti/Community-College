#include <iostream>
#include <string>

using namespace std;

class Cat
{
private:
	string _name;
	float _weight;
	string _color;
public:
	Cat() {}
	~Cat() {}
	void setName(string name);
	string name();
	void setWeight(float weight);
	float weight();
	void setColor(string color);
	string color();
	void displayCatInfo() {
		cout << "weights " << _weight << " pounds and is " << _color << ".\n";
	}
	void displayMeow() {
		cout << "Fluffy says: MEOW!\n";
		cout << "Tom says: MEOW!\n";
		cout << "Kitty says: MEOW!\n";
	}
};
