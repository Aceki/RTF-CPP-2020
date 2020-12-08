#include <iostream>

#include "Maze.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    
    Maze maze(5, 5);

    for (int i = 0; i < 4; i++)
    {
        maze.makeConnection(i - 1, i, i, i);
        maze.makeConnection(i, i, i, i + 1);
    }
    maze.makeConnection(3, 4, 4, 4);

    maze.printMaze();
}
