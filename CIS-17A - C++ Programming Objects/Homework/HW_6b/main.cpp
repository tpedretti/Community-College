#include "Cat.h"

int main()
{
	string name;
	float catWeight;
	string color;

	Cat fluffy;
	Cat tom;
	Cat kitty;
	Cat meow;

	cout << "So you have three cats...\n";
	cout << "Descride Fluffy. What does she weight? ";
	cin >> catWeight;
	cin.ignore();
	cout << "What color is she? ";
	getline(cin, color);

	fluffy.setWeight(catWeight);
	fluffy.setColor(color);
	cout << endl;

	cout << "Descride Tom. What does he weight? ";
	cin >> catWeight;
	cin.ignore();
	cout << "What color is he? ";
	getline(cin, color);

	tom.setWeight(catWeight);
	tom.setColor(color);
	cout << endl;

	cout << "Descride Kitty. What does she weight? ";
	cin >> catWeight;
	cin.ignore();
	cout << "What color is she? ";
	getline(cin, color);

	kitty.setWeight(catWeight);
	kitty.setColor(color);
	cout << endl;

	cout << "Fluffly "; 
	fluffy.displayCatInfo(); cout << endl;
	cout << "Tom "; 
	tom.displayCatInfo(); cout << endl;
	cout << "Kitty "; 
	kitty.displayCatInfo(); cout << endl;

	meow.displayMeow();

	system("PAUSE");
	return 0;
}