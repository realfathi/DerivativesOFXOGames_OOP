// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
TicTacToe5x5::TicTacToe5x5() {
    count_x=0;
    count_o=0;
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
bool TicTacToe5x5::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void TicTacToe5x5::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.

bool TicTacToe5x5::is_winner() {

    if (n_moves >= 24){
        //count 3 in a row horizontally
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i][j+1]==board[i][j+2]){
                    count_x++;
                }
                else if (board[i][j]=='O'&&board[i][j]==board[i][j+1]==board[i][j+2]){
                    count_o++;
                }
            }
        }
        //count 3 in a row vertically
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j]==board[i+2][j]){
                    count_x++;
                }
                else if (board[i][j]=='O'&&board[i][j]==board[i+1][j]==board[i+2][j]){
                    count_o++;
                }
            }
        }
        //count 3 in a row diagonally
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j+1]==board[i+2][j+2]){
                    count_x++;
                }
                else if(board[i][j]=='O'&&board[i][j]==board[i+1][j+1]==board[i+2][j+2]){
                    count_o++;
                }
            }
        }
        for (int i = 0; i <3 ; ++i) {
            for (int j = 4; j >=2 ; --j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j-1]==board[i+2][j-2]){
                    count_x++;
                }
                else if(board[i][j]=='O'&&board[i][j]==board[i+1][j-1]==board[i+2][j-2]){
                    count_o++;
                }
            }
        }
        return true ;
    }

    return false ;

}


// Return true if 24 moves are done and no winner
bool TicTacToe5x5::is_draw() {
    return ((count_x == count_o) && is_winner()) ;
}

bool TicTacToe5x5::game_is_over () {
    return n_moves >= 24 ;
}

