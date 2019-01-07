#include <iostream>
#include <string>

using namespace std;

#ifndef _TOY_H_
#define _TOY_H_

class Toy
{
protected:
	string _mfgr;
	double _wholesale;
public:
	Toy() {
		_mfgr ="";
		_wholesale = 0;
	}
	Toy(string mfgr, double sale) {
		_mfgr = mfgr;
		_wholesale = sale;
	}
	~Toy() {}
	double getWholeSale() {
		return _wholesale;
	}
	virtual void showAge() {}
	friend void calcRetail(Toy & toy);
};
#endif