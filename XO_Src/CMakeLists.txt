cmake_minimum_required(VERSION 3.24)
project(XO_Src)

set(CMAKE_CXX_STANDARD 14)

add_executable(XO_Src
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp)
