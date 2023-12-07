cmake_minimum_required(VERSION 3.24)
project(PyramidTicTacToe_Src)

set(CMAKE_CXX_STANDARD 14)

add_executable(PyramidTicTacToe_Src
        GameManager.cpp
        Player.cpp
        PyramidTicTacToe_App.cpp
        PyramidTicTacToe_Board.cpp
        RandomPlayer.cpp)
