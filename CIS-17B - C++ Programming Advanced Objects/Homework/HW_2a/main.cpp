#include <iostream>
#include <string>
#include <boost\regex.hpp>

using namespace std;

int main()
{
	boost::regex expression( "J.*\\d[0-35-9]-\\d\\d-\\d\\d" );

	string string1 = "Jane's Birthday is 05-12-75\n"
					 "Dave's Birthday is 11-04-68\n"
					 "John's Birthday is 04-28-73\n"
					 "Joe's Birthday is 12-17-77\n";

	boost::smatch match;

	while (boost::regex_search(string1, match, expression, boost::match_not_dot_newline)) {
		cout << match << endl;
		string1 = match.suffix();
		//cout << "TEST" << endl;
	}
	system("PAUSE");
	return 0;
}