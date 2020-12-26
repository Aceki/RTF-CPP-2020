﻿#include <iostream>

#include "Maze.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    
    constexpr int mazeRows = 5;
    constexpr int mazeColumns = 5;
    constexpr int ladderSteps = mazeRows - 1;

    Maze maze(mazeRows, mazeColumns);

    for (int i = 0; i < ladderSteps; i++)
    {
        maze.makeConnection(i, i, i, i + 1);
        maze.makeConnection(i, i + 1, i + 1, i + 1);
    }

    maze.printMaze();
}
