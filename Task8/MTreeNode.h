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

	MTreeNode(int i, int j);

	MTreeNode(MTreeNode* parent, int i, int j);

	MTreeNode& operator=(MTreeNode&& obj) noexcept;

	MTreeNode& operator=(const MTreeNode& obj) = delete;
};

enum direction 
{
	d_up,
	d_down,
	d_left,
	d_right
};

MTreeNode* makeChain(MTreeNode* startNode, direction dir, int length);

MTreeNode* makeLadderTree(MTreeNode* startNode, int size);

int** getTraversalWeights(const MTreeNode* startNode, int rows, int columns);

void printTraversalField(const MTreeNode* startNode, int rows, int columns);