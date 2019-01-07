#ifndef _ACTION_TOY_H_
#define _ACTION_TOY_H_

#include "Toy.h"

class aToy : public Toy
{
private:
	char _gender;
public:
	aToy() {
		_mfgr = "";
		_wholesale = 0;
	}
	aToy(string mfgr, double sale, char gender) {
		_mfgr = mfgr;
		_wholesale = sale;
		_gender = gender;
	}
	~aToy() {}
	void displayToy() {
		cout << "GENDER: " << _gender << endl;
		cout << "MFGR: " << _mfgr << endl;
		cout << "WHOLESALE: " << _wholesale << endl;
	}
	virtual void showAge() {
		cout << "The appropriate age for this toy is 6 to 10 years old.\n\n";
	}
	friend void calcRetail(Toy & toy);
};
#endif