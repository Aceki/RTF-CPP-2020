#include <iostream>

#include "Maze.h"
#include "MTreeNode.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    constexpr int mazeRows = 5;
    constexpr int mazeColumns = 5;

    Maze maze1(mazeRows, mazeColumns);
    for (int i = 0; i <= 4; i++)
    {
        maze1.makeConnection(i - 1, i, i, i);
        maze1.makeConnection(i, i, i, i + 1);
    }
    maze1.printMaze();

    Maze maze2(mazeRows, mazeColumns);

    MTreeNode* startNode = makeLadderTree(MTreeNode::beginTree(0, 0), mazeRows);

    fillMaze(maze2, startNode);

    maze2.printMaze();

    printTraversalField(startNode, mazeRows, mazeColumns);
}
