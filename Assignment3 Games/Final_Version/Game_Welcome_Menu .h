// Authors:  Mohammad El-Ramly - Muhammad Ahmed Fathi - Osama Moheb Shafik - Mohamed Gamal Ali
// ID:                         -      20220280        -        20220446    -    20220284
// Date:   7/12/2023
// Last Update Date : 16 / 12 / 2023
// Version: 1.1


#include <iostream>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
#ifndef GAMES2222_GAME_WELCOME_MENU_H
#define GAMES2222_GAME_WELCOME_MENU_H

void Four_in_a_row_X_O_Game(){
    int choice;
    Player* players[2];
    players[0] = new new_player (1, 'x');
    cout << "Welcome to FCAI Four in a row X_O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new new_player(2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer('o', 3);

    GameManager x_o_game2(new Four_in_a_row_X_O_Board(), players);
    x_o_game2.run();
    system("pause");
}

//===============================================================================================

void pyramidTicTacToe_Game(){
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
        players[1] = new New_RandomPlayer ('o', 3);

    GameManager PyramidTicTacToe (new pyramidTicTacToe(), players);
    PyramidTicTacToe.run();
    system ("pause");
}

//===============================================================================================

void TicTacToe5x5_Game(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI TicTacToe 5x5 game :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new TicTacToe5x5(), players);
    x_o_game.run();
    system ("pause");
}

//===============================================================================================

void X_O_Game(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X_O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}

//===============================================================================================

#endif //GAMES2222_GAME_WELCOME_MENU_H
