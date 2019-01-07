#include "Dog.h"

int main()
{
	Dog myDog("Spot", 5.5, 3);
	Dog yourDog("Jack", 4.5, 3);

	if(myDog >= 2)
		cout << "The dog is at least 2 years old.\n";
	else
		cout << "The dog is less than 2 years old.\n";
	if (yourDog < myDog)
		cout << "Your dog weights less than my dog.\n";
	else
		cout << "Your dog doesn't weight less than my dog.\n";
	if (myDog == yourDog)
		cout << "They have the same name. \n";
	else
		cout << "They don't have the same name.\n";
	cout << yourDog << endl;


	system("PAUSE");
	return 0;
}