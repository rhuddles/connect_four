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

extern int depthLim;

/************************Recursive AI Algorithm************************/       


int oPlayer(Board board,int depth,int bestValX,int bestValO){//Works in conjunction with xPlayer to find the best move
	int value;

	 if(board.isWin()==1 || board.isWin()==-1 || depth==depthLim){ //End recursion when a winning move is found or depth limit is hit
		return Heuristic(board);
			    }
	    int bestMove=0;
	    for(int c=0; c<7;c++){
		Board newboard=board; //Makes a copy of the current board to find value
		if(newboard.getNode(0,c) ==0){
		    newboard.makeMove(c,2);
		    value=xPlayer(newboard,depth+1,bestValX,bestValO);//Recursion: See Recursion
		
		    if(value < bestValO){ //Checks if given move was better than previous move. If so, it becoms the best move.
		        bestValO = value;
		        bestMove = c;
			}
		}}
		
		if (depth==0){return bestMove;} //After completing return the best move found		

		return bestValO;
	}
int xPlayer(Board board,int depth,int bestValX,int bestValO){ //Works in conjunction with oPlayer to find the best move
		int value;
		
	    if(board.isWin()==1 || board.isWin()==-1 || depth==depthLim){ //End recursion when a winning move is found or depth limit is hit
		return Heuristic(board);
		}
	    int bestMove=0;
	    for(int c=0; c<7;c++){           
		Board newboard=board; //Makes a copy of the current board to find value
		if(newboard.getNode(0,c) ==0){
		    newboard.makeMove(c,1);
		    value=oPlayer(newboard,depth+1,bestValX,bestValO); //Recursion: See Recursion
		   
		    if(value > bestValX){ //Checks if given move was better than previous move. If so, it becoms the best move.
		        bestValX = value;
		        bestMove = c;
			}
		}}

		if (depth==0){return bestMove;} //After completing return the best move found

	     return bestValX;	 
	}



/************************************************The Brain************************************************/

int Heuristic(Board board) {
/*This function returns an integer value of a given board. Negative boards favor o, while positive boards favor x.
The Heuristic checks for favorable board arrangments and is used in conjunction with the recursive AI below to predict 
board values several moves in the future given an ideal player. 
*/
	    if(board.isWin()==1 || board.isWin()==-1 || board.isFull()==true)
		return 9000 * board.isWin();
	    int num = 0;

	//rows Xs

	    // XXX_
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0)
		        num = num + 15;
	}}

	    // XXX_ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num + 20;
	}}

	    // XX_X
	   for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1)
		        num = num + 15;
	}}

	    // XX_X char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num + 20;
	}}


	    // X_XX 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1)
		        num = num + 15;
	}}

	    // X_XX char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j+1) !=0)
		        num = num + 20;
	}}

	    // _XXX
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1)
		        num = num + 15;
	}}
	    // _XXX char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j) !=0)
		        num = num + 20;
	}}

	//rows Os

	    // OOO_
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0)
		        num = num - 15;
	}}

	    // OOO_ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num - 20;
	}}

	    // OO_O
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2)
		        num = num - 15;
	}}

	    // OO_O char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num - 20;
	}}

	    // O_OO
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2)
		        num = num - 15;
	}}

	    // O_OO char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j+1) !=0)
		        num = num - 20;
	}}

	    // _OOO
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2)
		        num = num - 15;
	}}

	    // _OOO char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j) !=0)
		        num = num - 20;
	}}

	//rows twos Os
	 
	    // OO__ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==0)
		        num = num -5;
	}}

	    // OO__ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+2) !=0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num -10;
	}}
	    
	    // O_O_ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0)
		        num = num -5;
	}}
	    
	    // O_O_ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+1) !=0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num -10;
	}}

	    // _OO_ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0)
		        num = num -5;
	}}

	    // _OO_ char
	      for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j) !=0 &&
		       board.getNode(i+1,j+3) != 0)
		        num = num -10;
	}}

	    // __OO
	     for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2)
		        num = num -5;
	}}

	    // __OO char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==2 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j) !=0 &&
		       board.getNode(i+1,j+1) !=0)
		        num = num -10;
	}}

	    // _O_O
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2)
		        num = num -5;
	}}

	    // _O_O char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==2 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j) !=0 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num -10;
	}}

	    // O__O 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2)
		        num = num -5;
	}}

	    // O__O char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==2 &&
		       board.getNode(i+1,j+1) !=0 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num -10;
	}}

	//rows twos Xs

	    // XX__ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==0)
		        num = num +5;
	}}

	    // XX__ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+2) !=0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num +10;
	}}
	    
	    // X_X_ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0)
		        num = num +5;
	}}

	    // X_X_ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j+1) !=0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num +10;
	}}

	    // _XX_ 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0)
		        num = num +5;
	}}

	    // _XX_ char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==0 &&
		       board.getNode(i+1,j) !=0 &&
		       board.getNode(i+1,j+3) !=0)
		        num = num +10;
	}}

	    // __XX 
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1)
		        num = num +5;
	}}

	    // __XX char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==1 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j) !=0 &&
			board.getNode(i+1,j) !=0)
		        num = num +10;
	}}

	    //_X_X
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1)
		        num = num +10;
	}}

	    //_X_X char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i,j+1) ==1 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j) !=0 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num +10;
	}}

	    //X__X char
	    for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1)
		        num = num +5;
	}}

	    //X__X char
	    for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i,j+1) ==0 &&
		       board.getNode(i,j+2) ==0 &&
		       board.getNode(i,j+3) ==1 &&
		       board.getNode(i+1,j+1) !=0 &&
		       board.getNode(i+1,j+2) !=0)
		        num = num +10;
	}}


	//columns Xs

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==0)
		        num = num + 15;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==1)
		        num = num + 15;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==1)
		        num = num + 15;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==1)
		        num = num + 15;
	}}

	    //columns Os

	      for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==0)
		        num = num - 15;
	}}

	     for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==2)
		        num = num - 15;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==2)
		        num = num - 15;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==2)
		        num = num - 15;
	}}
	 
	    //column twos Os

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==0)
		        num = num -5;
	}}
	    
	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==0)
		        num = num -5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==0)
		        num = num -5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==2 &&
		       board.getNode(i+3,j) ==2)
		        num = num -5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==2 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==2)
		        num = num -5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==2 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==2)
		        num = num -5;
	}}

	    //columns twos Xs

	     for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==0)
		        num = num +5;
	}}
	    
	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==0)
		        num = num +5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==0)
		        num = num +5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==1 &&
		       board.getNode(i+3,j) ==1)
		        num = num +5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==0 &&
		       board.getNode(i+1,j) ==1 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==1)
		        num = num +5;
	}}

	    for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){ 
		    if(board.getNode(i,j) ==1 &&
		       board.getNode(i+1,j) ==0 &&
		       board.getNode(i+2,j) ==0 &&
		       board.getNode(i+3,j) ==1)
		        num = num +5;
	}}

	    //diagonals forward Xs

	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num + 15;
	}}

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 15;
	}}

	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 15;
	}}

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 15;
	}}

	    //diagonals forward Os

	     for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num - 15;
	}}

	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 15;
	}}

	   for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 15;
	}}

	     for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 15;
	}}
	 
	    //diagonals forward twos Os

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num - 5;
	}}
	    
	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num - 5;
	}}

	   for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num - 5;
	}}

	      for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 2 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 5;
	}}

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 2 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 5;
	}}

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 2)
		        num = num - 5;
	}}

	    //diagonals forward twos Xs

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num + 5;
	}}
	    
	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num + 5;
	}}

	      for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 0)
		        num = num + 5;
	}}
	  

	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 1 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 5;
	}}

	  for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i-1,j+1) == 1 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 5;
	}}

	    for(int i=5;i>2;i--){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i-1,j+1) == 0 &&
		       board.getNode(i-2,j+2) == 0 &&
		       board.getNode(i-3,j+3) == 1)
		        num = num + 5;
	}}
	    //diagonals backward Xs

	  for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num + 15;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 15;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 15;
	}}

	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 15;
	}}

	    //diagonals forward Os

	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num - 15;
	}}
	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 15;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 15;
	}}

	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 15;
	}}
	 
	    //diagonals forward twos Os

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num - 5;
	}}
	    
	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num - 5;
	}}

	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num - 5;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 2 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 5;
	}}

	  for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 2 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 5;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 2 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 2)
		        num = num - 5;
	}}

	    //diagonals forward twos Xs

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num + 5;
	}}
	    
	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num + 5;
	}}

	 for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 0)
		        num = num + 5;
	}}

	  for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 1 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 5;
	}}
	
	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 0 &&
		       board.getNode(i+1,j+1) == 1 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 5;
	}}

	for(int i=2;i<5;i++){
		for(int j=0;j<4;j++){ 
		    if(board.getNode(i,j) == 1 &&
		       board.getNode(i+1,j+1) == 0 &&
		       board.getNode(i+2,j+2) == 0 &&
		       board.getNode(i+3,j+3) == 1)
		        num = num + 5;
	}}
	    //middle of the board

	for(int i=0;i<6;i++){
		for(int j=2;j<5;j++){ 
		    if(board.getNode(i,j) ==1)
		        num = num + 1;
		    if(board.getNode(i,j) ==2)
		        num = num - 1;
	}}

	    return num;
	}

