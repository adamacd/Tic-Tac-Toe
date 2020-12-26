#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hasWinner(char *board){
    
    if ( (board[0] == 'X' || board[0] == 'O') && board[0] == board[1] && board[1] == board[2])
        return 1;         
    else if ( (board[3] == 'X' || board[3] == 'O') && board[3] == board[4] && board[4] == board[5])
        return 1;
    else if ( (board[6] == 'X' || board[6] == 'O') && board[6] == board[7] && board[7] == board[8])
        return 1;                
    else if ( (board[0] == 'X' || board[0] == 'O') && board[0] == board[3] && board[3] == board[6])
        return 1;              
    else if ( (board[1] == 'X' || board[1] == 'O') && board[1] == board[4] && board[4] == board[7])
        return 1;            
    else if ( (board[2] == 'X' || board[2] == 'O') && board[2] == board[5] && board[5] == board[8])
        return 1;        
    else if ( (board[0] == 'X' || board[0] == 'O') && board[0] == board[4] && board[4] == board[8])
        return 1;
    else if ( (board[2] == 'X' || board[2] == 'O') && board[2] == board[4] && board[4] == board[6])
        return 1;

}


void updateBoard(char *board){

    printf("  *   %c | %c | %c   *\n" //put the printboard in a function
          "*    -----------    *\n"
          "  *   %c | %c | %c   *\n"
          "*    -----------    *\n"
          "  *   %c | %c | %c   *\n", 
          board[0], board[1], board[2], board[3], board[4], 
          board[5], board[6], board[7], board[8] );

}

void VerifyRow(int row){
    if( row < 1 || row > 3 ) {
        fprintf(stderr, "Invalid input. Game over!");
        exit(1);
    }
}
void VerifySpace(int space){
    if( space < 1 || space > 3 ) {
        fprintf(stderr, "Invalid input. Game over!");
        exit(1);
    }  
}

void verifyUnoccupiedSpace1(char *board, int space){
    if( board[space-1] != '.' ){
        fprintf(stderr, "That space is already occupied by a marker. Game over!");
        exit(1);
    }
}
void verifyUnoccupiedSpace2( char *board, int space){
    if( board[space+2] != '.' ){
        fprintf(stderr, "That space is already occupied by a marker. Game over!");
        exit(1);
    }
}

void verifyUnoccupiedSpace3( char *board, int space){
    if( board[space+5] != '.' ){
        fprintf(stderr, "That space is already occupied by a marker. Game over!");
        exit(1);
    }
}

void setFirstTurn( char *mark, int *turn, int first ){
    if( first == 1 ){
        *turn = 1;
        *mark = 'X';
    }
    else if( first == 2 ) {
        *turn = 2;
        *mark = 'O';
    }
    else{
        fprintf(stderr, "Invalid input. Game over!");
        exit(1);
    }
}

void computerMove( char *board ){
    srand(time(NULL));
    int r = rand() % 9;
    while( board[r] == 'X' || board[r] == 'O' ){
        r = rand() % 9;
    }
    board[r] = 'O';
   // marker = 'X';   //switch to player's marker
   // playerTurn = 1; //switch to player's turn 
    
    printf("*********************   \n"
           "***Computer's Turn***  O\n"
           "*********************   \n"); 
}

void victoryMessage(int *turn){
    if( *turn == 2 ){
        printf(
               "\n   *             *  \n"
               " *        *        *\n"
               "   *   You win   *\n"
               "     *         *  \n"
               "          *       ");
    }
    else{
        printf(
               "01101000 01100001 01101000 01100001 00100000\n"
               "01101100 01101111 01110011 01100101 01110010\n"
               "** Computer wins **\n"
               "  **************   \n"
               "     ********      \n"
               "       ****        \n");
    }
}
void checkDraw(int turncount){
    if(turncount == 9){
        printf("####################################\n"
               "# There is no winner. It's a draw! #\n"
               "####################################\n");
        exit(0);
    }
}

void printInstructions(){
    printf(
           "\n* *  Tic-Tac-Toe  *  *\n\n"
           "Put your mark (X) on 3 spaces horizontally, vertically, or diagonally, to win.\n"
           "The board has 3 rows, each with 3 spaces:\n"
           "Rows 1, 2, 3 (Top, Middle, Bottom)\n"
           "Spaces 1, 2, 3 (Left, Midde, Right)\n\n");
            
}