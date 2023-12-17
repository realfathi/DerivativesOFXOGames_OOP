cmake_minimum_required(VERSION 3.24)
project(Final_Version)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Final_Version
        Four_in_row_X_O_Board.cpp
        "Game_Welcome_Menu .h"
        GameManager.cpp
        Menu.cpp
        Player.cpp
        PyramidTicTacToe_Board.cpp
        RandomPlayer.cpp
        TicTacToe5x5_Board.cpp
        X_O_Board.cpp)
