#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>

using namespace std;

#include "Card.h"
#include "Deck.h"

int main()
{
	int numOfCards = 5;
	srand(time(0));
	Deck deck;
	int player = 1;
	int numPlayers = 0;

	cout << "Enter in number of players: ";
	cin >> numPlayers;

	Sleep(2000);
	system("CLS");

	while(player <= numPlayers) {
		deck.shuffle();
		cout << "Player #" << player << " hand is: ";
		for(int cardNum = 0; cardNum < numOfCards; cardNum++) {
			Card aCard = deck.dealOneCard();
			string suit = aCard.getSuit();
			string face = aCard.getFace();
			cout << face << suit << " ";
		}
		cout << endl;
		player++;
		Sleep(2000);
	}
	cout << "GAME OVER!\n";
	return 0;
}