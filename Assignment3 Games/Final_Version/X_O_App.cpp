/*
Purpose: Menu for games we created
Authors: Mohamed Gamal Ali (20220284)--Muhammad Ahmed Fathi (20220280)--Osama Moheb Shafik(20220446)
Date: 14/12/2023
Version: 1.5
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
            cout << "1) Four_in_a_row_X_O_Game \n2) pyramidTicTacToe_Game\n" ;
            cout << "3) X_O_Game \n4) TicTacToe5x5_X_O_Game\n" ;
            cout << "5) Exit From Program \n" ;
            cout << "Choose the Game number : " ;

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

