#include "Action Toy.h"
#include "Game.h"

void calcRetail(Toy & toy);
int main()
{
	 aToy toyA("China", 4, 'M');
	 Game aGame("Taiwan", 5, "Chess set");

	 toyA.displayToy();
	 calcRetail(toyA);
	 toyA.showAge();

	 aGame.displayGame();
	 calcRetail(aGame);
	 aGame.showAge();

	 system("PAUSE");
	return 0;
}
void calcRetail(Toy & toy)
{
	cout << "RETAIL: " << (toy.getWholeSale() * 2.0) << endl;
}