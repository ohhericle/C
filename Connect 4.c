// CONNECT 4 PROGRAM 
// DECEMBER 13, 2016

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BOARD_HORIZ 6
#define BOARD_VERT 7

void printBoard(char*board);
int testFour(char *board, int, int, int ,int); // initializes testFour
int changeTurn(char *board, int player, const char*); // initializes changeTurn
int testWin(char *board);  // initializes testWin
int vertTest (char *board); //initalizes verTest
int diagonalTest(char *board);  // initializes diagonalTest
int horizonTest(char *board); // initializes horizonTest

//creates a new game 
int main(int game, char *gamey[]){     // main function 
    const char *PIECES = "XO"; // initializes game variables X & O
   char board[BOARD_HORIZ * BOARD_VERT];
   memset(board, ' ', BOARD_HORIZ * BOARD_VERT);  //fill block of memory


int turn, done = 0;  // initializes turn done when variable = 0

for( turn = 0; turn < BOARD_HORIZ * BOARD_VERT && !done; turn++){  //  loop to check  if a column is full) 
      printBoard(board);
      while(!changeTurn (board, turn % 2, PIECES)){ // changes player turn 
      printBoard(board);
      puts("**Column full!**\n"); // prints column full 
}
done = testWin(board); 
}
printBoard(board); //cycles again

if(turn == BOARD_HORIZ * BOARD_VERT && !done){// loop to check if board is a result of a tie game 
    puts("TIE GAME!"); // prints out tie game 
} else {
turn--; // decrements after
printf("Player %d (%c) Won!\n", turn % 2 + 1, PIECES[turn % 2]); // checks to see if there’s a winner
}
return 0;

}

void printBoard (char *board){
int row, col; // initialize row , col 

//system(“clear”); // starts a new game
puts("\n    **WELCOME TO CONNECT FOUR**\n"); // prints welcome screen

for(row = 0; row < BOARD_HORIZ; row++){
   for (col = 0; col < BOARD_VERT;col++){
printf("| %c ",  board[BOARD_VERT * row + col]);
}
puts("|"); // format for the connect 4 two dimensional array 
      puts("-----------------------------"); // format for the connect 4 two dimensional array 

}
printf("  1   2   3   4   5   6   7\n"); // label 
}
int changeTurn(char *board, int player, const char *PIECES){ // initializes changeTurn 
int row , col = 0;
   printf("Player %d (%c):\nEnter Location: ", player + 1, PIECES[player]); // prints current player's character and asks for location

while (1){ // while loop run till terminated
if(1 != scanf("%d", &col) || col < 1 || col > 7 ){
         while(getchar() != '\n'); // gets players char
    puts("INVALID LOCATION. SELECT ANOTHER."); // output for when user types in a invalid location 
} else {
break;
}
}
col--; // decrements after

for(row = BOARD_HORIZ - 1; row >=0;row--){  // for statement 
if(board[BOARD_VERT *row + col] ==' '){
board[BOARD_VERT *row + col] = PIECES[player];
return 1;
}
}
return 0;

}
int testWin(char *board){ // initializes the test to declare a winner 
return(horizonTest(board) || vertTest(board) || diagonalTest(board));

}
int testFour(char *board, int h, int i, int j, int k){ // initializes testFour and variables
return (board[h] == board[i] && board[i] == board[j] && board[j] == board[k]
&& board[h] != ' ');
}
// horizontal test loop function to declare a winner 
int horizonTest(char *board){ 
   int row, col,top;
const int WIDTH =1;
for(row = 0; row < BOARD_HORIZ;row++){ // increments before 
for(col = 0; col <BOARD_VERT -3;col++){
top = BOARD_VERT * row + col;
if(testFour(board, top, top + WIDTH, top+ WIDTH * 2,top + WIDTH * 3)){
return 1;
}
}
}
return 0;

}
// vertical test loop function to declare a winner 
int vertTest(char *board){
int row, col, top;
const int HIGH =7;

for(row = 0; row < BOARD_HORIZ -3;row ++){
for(col =0; col < BOARD_VERT;col++){
top = BOARD_VERT * row + col;
if(testFour(board, top,top + HIGH, top + HIGH * 2, top + HIGH * 3)) {
return 1;
}
}
}
return 0;
}
// Diagonal test loop function to declare a winner 
int diagonalTest(char *board){
int row , col, top, count = 0;
const int DRAG_R = 6, DRAG_L = 8;   

for(row = 0; row < BOARD_HORIZ -3; row++){ // loop that counts the rows 
for( col = 0; col < BOARD_VERT; col++){ // loop that counts the vert 
top = BOARD_VERT * row+ col ;  // loop that counts spaces between each character
if(count <= 3 && testFour(board, top, top + DRAG_L, top + DRAG_L * 2, top + DRAG_L * 3) || count >= 3 && testFour(board, top, top + DRAG_R, top + DRAG_R * 2, top + DRAG_R * 3)){

return 1;
}
count++;
}
count = 0;
}
return 0;
}