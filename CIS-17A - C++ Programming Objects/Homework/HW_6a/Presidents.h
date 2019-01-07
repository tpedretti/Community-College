#include <iostream>
#include <string>

using namespace std;

class Presidents
{
private:
	int _number;
	string _name;
	string _quote;
public:
	Presidents() {}
	//Presidents(int number, string name, string quote);
	~Presidents() {}
	void setNumber(int number);
	int getNumber();
	void setName(string name);
	string getName();
	void setQuote(string quote);
	string getQuote();
	void displayPresidents() {
		cout << _name << ", " << _number << "th president, said: " << _quote << "." << endl;
	}
};