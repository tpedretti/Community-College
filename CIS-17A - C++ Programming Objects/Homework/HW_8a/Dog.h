#include <iostream>
#include <string>
#include <ostream>

using namespace std;

//ostream & operator << (ostream & stream, Dog & yourDog);
class Dog
{
private:
	string _name;
	float _weight;
	int _age;
public:
	Dog(string name, float weight, int age) {
		_name = name;
		_weight = weight;
		_age = age;
	}
	~Dog() {}
	void displayDog() {
		cout << "NAME: " << _name << endl;
		cout << "WEIGHT: " << _weight << " pounds. \n";
		cout << "AGE: " << _age << " years old. \n";
	}
	int operator >= (int age) {
		return _age;
	}
	bool operator < (Dog & myDog) {
		return (_weight < myDog._weight);
	}
	bool operator == (Dog & yourDog) {
		return (_name == yourDog._name);
		/*if(_name == yourDog._name) {
			return true;
		}
		else
			return false;
		*/
	}
	friend ostream & operator << (ostream & stream, Dog & yourDog) {
		stream << "NAME: " << yourDog._name << endl;
		stream << "WEIGHT: " << yourDog._weight << endl;
		stream << "AGE: " << yourDog._age << endl;
		return stream;
	}
};