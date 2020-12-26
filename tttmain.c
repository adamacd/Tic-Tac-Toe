#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tttheader.h"

int main() {
    char board[9] = { '.', '.', '.',
                      '.', '.', '.',
                      '.', '.', '.' };
    int space;
    int row;
    int first;
    int playerTurn;
    int turnCounter = 0;
    char marker;
    
    printInstructions();
    updateBoard(board);

    printf("\nWill you make your move first, or second?\n"
           "Type 1 or 2: ");
    scanf("%d", &first);
    setFirstTurn(&marker, &playerTurn, first);
    
    while(hasWinner(board) != 1){
        if(playerTurn == 1){
            printf("Which row will you mark? (1, 2, or 3): ");
            scanf("%d", &row);
            VerifyRow(row);
            printf("Which space will you mark? (1, 2, or 3): ");
            scanf("%d", &space);
            VerifySpace(space);
        
            switch(row){
                case 1: 
                    verifyUnoccupiedSpace1(board, space);
                    board[space-1] = marker;
                    break;
                case 2: 
                    verifyUnoccupiedSpace2(board, space);
                    board[space+2] = marker;
                    break;
                case 3: 
                    verifyUnoccupiedSpace3(board, space);
                    board[space+5] = marker;
            }
            marker = 'O';   //switch to opponent's marker
            playerTurn = 2; //switch to opponent's turn
            turnCounter++;
            
            printf("*********************    \n"
                   "***   Your Turn   ***  X \n"
                   "*********************    \n");    
        }
        else {
            computerMove(board);
            marker = 'X';  //switch to player's marker
            playerTurn = 1;//switch to player's turn
            turnCounter++;
        }
        updateBoard(board);
        
        if(hasWinner(board) != 1){
            checkDraw(turnCounter);
        }
    }
    victoryMessage(&playerTurn);
}
