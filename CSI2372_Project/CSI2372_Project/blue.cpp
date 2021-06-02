#include "Card.h"

class Blue : public Card {

public:
	int getCardsPerCoin(int coins) {
		if (coins > 0 && coins <= 4) {
			switch (coins) {
			case 1:
				return 4;
				break;
			case 2:
				return 6;
				break;
			case 3:
				return 8;
				break;
			case 4:
				return 10;
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
		return "Blue";
	}

	void print(ostream& out) const {
		out << "B";
	}
};