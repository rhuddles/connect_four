/*Connect Four
Created by Bobby Huddleston
September 2013.*/


#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib> 
#include "connectFour.h"

using namespace std;

int depthLim=2;	
	
int main(){

	/*****initialize variables*****/
	long Hvalue;
	int bestMove; //contains column of bestMove
	char go; //start a new game?
	int column; //value of chosen column to play in
	int difficulty, first=rand()%2; 	
	
	//check player response
	cout << "start new game?(y/n) "; 
	cin >> go;

	//if player wants to start game, begin
	while(go == 'y' || go == 'Y'){
	    	
		Board board;
	
		//difficulty selection	
		cout <<"Select Difficulty (enter 1-4): "<<endl<<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl<<"4. Impossible"<<endl<<"Difficulty: ";
		cin >> difficulty;
		while((depthLim<1 || depthLim>4)&& depthLim!=-2 ){
			cout <<"Invalid difficulty" <<endl;
			cout <<"Select Difficulty (enter 1-4): "<<endl<<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl<<"4. Impossible"<<endl<<"Difficulty: ";
			cin >> difficulty;
		}
		depthLim+=difficulty;

	   	cout << "Bring it on!"<< endl;
	    
		
		if(first==0){
			cout <<"You are player X. You have the first move" <<endl;
		}
		else if(first==1){		
			cout <<"You are player O. X has the first move" <<endl;
		}

		//Checks for End Of Game by checking for win or full board
		while(!board.isFull() && board.isWin()==0){

			// X making a move
			board.printBoard();
			cout<< "X's turn:" <<endl;

			// Get and apply X's move.
			if(first==1){
		    		column = xPlayer(board,0,-9999,9999);
			}
			else if(first==0){
				column=getMove();//oPlayer(board,0,-9999,9999);
	
				while(column==-1){
					cout <<"Invlaid input";
					column=getMove();
				}
			}
			board.makeMove(column,1);
			board.printBoard();

			// if(that ended the game, break out of the loop
			if(board.isFull() || board.isWin()!=0)
			    break;

			// Same story, different player
			cout<< "O's turn:"<<endl;

			if(first==0){
		    		column = oPlayer(board,0,-9999,9999);
			}
			else if(first==1){
				column=getMove();//xPlayer(board,0,-9999,9999);
	
				while(column==-1){
					cout <<"Invlaid input";
					column=getMove();
				}
			}
			board.makeMove(column, 2);
		    	board.printBoard();
		}

	//End game text
	if(board.isWin()==1)
		cout<< "X wins!"<<endl;
	else if(board.isWin()==-1)
		cout<< "O wins!"<<endl;
	else
		cout<< "Draw!"<<endl;

	//switch first move
	if(first==0)
		first=1;
	else first=0;
	    cout<<"Play again? y/n:";
	    cin>>go;
	     // and loop!

	}

	return 42;
}

int getMove(){
	    /* Get a move from the user. This guarantees that the user has typed a
	    number in the range [0, 6], but there might be a character already in
	    that space on the board; this doesn't check that.

	    This function returns a column number*/

		int col;
		bool validMove=true; //true if no valid move has been made

	    while(validMove)  // Loop until they get it right
		{
		cout<< "Enter column values (0-6)"<<endl;
		cout<<"col:";
		cin>>col; //get user input

		       
		if(col >=0 && col < 7)
		    validMove=false;  // They gave us a valid x and y
		else if(col ==-1)
			return -1;
		else
		    cout<< "That isn't a valid input! Try again!"<<endl;
		    // and then this will loop again
		}
	    return col;
	}

