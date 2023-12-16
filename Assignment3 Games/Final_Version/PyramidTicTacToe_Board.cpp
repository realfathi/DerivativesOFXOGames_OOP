/*
 Class definition for Pyramid Tic Tac Toe class
 Author: Muhammad Ahmed Fathi
 Date: 7/12/2023
 Version: 1

 */
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <string>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
pyramidTicTacToe::pyramidTicTacToe () {
   n_rows = n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool pyramidTicTacToe::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (((x==0 && y==2) ||(x==1 && y>0 &&y<4) ||(x==2 && y>=0 &&y<=4)) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it

void pyramidTicTacToe::display_board() {

   for (int i: {0,1,2}) {
      cout << "\n";
      for (int j: {0,1,2,3,4}) {
          if ((i==0&&j==2)){
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << "|";}
          else if ((i==1&&j>0&&j<4)){
              cout << "(" << i << "," << j << ")";
              cout << setw(2) << board [i][j] << "|";}
          else if (i==2){cout << "(" << i << "," << j << ")";
              cout << setw(2) << board [i][j] << "|";}
          else cout<<"        ";
      }
      cout << "\n------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O

bool pyramidTicTacToe::is_winner() {
    char row_win[4], col_win[3], diag_win[2];
    diag_win[0] = board[1][3] & board[0][2] & board[2][4];
    diag_win[1] = board[1][1] & board[0][2] & board[2][0];

    row_win[0] = board[1][1] & board[1][2] & board[1][3];
    row_win[1] = board[2][0] & board[2][1] & board[2][2];
    row_win[2] = board[2][1] & board[2][2] & board[2][3];
    row_win[3] = board[2][2] & board[2][3] & board[2][4];

    col_win[2] = board[0][2] & board[1][2] & board[2][2];

        if ( (row_win[0] && (row_win[0] == board[1][1])) ||
                (row_win[1] && (row_win[1] == board[2][0])) ||
                 (row_win[2] && (row_win[2] == board[2][1])) ||
                  (row_win[3] && (row_win[3] == board[2][2])) )
            {return true;}

    if (col_win[2] && (col_win[2] == board[0][2]) )
    {return true;}


    if ((diag_win[0] && diag_win[0] == board[0][2]) ||
        (diag_win[1] && diag_win[1] == board[0][2]))
        {return true;}


    return false;
}

// Return true if 9 moves are done and no winner
bool pyramidTicTacToe::is_draw() {
    return (n_moves == 9 && !is_winner());
}

int pyramidTicTacToe::num_moves() {
    return 0;
}

bool pyramidTicTacToe::game_is_over () {
    return n_moves >= 9;
}
