/*
Purpose: Random player if player wanted to play against computer
Authors: Mohamed Gamal Ali (20220284)--Muhammad Ahmed Fathi (20220280)--Osama Moheb Shafik(20220446)
Date: 14/12/2023
Version: 1.5
*/

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
