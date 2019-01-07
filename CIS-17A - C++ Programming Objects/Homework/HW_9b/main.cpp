#include "Animal.h"
#include "Bird.h"
#include "Mammal.h"

bool isLarge(Animal & animal);

int main()
{
	Mammal cow("dairy cow", "black", 500);
	Bird bird("pelican", "gray", 8.5);

	bird.displayBird();
	cow.displayMammal();


	if (isLarge(bird))
		cout << "The animal weights at least 10 lbs.\n";
	else
	cout << "The animal doesn't weight more than 10lbs.\n";

	system("PAUSE");
	return 0;
}

bool isLarge(Animal & animal)
{
	if(animal.weight() >= 10)
		return true;
	else
		return false;
}