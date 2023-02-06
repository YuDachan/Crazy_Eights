#ifndef DECK
#define DECK

#include "./card.h"

using namespace std;

class deck {

private:
	string str;
	int count = 0;
public:
	string dek[52];

/*********************************************************************
** Function: deck
** Description: create constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: a deck of cards is created
*********************************************************************/
	deck();

/*********************************************************************
** Function: shuffle
** Description: shuffles the deck
** Parameters: N/A
** Pre-Conditions: Deck is Created
** Post-Conditions: DEck is randomized
*********************************************************************/
	void shuffle();

/*********************************************************************
** Function: Print
** Description: Prints the deck in order
** Parameters: N/A
** Pre-Conditions: Deck is created
** Post-Conditions: Full deck is displayed
*********************************************************************/
	void print();

/*********************************************************************
** Function: use
** Description: returns a card
** Parameters: num
** Pre-Conditions: deck is created
** Post-Conditions: specific card in deck is returned
*********************************************************************/
	string use(int num);

/*********************************************************************
** Function: card& operator
** Description: N/A
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
	deck& operator= (const deck&);

/*********************************************************************
** Function: copy constructor
** Description: N/A
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
	deck(const deck&);

/*********************************************************************
** Function: destructor
** Description: N/A
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
	~deck();
};
#endif // !1
