#include <unordered_set>
#include <iostream>
#include <stdlib.h>

#include "MTreeNode.h"


MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* node = new MTreeNode(i, j);

	return node;
}

const MTreeNode* MTreeNode::child(int i) const
{
	if(i >= 0 && i < m_child_count)
		return m_children + i;
	return nullptr;
}

bool MTreeNode::addChild(int i, int j)
{
	if (m_child_count == 4 || hasChild(i, j))
		return false;

	int offset_i = m_i - i;
	int offset_j = m_j - j;

	if (abs(offset_i) + abs(offset_j) != 1)
		return false;

	m_children[m_child_count++] = std::move(MTreeNode(this, i, j));

	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j) const
{
	for (int c = 0; c < m_child_count; c++)
		if (m_children[c].i() == i && m_children[c].j() == j)
			return m_children + c;
	return nullptr;
}

MTreeNode::~MTreeNode()
{
	if (m_children == nullptr)
		return;
	delete[] m_children;
}

MTreeNode::MTreeNode()
{
	m_i = m_j = m_distance = m_child_count = -1;
	m_parent = m_children = nullptr;
}

MTreeNode::MTreeNode(MTreeNode* parent, int i, int j)
{
	m_i = i;
	m_j = j;
	m_distance = parent->distance() + 1;
	m_child_count = 0;
	m_parent = parent;
	m_children = new MTreeNode[4];
}

MTreeNode::MTreeNode(int i, int j)
{
	m_i = i;
	m_j = j;
	m_distance = 0;
	m_child_count = 0;
	m_parent = nullptr;
	m_children = new MTreeNode[4];
}

MTreeNode& MTreeNode::operator=(MTreeNode&& obj) noexcept
{
	if (this == &obj)
		return *this;

	m_i = obj.m_i;
	m_j = obj.m_j;
	m_distance = obj.m_distance;
	m_child_count = obj.m_child_count;
	
	m_parent = obj.m_parent;
	obj.m_parent = nullptr;

	m_children = obj.m_children;
	obj.m_children = nullptr;

	return *this;
}

MTreeNode* makeChain(MTreeNode* startNode, direction dir, int length)
{
	if (length == 0)
		return startNode;

	int i_inc = 0;
	int j_inc = 0;
	
	switch (dir)
	{
	case d_up:
		i_inc = -1;
		break;
	case d_down:
		i_inc = 1;
		break;
	case d_left:
		j_inc = -1;
		break;
	case d_right:
		j_inc = 1;
		break;
	default:
		break;
	}

	int next_i = startNode->i() + i_inc;
	int next_j = startNode->j() + j_inc;

	if (startNode->addChild(next_i, next_j) == true)
		makeChain(startNode->hasChild(next_i, next_j), dir, length - 1);
	else
		return startNode;
}

MTreeNode* makeLadderTree(MTreeNode* startNode, int size)
{
	if (size == 1)
		return startNode;

	MTreeNode* currentNode = startNode;

	makeChain(currentNode, direction::d_right, size - 1);
	makeChain(currentNode, direction::d_down, size - 1);

	currentNode = startNode->hasChild(startNode->i(), startNode->j() + 1);
	currentNode->addChild(currentNode->i() + 1, currentNode->j());
	currentNode = currentNode->hasChild(currentNode->i() + 1, currentNode->j());

	makeLadderTree(currentNode, size - 1);

	return startNode;
}

int** getTraversalWeights(const MTreeNode* startNode, const int rows, const int columns, int** weights, std::unordered_set<const MTreeNode*>& visited)
{
	for (int i = 0; i < startNode->childCount(); i++)
	{
		const MTreeNode* child = startNode->child(i);
		if (visited.find(child) == visited.end()) // visited not contains child
		{
			visited.insert(child);
			if(child->i() >= 0 && child->i() < rows && child->j() >= 0 && child->j() < columns)
				weights[child->i()][child->j()] = child->distance();
			getTraversalWeights(child, rows, columns, weights, visited);
		}
	}
	return weights;
}

int** getTraversalWeights(const MTreeNode* startNode, int rows, int columns)
{
	int** weights = new int*[rows];
	for (int i = 0; i < rows; i++)
		weights[i] = new int[columns];

	weights[0][0] = startNode->distance();

	std::unordered_set<const MTreeNode*> visited;
	visited.insert(startNode);

	return getTraversalWeights(startNode, rows, columns, weights, visited);
}

void printTraversalField(const MTreeNode* startNode, int rows, int columns)
{
	int** weights = getTraversalWeights(startNode, rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << weights[i][j] << ' ';
		}
		std::cout << std::endl;

		delete[] weights[i];
	}

	delete[] weights;
}
