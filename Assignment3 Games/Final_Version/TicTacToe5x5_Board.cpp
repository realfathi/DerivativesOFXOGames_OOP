// Class definition for TicTacToe5x5 Board class
// Author:  Osama Moheb Shafik
// Date:    15/12/2022
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
    if (!(x < 0 || x >4 || y < 0 || y > 4) && (board[x][y] == 0)) {
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
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool TicTacToe5x5::is_winner() {
    if (n_moves==24){
        //count 3 in a row horizontally
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i][j+1]&&board[i][j+1]==board[i][j+2]){
                    count_x++;
                }
                else if (board[i][j]=='O'&&board[i][j]==board[i][j+1]&&board[i][j+1]==board[i][j+2]){
                    count_o++;
                }
            }
        }
        //count 3 in a row vertically
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+2][j]){
                    count_x++;
                }
                else if (board[i][j]=='O'&&board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+2][j]){
                    count_o++;
                }
            }
        }
        //count 3 in a row diagonally
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i+2][j+2]){
                    count_x++;
                }
                else if(board[i][j]=='O'&&board[i][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i+2][j+2]){
                    count_o++;
                }
            }
        }
        for (int i = 0; i <3 ; ++i) {
            for (int j = 4; j >=2 ; --j) {
                if (board[i][j]=='X'&&board[i][j]==board[i+1][j-1]&&board[i+1][j-1]==board[i+2][j-2]){
                    count_x++;
                }
                else if(board[i][j]=='O'&&board[i][j]==board[i+1][j-1]&&board[i+1][j-1]==board[i+2][j-2]){
                    count_o++;
                }
            }
        }
    }
    if (count_x>count_o) {
        n_moves++; //to make game over and don't go inside the loop in the game manager (prevent from update board then)
        cout<<"X wins\n";
    }
    else if(count_o>count_x) {
        n_moves++;
        cout<<"O wins\n";
    }
    return false;

}

// Return true if 24 moves are done and no winner
bool TicTacToe5x5::is_draw() {
    if (count_x==count_o&&n_moves==24){
        n_moves++; //to make game over and don't go inside the loop in the game manager (prevent from update board then)
        cout<<"Draw!\n";
    }
    return false;
}

bool TicTacToe5x5::game_is_over () {
    return n_moves > 24;
}







