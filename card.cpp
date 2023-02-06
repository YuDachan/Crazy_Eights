#include "./card.h"

using namespace std;

void card::icard() {
	y = 0;
	x = 0;
}

card::card(int suit, int rank) {
	y = rank;
	x = suit;
}

void card::classify() {
	if (x == 1) {
		suit = "Diamonds";
	}
	else if (x == 2) {
		suit = "Clubs";
	}
	else if (x == 3) {
		suit = "Hearts";
	}
	else if (x == 4) {
		suit = "Spades";
	}

	if ((y > 1) && (y <= 10)) {
		rank = to_string(y);
	}
	else if (y == 1) {
		rank = "Ace";
	}
	else if (y == 11) {
		rank = "Jack";
	}
	else if (y == 12) {
		rank = "Queen";
	}
	else if (y == 13) {
		rank = "King";
	}
}

string card::create_card() {
	card_info = rank + " of " + suit;
	return card_info;
}

card& card::operator= (const card&) {
}

card::card(const card&) {
}

card::~card() {
}