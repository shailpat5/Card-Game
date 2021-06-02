#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>

using namespace std;

const int CARDS_BLUE = 20;
const int CARDS_CHILI = 18;
const int CARDS_STINK = 16;
const int CARDS_GREEN = 14;
const int CARDS_SOY = 12;
const int CARDS_BLACK = 10;
const int CARDS_RED = 8;
const int CARDS_GARDEN = 6;

//base abstract class
class Card {
public:
	virtual int getCardsPerCoin(int) = 0;

	virtual string getName() = 0;

	friend ostream& operator << (ostream& output, const Card& card) {
		card.print(output);
		return output;
	};
	friend ostream& operator << (ostream& output, const Card* card) {
		output << (*card);
		return output;
	};

	//using friend function
	virtual void print(ostream&) const = 0;
};

#endif