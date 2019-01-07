#include <iostream>
#include <string>
#include <boost\regex.hpp>

using namespace std;

int main()
{
	string userEnter = "";
	boost::regex expression("@.*.com");
	
	cout << "Enter in a .com username: ";
	getline(cin, userEnter);

	boost::smatch match;

	if(boost::regex_search(userEnter, match, expression, boost::match_not_dot_newline)) {
		cout << match << endl;
		userEnter = match.suffix();
		cout << "That is a .com email\n";
	}
	else {
		cout << "The email you used isn't a .com email.\n";
	}
	system("PAUSE");
	return 0;
}