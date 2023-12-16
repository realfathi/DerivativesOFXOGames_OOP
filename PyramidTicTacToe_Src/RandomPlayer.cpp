/*
 Class definition for Pyramid Tic Tac Toe Random Player class
 Which is a computer player playing randomly
 Author: Muhammad Ahmed Fathi
 Date: 7/12/2023
 Version: 1
 */

#include<iostream>
#include<random>
#include<iomanip>
#include <Vector>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;

}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    validMoves = {
            {0, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 0},
            {2, 1}, {2, 2}, {2, 3}, {2, 4}
    };
    int randomIndex = rand() % validMoves.size();
    x = validMoves[randomIndex].first;;
    y = validMoves[randomIndex].second;;
}
