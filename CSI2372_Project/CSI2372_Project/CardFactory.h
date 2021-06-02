#ifndef CardFactory_h
#define CardFactory_h

#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "Deck.h"
#include "Card.h"
#include "blue.cpp"
#include "chili.cpp"
#include "stink.cpp"
#include "green.cpp"
#include "soy.cpp"
#include "black.cpp"
#include "red.cpp"
#include "garden.cpp"

class Deck;

class CardFactory {
public:
	static CardFactory* getFactory();
	Deck getDeck();
	Card* generateCard(char);
	Deck generateDeck(istream&);

private:
	Deck* deck;

	//constructors
	CardFactory(const CardFactory&);
	CardFactory();
};
#endif