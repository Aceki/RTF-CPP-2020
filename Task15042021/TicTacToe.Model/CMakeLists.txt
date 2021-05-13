cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(TicTacToe.Model)

add_library(Model)

target_sources(Model
    PRIVATE
    	include/cell.h
        include/field.h
        include/figure.h
        include/game.h
        src/cell.cpp
        src/field.cpp
        src/figure.cpp 
        src/game.cpp 
)

target_include_directories(Model PUBLIC include)
