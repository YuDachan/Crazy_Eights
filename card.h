#ifndef CARD
#define CARD

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class card {
private:
	int x, y;

public:
	string suit, rank, card_info;

	/*********************************************************************
	** Function:  icard
	** Description:  initialize class
	** Parameters:   none
	** Pre-Conditions:  none
	** Post-Conditions:  int members set 0
	*********************************************************************/
	void icard();

	/*********************************************************************
	** Function: card
	** Description: create constructor
	** Parameters: suit, rank
	** Pre-Conditions: none
	** Post-Conditions: stores integers
	*********************************************************************/
	card(int suit, int rank);

	/*********************************************************************
	** Function: classify
	** Description: turns integers into cards
	** Parameters: none
	** Pre-Conditions: constructor with int ares created
	** Post-Conditions: numbers are correlated with a suit or rank
	*********************************************************************/
	void classify();

	/*********************************************************************
	** Function: create card
	** Description: creates the full card
	** Parameters: none
	** Pre-Conditions: constructor with int are created
	** Post-Conditions: a playing card is created
	*********************************************************************/
	string create_card();

	/*********************************************************************
	** Function: card& operator
	** Description: N/A
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	card& operator= (const card&);

	/*********************************************************************
	** Function: card
	** Description: N/A
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	card(const card&);

	/*********************************************************************
	** Function: ~card
	** Description: N/A
	** Parameters: N/A
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/
	~card();

};


#endif // !CARD
