#include "Bird.h"
#include "Mammal.h"

int main()
{
	Mammal cow("dairy cow", "black", 500);
	Bird bird("pelican", "gray", 8.5);

	bird.displayBird();
	cow.displayMammal();


	system("PAUSE");
	return 0;
}