#include "Date.h"
class People
{
private:
	string _name;
	string _quote;
	Date _brithdate;
public:
	People() {
		_name = "";
		_quote = "";
	}
	People(string name, string quote, int month, int day, int year)
		: _brithdate(month, day, year) {
			/*_name = name;
			_quote = quote;
			_brithdate.setDate(month, day, year);*/
	}
	~People() {}
	string setName(string name) {
		_name = name;
		return _name;
	}
	string setQuote(string quote) {
		_quote = quote;
		return _quote;
	}
	void setDate(int month, int day, int year) {
		_brithdate.setDate(month, day, year);
	}
	void displayPerson(string name, string quote) {
		cout << "NAME: " << _name << endl;
		cout << "QUOTATION: " << "\"" <<  _quote << "\"" << endl;
	}
	void displayDate(int month, int day, int year) {
		_brithdate.displayDate(month, day, year);
	}
};