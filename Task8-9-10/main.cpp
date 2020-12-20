#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#include "MTreeNode.h"
#include "Maze.h"

enum direction
{
	d_up = 0,
	d_down,
	d_left,
	d_right
};

int* getMTreeWeights(const MTreeNode& startNode, int mazeRows, int mazeColumns);

void printMTreeWeights(const int* weights, int mazeRows, int mazeColumns);

void buildFullMaze(Maze& iMaze, MTreeNode& tree);

MTreeNode* makeChain(MTreeNode& startNode, direction dir, int length);

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL));

    constexpr int mazeRows = 20;
    constexpr int mazeColumns = 20;

	//Border selection
	int startI = 0;
	int startJ = 0;
	direction startDir = static_cast<direction>(rand() % 4);
	switch (startDir)
	{
	case d_up:
		startJ = rand() % mazeColumns;
		break;
	case d_down:
		startI = mazeRows - 1;
		startJ = rand() % mazeColumns;
		break;
	case d_left:
		startI = rand() % mazeRows;
		break;
	case d_right:
		startJ = mazeColumns - 1;
		startI = rand() % mazeRows;
		break;
	}

    Maze maze(mazeRows, mazeColumns);

	MTreeNode* startNode = MTreeNode::beginTree(startI, startJ);

	//Generating a random tree
	std::vector<MTreeNode*> stack;
	stack.push_back(startNode);
	while (!stack.empty())
	{
		MTreeNode* currentNode = stack.back();
		stack.pop_back();

		int neighboursCount = 0;
		MTreeNode* neighbours[4];

		for (int offsetI = -1; offsetI <= 1; offsetI++)
			for (int offsetJ = -1; offsetJ <= 1; offsetJ++)
			{
				if (abs(offsetI) + abs(offsetJ) != 1)
					continue;

				int childI = currentNode->i() + offsetI;
				int childJ = currentNode->j() + offsetJ;

				if (childI >= 0 && childI < mazeRows && childJ >= 0 && childJ < mazeColumns
					&& MTreeNode::searchNode(*startNode, childI, childJ) == nullptr)
				{
					currentNode->addChild(childI, childJ);
					neighbours[neighboursCount++] = currentNode->hasChild(childI, childJ);
				}
			}

		if (neighboursCount == 0)
			continue;

		int nextNodeIndex = rand() % neighboursCount;

		for (int i = 0; i < neighboursCount; i++)
		{
			if (i == nextNodeIndex)
				continue;

			stack.push_back(neighbours[i]);
		}

		stack.push_back(neighbours[nextNodeIndex]);
	}

	buildFullMaze(maze, *startNode);

	maze.printMaze();

	int* weights = getMTreeWeights(*startNode, mazeRows, mazeColumns);

	int* maxPtr = std::max_element(weights, weights + mazeRows * mazeColumns - 1);

	printMTreeWeights(weights, mazeRows, mazeColumns);

	std::wcout << *maxPtr << std::endl;

	delete[] weights;

	delete startNode;
}

int* getMTreeWeights(const MTreeNode& startNode, int mazeRows, int mazeColumns)
{
	int* weights = new int[mazeRows * mazeColumns];
	weights[startNode.i() * mazeColumns + startNode.j()] = 0;

	std::vector<const MTreeNode*> stack;
	stack.push_back(&startNode);
	while (!stack.empty())
	{
		const MTreeNode* currentNode = stack.back();
		stack.pop_back();
		for (int i = 0; i < currentNode->childCount(); i++)
		{
			const MTreeNode* child = currentNode->child(i);
			weights[child->i() * mazeColumns + child->j()] = child->distance();
			stack.push_back(child);
		}
	}

	return weights;
}

void printMTreeWeights(const int* weights, int mazeRows, int mazeColumns)
{
	for (int i = 0; i < mazeRows; i++)
	{
		for (int j = 0; j < mazeColumns; j++)
			wprintf(L"%-4d", weights[i * mazeColumns + j]);
		std::wcout << std::endl;
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
