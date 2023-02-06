#include "./func_ass2.h"

using namespace std;

bool check(string str, hand& han, int num) {
	for (int i = 0; i < num; i++) {
		if (str == han.fan[i]) {
			return true;
		}
	}

	return false;
}

bool rule_check(string str, string suit, string rank) {
	if (str.find(rank) != string::npos) {
		return true;
	}
	if (str.find(suit) != string::npos) {
		return true;
	}

	return false;
}

bool CPU_check(hand& han, string rank, string suit, int& z) {
	for (int i = 0; i < han.num_in_hand(); i++) {
		if (han.fan[i].find(suit) != string::npos) {
			z = i;
			return true;
		}
		else if (han.fan[i].find(rank) != string::npos) {
			z = i;

			return true;
		}

	}
	return false;
}

void second_convert(string pile, string& suit, string& rank) {
	if (pile.find("King") != string::npos) {
		rank = "King";
	}
	else if (pile.find("Queen") != string::npos) {
		rank = "Queen";
	}
	else if (pile.find("Jack") != string::npos) {
		rank = "Jack";
	}
	if (pile.find("Diamonds") != string::npos) {
		suit = "Diamonds";
	}
	else if (pile.find("Clubs") != string::npos) {
		suit = "Clubs";
	}
	else if (pile.find("Spades") != string::npos) {
		suit = "Spades";
	}
	else if (pile.find("Hearts") != string::npos) {
		suit = "Hearts";
	}
}

void convert(string pile, string& suit, string& rank) {
	if (pile.find("Ace") != string::npos) {
		rank = "Ace";
	}
	else if (pile.find("2") != string::npos) {
		rank = "2";
	}
	else if (pile.find("3") != string::npos) {
		rank = "3";
	}
	else if (pile.find("4") != string::npos) {
		rank = "4";
	}
	else if (pile.find("5") != string::npos) {
		rank = "5";
	}
	else if (pile.find("6") != string::npos) {
		rank = "6";
	}
	else if (pile.find("7") != string::npos) {
		rank = "7";
	}
	else if (pile.find("8") != string::npos) {
		rank = "8";
	}
	else if (pile.find("9") != string::npos) {
		rank = "9";
	}
	else if (pile.find("10") != string::npos) {
		rank = "10";
	}
	second_convert(pile, suit, rank);
}

void mod(hand& han, string str, string& pile, string& suit, string& rank, int& z) {
	if (rule_check(str, suit, rank)) {
		han.discard(str);
		pile = str;
		z = 1;
	}
	else {
		cout << "poor input" << endl;
	}
}

void explain(hand& han, string pile) {
	cout << endl;
	cout << "pile: " << pile << endl;
	cout << "cards left in deck: " << 52 - han.deck_order() << endl;
	cout << endl;
	cout << "card must be spelled exactly to use" << endl;
	cout << "to draw type: Draw" << endl;
}

void eight(hand& han, string& suit, string& rank, string& pile) {
	string str;
	do {
		rank = "8";
		cout << endl;
		cout << "what suit would you like?" << endl;
		cout << "[1]Diamonds [2]Clubs [3]Hearts [4]Spades" << endl;
		getline(cin, str);
		if (str == "1") {
			pile = "8 of Diamonds";
			suit = "Diamonds";
		}
		else if (str == "2") {
			pile = "8 of Clubs";
		}
		else if (str == "3") {
			pile = "8 of Hearts";
			suit = "Hearts";
		}
		else if (str == "4") {
			pile = "8 of Spades";
			suit = "Spades";
		}
		else {
			cout << "poor input" << endl;
		}
	} while ((str != "1") && (str != "2") && (str != "3") && (str != "4"));
}

void hand_discard(hand& han, deck& dek, string& suit, string& rank, string& pile) {
	int x = 1, z = 0;
	string str;

	do {
		explain(han, pile);
		getline(cin, str);
		cout << endl;
		if (str == "Draw") {
			han.draw(dek);
			han.print();
		}
		else if (check(str, han, han.num_in_hand())) {
			if (str.find("8") != string::npos) {
				eight(han, pile, suit, rank);
				han.discard(str);
				break;
			}
			mod(han, str, pile, suit, rank, z);
			if (z == 1) {
				break;
			}
		}
		else {
			cout << "poor input" << endl;
		}

	} while (han.deck_order() != 52);
}

void use(hand& han, deck& dek, string& pile, string& suit, string& rank) {
	int x = 1, y = han.num_in_hand();

	convert(pile, suit, rank);
	hand_discard(han, dek, suit, rank, pile);

}

void points(hand& han, int& total) {
	string rank, suit;
	int x = 0;

	for (int i = 0; i < han.num_in_hand(); i++) {
		convert(han.fan[i], suit, rank);
		
		if (rank == "8") {
			x = 50;
			total = total + x;
		}
		else if (rank == "Ace") {
			x = 1;
			total = total + x;
		}
		else if (rank == "Jack") {
			x = 10;
			total = total + x;
		}
		else if (rank == "Queen") {
			x = 10;
			total = total + x;
		}
		else if (rank == "King") {
			x = 10;
			total = total + x;
		}
		else if (isalpha(rank[0]) == false) {
			x = stoi(rank);
			total = total + x;
		}

	}
}

void CPU_ctrl(hand& han, deck& dek, string& pile, string& suit, string& rank) {
	int z = 0;

	convert(pile, suit, rank);
	do {
		if (CPU_check(han, rank, suit, z)) {
			pile = han.fan[z];
			han.discard(han.fan[z]);
			break;
		}
		else {
			han.draw(dek);
		}

	} while (han.deck_order() != 52);
}

void gameplay(hand& s, hand& CPU, deck& d, string& pile, string& suit, string& rank) {
	int CPUtotal = 0, total = 0;

	do {
		if ((s.deck_order() < 52) && (s.num_in_hand() > 0) && (CPU.num_in_hand() > 0)) {
			cout << "player" << endl;
			s.print();
			cout << endl;
			use(s, d, pile, suit, rank);
			cout << endl;
		}
		if ((s.deck_order() < 52) && (s.num_in_hand() > 0) && (CPU.num_in_hand() > 0)) {
			cout << "CPU" << endl;
			for (int i = 0; i < CPU.num_in_hand(); i++) {
				cout << "XXXXXXX" << endl;
			}
			cout << endl;
			CPU_ctrl(CPU, d, pile, suit, rank);
		}
	} while ((s.deck_order() != 52) && (s.num_in_hand() > 0) && (CPU.num_in_hand() > 0));
}