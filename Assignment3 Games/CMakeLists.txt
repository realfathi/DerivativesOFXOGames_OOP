cmake_minimum_required(VERSION 3.26)
project(Games2222)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Games2222
        Final_Version/Four_in_row_X_O_Board.cpp
        Final_Version/GameManager.cpp
        Final_Version/Player.cpp
        Final_Version/RandomPlayer.cpp
        Final_Version/X_O_App.cpp
        Final_Version/X_O_Board.cpp
        include/BoardGame_Classes.hpp
        Final_Version/PyramidTicTacToe_Board.cpp
        "Final_Version/Game_Welcome_Menu .h"
        Final_Version/X_O_App.cpp
        Final_Version/X_O_App.cpp
        Final_Version/X_O_App.cpp
        Final_Version/TicTacToe5x5_Board.cpp
)
