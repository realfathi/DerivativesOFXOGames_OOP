/*
Purpose: Making player enter moves
Authors: Mohamed Gamal Ali (20220284)--Muhammad Ahmed Fathi (20220280)--Osama Moheb Shafik(20220446)
Date: 14/12/2023
Version: 1.5
Section:20
TA: Mohamed Talaat
*/
#include<iostream>
#include<random>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y \"x  y\" separated by spaces And make sure it's valid:  ";
    cin >> x >> y;
}

void new_player :: get_move (int& x, int& y) {
    cout << "\nPlease enter your move y (0 to 6) represent columns : ";
    cin >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}
