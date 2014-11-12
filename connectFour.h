#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
/*connectFour.h file
 *
 *Created by Bobby Huddleston
 *
 *February 2013
 */

#include "Board.h"

using namespace std;

//REQUIRES: User enters the value of a non-full column.
//MODIFIES: stdout
//EFFECTS: prints prompt to terminal.
//Returns value (0-6) of entered column.
int getMove();

//REQUIRES: An initialized Board
//EEFECTS: returns the "value" of the given board, negative favors 'O' and positive favors 'X'.
int Heuristic(Board board);

//REQUIRES: An initialized Board, depthLim>=1
//EFFECTS: returns the best possible move (0-6) for 'X'
int xPlayer(Board board,int depth,int bestValX,int bestVal0);

//REQUIRES: An initialized Board, depthLim>=1
//EFFECTS: returns the best possible move (0-6) for 'O'
int oPlayer(Board board,int depth,int bestValX,int bestVal0);

#endif
