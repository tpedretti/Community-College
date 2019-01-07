#include "Presidents.h"

/*Presidents::Presidents() {
	_number = 0;
	_name = "";
	_quote = "";
}
Presidents::~Presidents() {}*/
void Presidents::setNumber(int number) {
	_number = number;
}
int Presidents::getNumber() {
	return _number;
}

void Presidents::setName(string name) {
	_name = name;
}
string Presidents::getName() {
	return _name;
}

void Presidents::setQuote(string quote) {
	_quote = quote;
}
string Presidents::getQuote() {
	return _quote;
}

//void Presidents::displayPresidents(int number, string name, string quote) {}