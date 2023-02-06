#include "./deck.h"

using namespace std;

	deck::deck() {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 13; j++) {
				card cards(i, j);
				cards.classify();
				str = cards.create_card();
				dek[count] = str;
				count++;
			}
		}
	}

	void deck::shuffle() {
		string temp_str;
		int x = 0, w = 0;

		for (int i = 0; i < 100; i++) {
			w = (rand() % 52);
			x = (rand() % 52);
			temp_str = dek[w];
			dek[w] = dek[x];
			dek[x] = temp_str;
		}
	}

	void deck::print() {
		for (int i = 0; i < 52; i++) {
			cout << dek[i] << endl;
		}
	}

	string deck::use(int num) {
		return dek[num];
	}

	deck& deck::operator= (const deck&) {
	}

	deck::deck(const deck&) {
	}

	deck::~deck() {
	}