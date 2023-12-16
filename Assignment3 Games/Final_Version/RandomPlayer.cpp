// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
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
    y = validMoves[randomIndex].second;
}
