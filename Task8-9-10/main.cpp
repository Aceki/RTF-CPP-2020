#include <iostream>
#include <vector>

#include "Maze.h"
#include "MTreeNode.h"

enum direction
{
	d_up,
	d_down,
	d_left,
	d_right
};

void buildFullMaze(Maze& iMaze, MTreeNode& tree);

MTreeNode* makeChain(MTreeNode& startNode, direction dir, int length);

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    constexpr int mazeRows = 5;
    constexpr int mazeColumns = 5;

    Maze maze(mazeRows, mazeColumns);

	MTreeNode* startNode = MTreeNode::beginTree(0, 0);

	MTreeNode* currentNode = startNode;
	while ((currentNode->i() + 1 < mazeRows) && (currentNode->j() + 1 < mazeColumns))
	{
		makeChain(*currentNode, d_down, mazeRows - currentNode->i() - 1);
		makeChain(*currentNode, d_right, mazeColumns - currentNode->j() - 1);

		currentNode = currentNode->hasChild(currentNode->i(), currentNode->j() + 1);
		currentNode->addChild(currentNode->i() + 1, currentNode->j());
		currentNode = currentNode->hasChild(currentNode->i() + 1, currentNode->j());
	}

	buildFullMaze(maze, *startNode);

	maze.printMaze();
	
	int* weights = new int[mazeRows * mazeColumns];
	weights[0] = 0;

	std::vector<const MTreeNode*> nodes;
	nodes.reserve(mazeRows * mazeColumns);
	nodes.push_back(startNode);
	while (!nodes.empty())
	{
		const MTreeNode* currentNode = nodes.back();
		nodes.pop_back();
		for (int i = 0; i < currentNode->childCount(); i++)
		{
			const MTreeNode* child = currentNode->child(i);
			weights[child->i() * mazeColumns + child->j()] = child->distance();
			nodes.push_back(child);
		}
	}

	for (int i = 0; i < mazeRows; i++)
	{
		for (int j = 0; j < mazeColumns; j++)
		{
			std::cout << weights[i * mazeColumns + j] << ' ';
		}
		std::cout << std::endl;
	}

	delete[] weights;
}

void buildFullMaze(Maze& iMaze, MTreeNode& tree)
{
	std::vector<const MTreeNode*> nodes;
	nodes.push_back(&tree);
	while (!nodes.empty())
	{
		const MTreeNode* currentNode = nodes.back();
		nodes.pop_back();
		for (int i = 0; i < currentNode->childCount(); i++)
		{
			const MTreeNode* child = currentNode->child(i);
			iMaze.makeConnection(currentNode->i(), currentNode->j(), child->i(), child->j());
			nodes.push_back(child);
		}
	}
}

MTreeNode* makeChain(MTreeNode& startNode, direction dir, int length)
{
	if (length == 0)
		return &startNode;

	int child_i = startNode.i();
	int child_j = startNode.j();

	switch (dir)
	{
	case d_up:
		child_i -= 1;
		break;
	case d_down:
		child_i += 1;
		break;
	case d_left:
		child_j -= 1;
		break;
	case d_right:
		child_j += 1;
		break;
	default:
		break;
	}

	startNode.addChild(child_i, child_j);
	MTreeNode* child = startNode.hasChild(child_i, child_j);
	if (child != nullptr)
		return makeChain(*child, dir, length - 1);
	return &startNode;
}
