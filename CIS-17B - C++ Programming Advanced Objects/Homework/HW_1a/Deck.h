#ifndef DECK_H
#define DECK_H

class Deck
{
private:
	Card _cards[52];
	int _nextCardIndex;
public:
	Deck();
	~Deck();
	Card dealOneCard();
	void shuffle();
};
#endif