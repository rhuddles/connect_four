
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib> 
#include "Board.h"

using namespace std;


	Board::Board(){ //Initilizes a new Board with empty cells

		for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			node[i][j]=0;
		}}
	}

	void Board::resetBoard(){ //Clears Board and fills with empty cells
		for(int i=0;i<6;i++){
	    	for(int j=0;j<7;j++){
			node[i][j]=0;
		}}	

		return;
	}

	int Board::getNode(int i, int j){
		return node[i][j];
	}
 	void Board::printBoard(){ //prints out a copy of the current board
		char move;
		cout << " 0 1 2 3 4 5 6"<<endl;    
   		for(int i=0;i<6;i++){
    		for(int j=0;j<7;j++){
			if(node[i][j]==0)
				move= ' ';
			else if(node[i][j]==1)
				move= 'X';
			else if(node[i][j]==2)
				move= 'O';

     		 	cout<< "|"<< move;
    		}
		cout<<"|"<<endl;	
		}
		cout<<endl<<"--------------------------"<<endl;
   		
		return;
  	}

	 bool Board::makeMove(int column, int move){ //Plays move into the given column.
	       	if(column < 0 || column > 6){
			cout<< "Illegal move into column "<< column <<endl; //Checks for illegal move
			return false;
		}
		for(int i=5;i>=0;i--){
			if(node[i][column] == 0){
		    		 node[i][column] = move;
		    		 return true;
		}}
	 	return false;
	  }


	  bool Board::isFull(){ //checks if board is full
	  	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			if(node[i][j] == 0)
				return false;
		}}

	    return true;
	}

	  bool Board::rowWin(int row, int player){ //Determines if player has won in given row.
	  	for(int i=0;i<4;i++){
	  		if(node[row][i] == player &&
			 node[row][i+1] == player &&
			 node[row][i+2] == player &&
			 node[row][i+3] == player)
		   		return true;
	
		}
		return false;
	  }

	  bool Board::colWin(int col, int player){ //Determines whether player has won in given column.
		for(int i=0;i<3;i++){
			if(node[i][col] == player &&
			 node[i+1][col] == player &&
			 node[i+2][col] == player &&
			 node[i+3][col] == player)
		   		return true;
		}
	   	 return false;
	  }

	  bool Board::forwardDiagWin( int player){   //Determines if player has won a forward-diagonal win. Note that "forward" means "from bottom-left to top-right", like the forward-slash.
		for(int i=5;i>2;i--){
	      	for(int j=0;j<4;j++){
			if(node[i][j] == player && 
			node[i-1][j+1] == player && 
			node[i-2][j+2] == player && 
			node[i-3][j+3] == player)
		     		return true;
		}}
		return false;
	  }

	  bool Board::backwardDiagWin( int player){ //Does exactly the same thing as forwardDiagWin, but for backslash-shaped wins.
		for(int i=0;i<3;i++){
	     	for(int j=0;j<4;j++){
			if(node[i][j] == player && 
			node[i+1][j+1] == player && 
			node[i+2][j+2] == player && 
			node[i+3][j+3] == player)
		     		return true;
		}}
	    	return false;
	  }
	    
	        
	  int Board::isWin(){ // Returns 1 if X wins, -1 if O wins, and 0 otherwise.

	    // Check every row to see if X or O won
	    for(int i=0;i<6;i++){
	      if(rowWin( i, 1))
		return 1;
	      else if(rowWin( i, 2))
		return -1;
		}

	    // Check every column to see if X or O won
	    for(int i=0;i<7;i++){
	      if(colWin( i, 1))
		return 1;
	      else if(colWin( i, 2))
		return -1;
		}

	    // Check forward diagonals
	    if(forwardDiagWin(1))
	      return 1;
	    else if(forwardDiagWin(2))
	      return -1;
		
	    // Check backward diagonals
	    if(backwardDiagWin(1))
	      return 1;
	    else if(backwardDiagWin(2)) 
	      return -1;
		
	    // if nobody has won yet, it must be a draw
	    return 0;

	}
