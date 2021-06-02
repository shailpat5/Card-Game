#include "CardFactory.h"

CardFactory::CardFactory() {
	Card* card;
	deck = new Deck();

	for (int i = 0; i < CARDS_BLUE; i++)
	{
		card = new Blue();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_CHILI; i++)
	{
		card = new Chili();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_STINK; i++)
	{
		card = new Stink();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_GREEN; i++)
	{
		card = new Green();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_SOY; i++)
	{
		card = new soy();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_BLACK; i++)
	{
		card = new black();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_RED; i++)
	{
		card = new Red();
		deck->push_back(card);
	}
	for (int i = 0; i < CARDS_GARDEN; i++)
	{
		card = new garden();
		deck->push_back(card);
	}
}

Deck CardFactory::generateDeck(istream& input)
{
	deck = new Deck();
	char cardID[128];
	input.getline(cardID, 128);

	int i = 0;
	while (cardID[i] != NULL && cardID[i] != ' ') {
		Card* card = NULL;

		if (cardID[i] == 'B') {
			card = new Blue();
		}
		else if (cardID[i] == 'C') {
			card = new Chili();
		}
		else if (cardID[i] == 'S') {
			card = new Stink();
		}
		else if (cardID[i] == 'G') {
			card = new Green();
		}
		else if (cardID[i] == 's') {
			card = new soy();
		}
		else if (cardID[i] == 'b') {
			card = new black();
		}
		else if (cardID[i] == 'R') {
			card = new Red();
		}
		else if (cardID[i] == 'g') {
			card = new garden();
		}

		deck->push_back(card);
		i++;
	}

	return *deck;
}

//variation of generateDeck
Card* CardFactory::generateCard(char cardID) {
	Card* card = NULL;
	
	while (cardID != NULL && cardID != ' ') {
		if (cardID == 'B') {
			card = new Blue();
		}
		else if (cardID == 'C') {
			card = new Chili();
		}
		else if (cardID == 'S') {
			card = new Stink();
		}
		else if (cardID == 'G') {
			card = new Green();
		}
		else if (cardID == 's') {
			card = new soy();
		}
		else if (cardID == 'b') {
			card = new black();
		}
		else if (cardID == 'R') {
			card = new Red();
		}
		else if (cardID == 'g') {
			card = new garden();
		}
	}

	return card;
}

Deck CardFactory::getDeck()
{
	//shuffle deck
	unsigned temp = (unsigned int)(chrono::system_clock::now().time_since_epoch().count());
	shuffle(deck->begin(), deck->end(), default_random_engine(temp));

	return *deck;
}

CardFactory* CardFactory::getFactory()
{
	static CardFactory cardFactory;
	return &cardFactory;
}