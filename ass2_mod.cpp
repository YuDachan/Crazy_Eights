/******************************************************
** Program: Assignment 2
** Author: Dachan Yu
** Date: 4/25/2021
** Description: A game of Crazy Eights
** Input: Various strings
** Output: Displays the game
******************************************************/

#include <iostream>
#include <ctime>
#include <string>
#include "./func_ass2.h"

using namespace std;

int main() {
	srand(time(NULL));
	string rank, suit, pile;
	int y = 0;
	int CPUtotal = 0, total = 0;

	do {
		deck d;
		d.shuffle();
		hand s(d, 7), CPU(d, 7);
		s.first(d, pile);
		gameplay(s, CPU, d, pile, suit, rank);
		points(s, total);
		points(CPU, CPUtotal);
		cout << "player points: " << total << endl;
		cout << "CPU points: " << CPUtotal << endl;
	} while ((total < 100) && (CPUtotal < 100));
	if (total > CPUtotal) {
		cout << endl;
		cout << "PLayer Lose!" << endl;
		cout << endl;
	}
	else if (CPUtotal > total) {
		cout << endl;
		cout << "Player win" << endl;
		cout << endl;
	}

	return 0;
}