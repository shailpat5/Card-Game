#include "Card.h"

class black : public Card {

public:
	int getCardsPerCoin(int coins) {
		if (coins > 0 && coins <= 4) {
			switch (coins) {
			case 1:
				return 2;
				break;
			case 2:
				return 4;
				break;
			case 3:
				return 5;
				break;
			case 4:
				return 6;
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
		return "black";
	}

	void print(ostream& out) const {
		out << "b";
	}
};