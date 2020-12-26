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
	MTreeNode() = default;

	MTreeNode(const MTreeNode& obj) = delete;

	MTreeNode(const MTreeNode* parent);

	MTreeNode& operator=(MTreeNode&& obj) noexcept;

	MTreeNode& operator=(const MTreeNode& obj) = delete;

	int m_i = -1;
	int m_j = -1;
	int m_distance = 0;
	int m_child_count = 0;
	const MTreeNode* m_parent = nullptr;
	MTreeNode* m_children = nullptr;
};
