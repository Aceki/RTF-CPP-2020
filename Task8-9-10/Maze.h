#pragma once

#include "MCell.h"

class Maze
{
public:
	Maze(const Maze&) = delete;

	Maze(int n, int m);

	MCell& cell(int i, int j) const;

	void printMaze() const;

	bool hasConnection(int i1, int j1, int i2, int j2) const;

	bool makeConnection(int i1, int j1, int i2, int j2);

	bool removeConnection(int i1, int j1, int i2, int j2);

	~Maze();
private:
	bool inBounds(int i, int j) const { return i >= 0 && i < m_n && j >= 0 && j < m_m; }

	bool isNeighbours(int i1, int j1, int i2, int j2) const { return abs(i2 - i1) + abs(j2 - j1) == 1; }

	MCell* m_field;
	const int m_n;
	const int m_m;
};

