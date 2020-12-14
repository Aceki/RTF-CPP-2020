#include <iostream>
#include <vector>

#include "Maze.h"
#include "MTreeNode.h"

using namespace std;

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
		startI = 0;
		startJ = rand() % mazeColumns;
		break;
	case d_down:
		startI = mazeRows - 1;
		startJ = rand() % mazeColumns;
		break;
	case d_left:
		startJ = 0;
		startI = rand() % mazeRows;
		break;
	case d_right:
		startJ = mazeColumns - 1;
		startI = rand() % mazeRows;
		break;
	}

    Maze maze(mazeRows, mazeColumns);

	MTreeNode* startNode = MTreeNode::beginTree(startI, startJ);

	vector<MTreeNode*> stack;
	stack.push_back(startNode);
	while (!stack.empty())
	{
		MTreeNode* currentNode = stack.back();
		stack.pop_back();

		int neighboursCount = 0;
		MTreeNode* neighbours[4];

		if (MTreeNode::searchNode(*startNode, currentNode->i() - 1, currentNode->j()) == nullptr
			&& currentNode->i() - 1 >= 0 && currentNode->i() - 1 < mazeRows && currentNode->j() >= 0 && currentNode->j() < mazeColumns)
		{
			currentNode->addChild(currentNode->i() - 1, currentNode->j());
			neighbours[neighboursCount++] = currentNode->hasChild(currentNode->i() - 1, currentNode->j());
		}


		if (currentNode->i() + 1 >= 0 && currentNode->i() + 1 < mazeRows && currentNode->j() >= 0 && currentNode->j() < mazeColumns
			&& MTreeNode::searchNode(*startNode, currentNode->i() + 1, currentNode->j()) == nullptr)
		{
			currentNode->addChild(currentNode->i() + 1, currentNode->j());
			neighbours[neighboursCount++] = currentNode->hasChild(currentNode->i() + 1, currentNode->j());
		}

		if (currentNode->i() >= 0 && currentNode->i() < mazeRows && currentNode->j() - 1 >= 0 && currentNode->j() - 1 < mazeColumns
			&& MTreeNode::searchNode(*startNode, currentNode->i(), currentNode->j() - 1) == nullptr)
		{
			currentNode->addChild(currentNode->i(), currentNode->j() - 1);
			neighbours[neighboursCount++] = currentNode->hasChild(currentNode->i(), currentNode->j() - 1);
		}

		if (currentNode->i() >= 0 && currentNode->i() < mazeRows && currentNode->j() + 1 >= 0 && currentNode->j() + 1 < mazeColumns
			&& MTreeNode::searchNode(*startNode, currentNode->i(), currentNode->j() + 1) == nullptr)
		{
			currentNode->addChild(currentNode->i(), currentNode->j() + 1);
			neighbours[neighboursCount++] = currentNode->hasChild(currentNode->i(), currentNode->j() + 1);
		}

		if (neighboursCount == 0)
			continue;

		if (neighboursCount == 1)
		{
			stack.push_back(neighbours[0]);
			continue;
		}

		int nextNodeIndex = 0 + rand() % neighboursCount;

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

	int* weights = new int[mazeRows * mazeColumns];
	weights[startNode->i() * mazeColumns + startNode->j()] = 0;

	vector<const MTreeNode*> nodes;
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

	int max = 0;

	for (int i = 0; i < mazeRows; i++)
	{
		for (int j = 0; j < mazeColumns; j++)
		{
			if (weights[i * mazeColumns + j] > max)
				max = weights[i * mazeColumns + j];
			printf("%-3d ", weights[i * mazeColumns + j]);
		}
		std::cout << std::endl;
	}
	delete[] weights;

	cout << max;
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
	vector<const MTreeNode*> nodes;
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