/*
Purpose: Menu for games we created
Authors: Mohamed Gamal Ali (20220284)--Muhammad Ahmed Fathi (20220280)--Osama Moheb Shafik(20220446)
Date: 14/12/2023
Version: 1.7
Section:20
TA: Mohamed Talaat
*/

#include "Game_Welcome_Menu .h"
using namespace std;

int main() {

    char select ;
    while (true)
        {
            cout << "The Menu of Games : \n" ;
            cout << "====================\n" ;
            cout << "1) Four in a row X_O Game \n2) Pyramid TicTacToe Game\n" ;
            cout << "3) X_O Game \n4) Tic Tac Toe 5x5 X_O Game\n" ;
            cout << "5) Exit From Program \n" ;
            cout << "Choose the Game number: " ;

            cin >> select;
            switch (select) {
                case '1':
                    Four_in_a_row_X_O_Game();
                    break;

                case '2':
                    pyramidTicTacToe_Game();
                    break;

                case '3':
                    X_O_Game();
                    break;

                case '4':
                    TicTacToe5x5_Game();
                    break;

                case '5':
                    return 0;

            }
        }
}

