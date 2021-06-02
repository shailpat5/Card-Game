#include "Card.h"

class Chili : public Card {

public:
	int getCardsPerCoin(int coins) {
		if (coins > 0 && coins <= 4) {
			switch (coins) {
			case 1:
				return 3;
				break;
			case 2:
				return 6;
				break;
			case 3:
				return 8;
				break;
			case 4:
				return 9;
				break;
			default:
				return 0;
				break;
			}
		}
		else {
			cout << "The number of coins provided is invalid.";
			return 0;
		}
	}

	string getName() {
		return "Chili";
	}

	void print(ostream& out) const {
		out << "C";
	}
};