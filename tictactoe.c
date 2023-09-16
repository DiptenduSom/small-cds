#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> //for various functions to classify and transform characters
#include <time.h>  //for manipulating data and time
// global variables
char board[3][3];
const char PLAYER = 'X';   // player will give the X on the board
const char COMPUTER = 'O'; // computer will give the O on the board
// 7 differenet function prototypes
void resetBoard();      // board will be 2D character array
void printBoard();      // printing of that board
int checkFreeSpaces();  // return type of integer
void playerMove();      // for the player to give the move
void computerMove();    // for the computer to give the move
char checkWinner();     // for checking the winning conditions
void printWinner(char); // for printing the name of the winner
// function prototypes end
int main()
{
   while (true)
   { // for playing the game as long as you wish
      int des;
      printf("\n Would you like to play a game if TIC TAC TOE ? ");
      printf("\n Enter 1 for yes and 0 for no ");
      printf("\n > ");
      scanf("%d", &des); // user input of choice done
      if (des == 1)
      {
         // assumption
         char winner = ' '; // if winner empty space then no winner
         resetBoard();      // reseting the entire tictactoe board
         while (winner = ' ' && checkFreeSpaces() != 0)
         {
            printBoard();
            playerMove();
            char winner;
            winner = checkWinner(); // checking if the player is the winner
            if (winner != ' ' || checkFreeSpaces() == 0)
            { // sending the value and chcking for free spaces or winner
               break;
            }
            computerMove();
            winner = checkWinner(); // checking if the player is the winner
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
               break;
            }
         } // checking done
         printBoard();
         printWinner(winner);
      }
      else
      {
         printf("\n Thanks for the response \n");
         exit(0);
      }
   }
   return 0;
}
void resetBoard()
{
   for (int i = 0; i < 3; i++) // for rows
   {
      for (int j = 0; j < 3; j++) // for columns
      {
         board[i][j] = ' '; // thus clearing the board out
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
} // printing complete
int checkFreeSpaces()
{
   int freespaces = 9; // initialization done
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board[i][j] != ' ')
         {
            freespaces--;
         }
      }
   }
   return freespaces;
}
void playerMove()
{
   int x; // for the user to entire the row number
   int y; // for the user to entire the column number
   do
   {
      printf(" Enter row #( 1 - 3 ) : ");
      scanf("%d", &x);
      x--;
      printf(" Enter column #( 1 - 3 ) : ");
      scanf("%d", &y);
      y--;
      if (board[x][y] != ' ')
      {
         printf("\n Invalid Move ");
      } // if the user entire in an already filled up block
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');
}
void computerMove()
{
   // creates a seed based current time
   // this function will generate radnom number in which
   // the computer will invoke its move
   srand(time(0));
   int x;
   int y;
   if (checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3; // for generating a random value between 1 and 3
         y = rand() % 3;
      } while (board[x][y] != ' ');
      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   // for checking the rows
   for (int i = 0; i < 3; i++)
   {
      if (board[i][0] == board[i][i] && board[i][0] == board[i][2]) // checking for the row conditions
      {
         return board[i][0];
      }
   }
   // for checking the columns
   for (int i = 0; i < 3; i++)
   {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) // checking for the column conditions
      {
         return board[0][1];
      }
   }
   // for checking the diagonals
   // for the left diagonal
   if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) // checking for the diagonal conditions
   {
      return board[0][0];
   }
   // for the right diagonal
   if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) // checking for the diagonal conditions
   {
      return board[0][2];
   }
   return ' ';
}
void printWinner(char winner)
{
   if (winner == PLAYER)
   {
      printf("\n YOU WIN !! \n");
   }
   else if (winner == COMPUTER)
   {
      printf("\n COMPUTER WINS ! \n");
   }
   else
   {
      printf("\n ITS A DRAW \n");
   }
}