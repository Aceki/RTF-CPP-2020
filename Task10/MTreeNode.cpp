#include <iostream>
#include <stdlib.h>
#include <vector>

#include "MTreeNode.h"
#include <cassert>


MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* node = new MTreeNode();

	node->m_i = i;
	node->m_j = j;
	node->m_distance = 0;
	node->m_child_count = 0;
	node->m_parent = nullptr;
	node->m_children = new MTreeNode[4];

	return node;
}

const MTreeNode* MTreeNode::searchNode(const MTreeNode& tree, const int i, const int j) // TODO: Метод поиска нод.
{
	if (tree.m_i == i && tree.m_j == j)
		return &tree;

	std::vector<const MTreeNode*> nodes;
	nodes.push_back(&tree);

	while (!nodes.empty())
	{
		const MTreeNode* currentNode = nodes.back();
		nodes.pop_back();
		for (int c = 0; c < currentNode->childCount(); c++)
		{
			const MTreeNode* child = currentNode->child(c);
			if (child->i() == i && child->j() == j)
				return child;
			nodes.push_back(child);
		}
	}
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

	MTreeNode* child = m_children + m_child_count;

	child->m_i = i;
	child->m_j = j;
	child->m_distance = m_distance + 1;
	child->m_parent = this;
	child->m_child_count = 0;
	child->m_children = new MTreeNode[4];

	m_child_count++;

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

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_distance = parent->distance() + 1;
	m_child_count = 0;
	m_parent = parent;
	m_children = new MTreeNode[4];
}
