#ifndef HAND
#define HAND

#include "./deck.h"

using namespace std;

class hand {
private:
	string* old_fan = NULL;
	int x = 0;
	static int y;

public:
	string* fan = NULL;

/*********************************************************************
** Function: hand
** Description: constructor
** Parameters: deck, number of cards in hand
** Pre-Conditions: N/A
** Post-Conditions: creates a hand
*********************************************************************/
	hand(const deck& d, int num);

/*********************************************************************
** Function: operator
** Description: creates a assigned operator
** Parameters: hand
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
	hand& operator= (const hand& s);

/*********************************************************************
** Function: num_in_hand
** Description: returns the number of cards in hand
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns # of cards in hand
*********************************************************************/
	int num_in_hand();

/*********************************************************************
** Function: deck_order
** Description: returns the order of deck
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: return the order of deck
*********************************************************************/
	int deck_order();

/*********************************************************************
** Function: first
** Description: inititalizes the pile
** Parameters: deck, pile
** Pre-Conditions: N/A
** Post-Conditions: a random card is placed onto the pile
*********************************************************************/
	void first(deck& dek, string& pile);

/*********************************************************************
** Function: draw
** Description: adds a card to the hand
** Parameters: deck
** Pre-Conditions: N/A
** Post-Conditions: hand has another card
*********************************************************************/
	void draw(const deck& dek);

/*********************************************************************
** Function: discard
** Description: removes a card from the hand
** Parameters: name of the card
** Pre-Conditions: N/A
** Post-Conditions: card given is no longer in hand
*********************************************************************/
	void discard(string str);

/*********************************************************************
** Function: print
** Description: prints the hand
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: hand is displayed
*********************************************************************/
	void print();

/*********************************************************************
** Function: destructor
** Description: deletes dynamic memory
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: all memory is cleared
*********************************************************************/
	~hand();
};

#endif // !HAND
