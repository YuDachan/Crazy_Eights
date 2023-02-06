#ifndef FUNC
#define FUNC

#include "./hand.h"

using namespace std;

/*********************************************************************
** Function: check
** Description: checks if user input mathces card in hand
** Parameters: string, hand, number of cards in hand
** Pre-Conditions: user inputs a string
** Post-Conditions: return ture or false depending if card is in hand
*********************************************************************/
bool check(string str, hand& han, int num);

/*********************************************************************
** Function: rule check
** Description: checks if card user place matches suit/rank of card in pile
** Parameters: pile, suit, rank
** Pre-Conditions: user enters a string
** Post-Conditions: reutrn true or false depending on input
*********************************************************************/
bool rule_check(string str, string suit, string rank);

/*********************************************************************
** Function: CPU_check
** Description: check if there are any cards in CPU hand can be played
* and determine which card can be played
** Parameters: hand, rank, string, int
** Pre-Conditions: N/A
** Post-Conditions: return true if card can be play else false
*********************************************************************/
bool CPU_check(hand& han, string rank, string suit, int& z);

/*********************************************************************
** Function: second_convert
** Description: splits the card into rank and suit pt.2
** Parameters: pile, suit, rank
** Pre-Conditions: N/A
** Post-Conditions: A card in the pile is classified
*********************************************************************/
void second_convert(string pile, string& suit, string& rank);

/*********************************************************************
** Function: Convert
** Description: splits the card into rank and suit
** Parameters: pile, suit, rank
** Pre-Conditions: N/A
** Post-Conditions: A card in the pile is classified
*********************************************************************/
void convert(string pile, string& suit, string& rank);

/*********************************************************************
** Function: mod
** Description: discards card and replaces pile
** Parameters: hand, string, pile, suit, rank, int
** Pre-Conditions: pass all bools and must not be an eight
** Post-Conditions: pile is replaced, card is removed from hand
*********************************************************************/
void mod(hand& han, string str, string& pile, string& suit, string& rank, int& z);

/*********************************************************************
** Function: explain
** Description: explain the rules when interacting with system
** Parameters: hand, pile
** Pre-Conditions: N/A
** Post-Conditions: pile, rule are displayed
*********************************************************************/
void explain(hand& han, string pile);

/*********************************************************************
** Function: eight
** Description: apply the rules of crazy eights when an eight is played
** Parameters: hand, suit, rank, pile, deck
** Pre-Conditions: N/A
** Post-Conditions: Ask user for a suit
*********************************************************************/
void eight(hand& han, string& suit, string& rank, string& pile);

/*********************************************************************
** Function: hand discard
** Description: playing a card into the pile
** Parameters: hand, deck, suit, rank, pile
** Pre-Conditions: N/A
** Post-Conditions: A card is played by user and pile changed based on
* card played by user
*********************************************************************/
void hand_discard(hand& han, deck& dek, string& suit, string& rank, string& pile);

/*********************************************************************
** Function: use
** Description: begins the process for player to play card
** Parameters: hand, deck, suit, rank, pile
** Pre-Conditions: N/A
** Post-Conditions: cards discard begins
*********************************************************************/
void use(hand& han, deck& dek, string& pile, string& suit, string& rank);

/*********************************************************************
** Function: points
** Description: count points based off of rules of crazy eights
** Parameters: hand, total points
** Pre-Conditions: N/A
** Post-Conditions: total points are calculated based off the hand of user/CPU
*********************************************************************/
void points(hand& han, int& total);

/*********************************************************************
** Function: CPU_ctrl
** Description: makes the CPU play a card or draw depending on hand
** Parameters: hand, deck, pile, suit, rank
** Pre-Conditions: N/A
** Post-Conditions: CPU does a action
*********************************************************************/
void CPU_ctrl(hand& han, deck& dek, string& pile, string& suit, string& rank);

/*********************************************************************
** Function: Gameplay
** Description: orders the events of the game
** Parameters: hand of user, hand of CPU, pile, suit, rank
** Pre-Conditions: N/A
** Post-Conditions: game is played
*********************************************************************/
void gameplay(hand& s, hand& CPU, deck& d, string& pile, string& suit, string& rank);

#endif // !FUNC
