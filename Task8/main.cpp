#include <iostream>

#include "Maze.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    
    Maze maze = Maze(5, 5);

    for (int i = 1; i <= 4; i++)
    {
        maze.makeConnection(i, i - 1, i, i);
        maze.makeConnection(i, i, i + 1, i);
    }
    maze.makeConnection(4, 3, 4, 4);

    maze.printMaze();
}
