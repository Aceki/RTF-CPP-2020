#pragma once

class MTreeNode
{
public:
	static MTreeNode* beginTree(int i, int j);

	int i() const { return m_i; }

	int j() const { return m_j; }

	const MTreeNode* parent() const { return m_parent; }

	int distance() const { return m_distance; }

	int childCount() const { return m_child_count; }

	const MTreeNode* child(int i) const;

	MTreeNode* hasChild(int i, int j) const;

	bool addChild(int i, int j);

	~MTreeNode();
private:
	int m_i;
	int m_j;
	int m_distance;
	int m_child_count;
	MTreeNode* m_parent;
	MTreeNode* m_children;

	MTreeNode();

	MTreeNode(const MTreeNode& obj) = delete;

	MTreeNode(MTreeNode* parent);

	MTreeNode& operator=(const MTreeNode& obj) = delete;
};