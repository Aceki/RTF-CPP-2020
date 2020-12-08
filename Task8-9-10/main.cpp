#include <iostream>
#include <vector>

#include "Maze.h"
#include "MTreeNode.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    constexpr int mazeRows = 5;
    constexpr int mazeColumns = 5;

    Maze maze(mazeRows, mazeColumns);

	MTreeNode* startNode = MTreeNode::beginTree(0, 0);

#pragma region LadderTreeCreating
	{
		MTreeNode* currentNode = startNode;
		while (currentNode != nullptr) 
		{
			MTreeNode* temp = currentNode;

			for (int i = currentNode->i(); i < mazeRows - 1; i++)
			{
				temp->addChild(temp->i() + 1, temp->j());
				temp = temp->hasChild(temp->i() + 1, temp->j());
			}
			
			temp = currentNode;

			for (int i = currentNode->j(); i < mazeColumns - 1; i++)
			{
				temp->addChild(temp->i(), temp->j() + 1);
				temp = temp->hasChild(temp->i(), temp->j() + 1);
			}
			

			temp = currentNode->hasChild(currentNode->i(), currentNode->j() + 1);
			temp->addChild(temp->i() + 1, temp->j());
			currentNode = temp->hasChild(temp->i() + 1, temp->j());

			if (currentNode->i() + 1 == mazeRows && currentNode->j() + 1 == mazeColumns)
				currentNode = nullptr;
		}
	}
#pragma endregion


	int** weights = new int*[mazeRows];
	for (int i = 0; i < mazeRows; i++)
		weights[i] = new int[mazeColumns];

#pragma region MazeFilling
	{
		vector<const MTreeNode*> nodes;
		nodes.push_back(startNode);
		while (!nodes.empty()) 
		{
			const MTreeNode* currentNode = nodes.back();
			nodes.pop_back();
			for (int i = 0; i < currentNode->childCount(); i++)
			{
				const MTreeNode* child = currentNode->child(i);
				maze.makeConnection(currentNode->i(), currentNode->j(), child->i(), child->j());
				nodes.push_back(child);
			}
		}
	}
#pragma endregion

	maze.printMaze();

#pragma region WeightsCounting
	{
		vector<const MTreeNode*> nodes;
		nodes.push_back(startNode);
		weights[0][0] = 0;
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
	}
#pragma endregion

#pragma region TraversalFieldPrinting
	{
		for (int i = 0; i < mazeRows; i++)
		{
			for (int j = 0; j < mazeColumns; j++)
			{
				std::cout << weights[i][j] << ' ';
			}
			std::cout << std::endl;

			delete[] weights[i];
		}
		delete[] weights;
	}
#pragma endregion
}
