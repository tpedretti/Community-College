#ifndef CARD_H
#define CARD _H

class Card
{
private:
	int _card;
	static const string CARD_FACES[];
	static const string CARD_SUITS[];
public:
	Card();
	Card(int card);
	~Card();
	string getSuit() const;
	string getFace()  const;
};
#endif
