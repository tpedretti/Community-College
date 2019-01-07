#include <cassert>
#include <string>
#include <algorithm>

using namespace  std;

#include "Card.h"
#include "Deck.h"

Deck::Deck() {
	for(int i = 0; i < 52; i++) {
		_cards[i] = Card(i);
	}
	shuffle();
	_nextCardIndex = 0;
}
Deck::~Deck() {}
Card Deck::dealOneCard() {
	assert(_nextCardIndex >= 0 && _nextCardIndex < 52);
	return _cards[_nextCardIndex++];
}
void Deck::shuffle() {
	for(int i = 0; i < 52; i++) {
		int randNum = i + (rand() % (52 - i));
		swap(_cards[i], _cards[randNum]);
	}
	_nextCardIndex = 0;
}