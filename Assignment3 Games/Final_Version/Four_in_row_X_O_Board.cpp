/*
 Class definition for Four_in_a_row_X_O_Board class
 Author: Mohamed Gamal Ali          (20220284)
 Date: 14/12/2023
 Version: 1
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
Four_in_a_row_X_O_Board :: Four_in_a_row_X_O_Board() {
    n_rows = 6 ;
    n_cols = 7 ;
    board = new char*[n_rows];
    for (int i = n_rows ; i >=0 ; --i) {
        board [i] = new char[n_cols];
        for (int j = n_cols; j >=0; j--)
            board[i][j] = '-';
    }

}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_in_a_row_X_O_Board:: update_board (int x, int y, char mark){
    // Only update if move is valid
    if ( y >= 0 && y <= 6) {
        for (int i = 0 ; i < n_rows; i++) {
            if (board[i][y] == '-') {
                board[i][y] = toupper(mark); // NOLINT(*-narrowing-conversions)
                n_moves++;
                return true ;
            }
        }
    }

    return false ;

}

// Display the board and the pieces on it
void Four_in_a_row_X_O_Board :: display_board(){
    for (int i = n_rows - 1; i >= 0; --i) {
        for (int j = 0; j < n_cols; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    for (int j = 0; j < n_cols; ++j) {
        cout << j << ' ';
    }
    cout << endl ;

}
bool Four_in_a_row_X_O_Board :: is_winner(){
    //! Check horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j + 1] == board[i][j + 2] &&
                board[i][j + 2] == board[i][j + 3]) {
                return true;
            }
        }
    }

    //! Check vertically
    for (int j = 0; j < n_cols; ++j) {
        for (int i = 0; i < n_rows - 3; ++i) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i + 2][j] &&
                board[i + 2][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    //! Check diagonally (positive slope)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i + 1][j + 1] == board[i + 2][j + 2] &&
                board[i + 2][j + 2] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    //! Check diagonally (negative slope)
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 3 ; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i - 1][j + 1] == board[i - 2][j + 2] &&
                board[i - 2][j + 2] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

bool Four_in_a_row_X_O_Board :: is_draw(){
    return (n_moves == 42 && !is_winner());
}
bool Four_in_a_row_X_O_Board :: game_is_over(){
    return n_moves >= 42;
}

int Four_in_a_row_X_O_Board::num_moves() {
    return 0;
}

