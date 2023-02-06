#include "./hand.h"

using namespace std;



	hand::hand(const deck& d, int num) {
		fan = new string[num];
		x = num;
		for (int i = 0; i < num; i++) {
			fan[i] = d.dek[i + y];
		}
		y = y + num;
	}

	hand& hand::operator= (const hand& s) {

	}

	int hand::num_in_hand() {
		return x;
	}

	int hand::deck_order() {
		int z = y;
		return z;
	}

	void hand::first(deck& dek, string& pile) {
		pile = dek.dek[y];
		y++;
	}

	void hand::draw(const deck& dek) {
		old_fan = new string[x];
		for (int i = 0; i < x; i++) {
			old_fan[i] = fan[i];
		}
		delete[] fan;
		fan = new string[x + 1];
		for (int i = 0; i < x; i++) {
			fan[i] = old_fan[i];
		}
		fan[x] = dek.dek[y];
		y++;
		x++;
		delete[] old_fan;

	}

	void hand::discard(string str) {

		old_fan = new string[x];
		for (int i = 0; i < x; i++) {
			if (str == fan[i]) {
				for (int j = i; j < x - 1; j++) {
					old_fan[j] = fan[j + 1];
				}
				break;
			}
			else {
				old_fan[i] = fan[i];
			}
		}

		delete[] fan;
		x--;
		fan = new string[x];
		for (int i = 0; i < x; i++) {
			fan[i] = old_fan[i];
		}
		delete[] old_fan;
	}

	void hand::print() {
		for (int i = 0; i < x; i++) {
			cout << fan[i] << endl;
		}
	}

	hand::~hand() {
		delete[] fan;
	}


int hand::y = 0;