#include <iostream>
#include <stdlib.h>

#include "MTreeNode.h"
#include <cassert>


MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* node = new MTreeNode();

	node->m_i = i;
	node->m_j = j;

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

	if (abs(m_i - i) + abs(m_j - j) != 1)
		return false;

	MTreeNode child(this);
	child.m_i = i;
	child.m_j = j;

	m_children[m_child_count++] = std::move(child);

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
	delete[] m_children;
}

MTreeNode::MTreeNode(MTreeNode* parent)
{
	assert(parent != nullptr);

	m_distance = parent->distance() + 1;
	m_parent = parent;
	m_children = new MTreeNode[4];
}

MTreeNode& MTreeNode::operator=(MTreeNode&& obj) noexcept
{
	if (this == &obj)
		return obj;

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
