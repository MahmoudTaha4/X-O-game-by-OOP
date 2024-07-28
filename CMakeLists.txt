cmake_minimum_required(VERSION 3.28)
project(XO)

set(CMAKE_CXX_STANDARD 17)

add_executable(XO main.cpp
        GameBoard.cpp
        GameManager.cpp
        Player.cpp)
