
#ifndef BOARD_H
#define BOARD_H
/*Board.h file
 *
 *Created by Bobby Huddleston
 *
 *February 2013
 */

using namespace std;




class Board { 
/* Creates the object "Board" which contains all the moves made by the player and the AI.The Board object 
is also used by the AI to check possible future boards and their relative values. The Class can check to 
see who has won on if the board is full and is used to make all moves by both the player and AI */
	private:

	/*****Class Private Variables*****/
		int node[6][7];

	/*****Class Private Functions*****/
		bool rowWin(int row, int player);
		bool colWin(int col, int player);
		bool forwardDiagWin(int player);
		bool backwardDiagWin(int player);

	public:
	
	/*****Class Functions*****/
		Board ();
		void printBoard();
		bool makeMove( int column, int move);
		bool isFull();
		int isWin();
		void resetBoard();
		int getNode(int i,int j);

};

#endif
