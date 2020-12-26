//Function Prototypes

int hasWinner(char *board);
void updateBoard(char *board);
void VerifyRow(int row);
void VerifySpace(int space);
void setFirstTurn(char *mark, int *turn, int first);
void computerMove(char *board);
void verifyUnoccupiedSpace1(char *board, int space);
void verifyUnoccupiedSpace2(char *board, int space);
void verifyUnoccupiedSpace3(char *board, int space);
void victoryMessage(int *turn);
void checkDraw(int);
void printInstructions();
