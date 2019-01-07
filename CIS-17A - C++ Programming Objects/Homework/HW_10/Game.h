#ifndef _GAME_H_
#define _GAME_H_

#include "Toy.h"

class Game : public Toy
{
private:
	string _type;
public:
	Game() {
		_mfgr ="";
		_wholesale = 0;
		_type = "";
	}
	Game(string mfgr, double sale, string type) {
		_mfgr = mfgr;
		_wholesale = sale;
		_type = type;
	}
	~Game() {}
	void displayGame() {
		cout << "TYPE: " << _type << endl;
		cout << "MFGR: " << _mfgr << endl;
		cout << "WHOLESALE: " << _wholesale << endl;
	}
	virtual void showAge() {
		cout << "The appropriate age for this toy is 12 years and older.\n\n";
	}
	friend void calcRetail(Toy & toy);
};
#endif