cmake_minimum_required(VERSION 3.15)
project(pente)

set(CMAKE_CXX_STANDARD 14)

add_executable(pente main.cpp Player.h Board.h Referee.h)