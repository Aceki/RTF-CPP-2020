#include <iostream>
#include <vector>

#include "Maze.h"
#include "MTreeNode.h"

using namespace std;

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

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL));

    constexpr int mazeRows = 20;
    constexpr int mazeColumns = 20;

    Maze maze(mazeRows, mazeColumns);

	MTreeNode* startNode = MTreeNode::beginTree(0, 0 + rand() % mazeColumns);

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


	int** weights = new int*[mazeRows];
	for (int i = 0; i < mazeRows; i++)
		weights[i] = new int[mazeColumns];

	buildFullMaze(maze, *startNode);

	maze.printMaze();

	vector<const MTreeNode*> nodes;
	nodes.push_back(startNode);
	weights[startNode->i()][startNode->j()] = 0;
	while (!nodes.empty())
	{
		const MTreeNode* currentNode = nodes.back();
		nodes.pop_back();
		for (int i = 0; i < currentNode->childCount(); i++)
		{
			const MTreeNode* child = currentNode->child(i);
			weights[child->i()][child->j()] = child->distance();
			nodes.push_back(child);
		}
	}

	int max = 0;

	for (int i = 0; i < mazeRows; i++)
	{
		for (int j = 0; j < mazeColumns; j++)
		{
			if (weights[i][j] > max)
				max = weights[i][j];
			printf("%-3d ", weights[i][j]);
		}
		std::cout << std::endl;

		delete[] weights[i];
	}
	delete[] weights;

	cout << max;
}
