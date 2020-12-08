#include <iostream>
#include <stdlib.h>

#include "MTreeNode.h"


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
