#include <iostream>
#include <string>
#include <boost\regex.hpp>

using namespace std;

bool validate(const string&, const string&);
string inputData(const string&, const string&);

int main()
{
	string lastName = inputData("last name", "[A-Z][a-zA-Z]*");
	string firstName = inputData("first name", "[A-Z][a-zA-Z]*");
	string address = inputData("address", "[0-9]+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-z]+)");
	string city = inputData("city", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
	string state = inputData("state", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
	string zipCode = inputData("zip code", "\\d{5}");
	string phoneNumber = inputData("phone number", "[1-9]\\d{2}-[1-9]\\d{2}-\\d{4}");

	cout << "\nValidated Data\n\n";
	cout << "Last Name: " << lastName << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Address: " << address << endl;
	cout << "City: " << city << endl;
	cout << "State: " << state << endl;
	cout << "Zip Code: " << zipCode << endl;
	cout << "Phone Number: " << phoneNumber << endl;

	system("PAUSE");
	return 0;
}

string inputData(const string &fieldName, const string &expression) {
	string data;
	cout << "Enter " << fieldName << ": ";
	getline(cin, data);
	while(!(validate(data, expression))) {
		cout << "Invalid " << fieldName << ".\n";
		cout << "Enter " << fieldName << ": ";
		getline(cin, data);
	}
	return data;
}

bool validate(const string &data, const string &expression) {
	boost::regex validationExpression = boost::regex(expression);
	return boost::regex_match(data, validationExpression);
}