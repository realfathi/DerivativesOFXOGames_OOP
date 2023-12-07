/*
 Class definition for Pyramid Tic Tac Toe class
 Author: Muhammad Ahmed Fathi
 Date: 7/12/2023
 Version: 1

 */
#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Pyramid Tic-Tac-Toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager PyramidTicTacToe (new pyramidTicTacToe(), players);
    PyramidTicTacToe.run();
    system ("pause");
}
