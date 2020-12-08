#pragma once

#include "MCell.h"

class Maze
{
public:
	Maze(const Maze& obj) = delete;

	Maze(int n, int m);

	MCell& cell(int i, int j) const;

	void printMaze() const;

	bool hasConnection(int i1, int j1, int i2, int j2) const;

	bool makeConnection(int i1, int j1, int i2, int j2);

	bool removeConnection(int i1, int j1, int i2, int j2);

	~Maze();
private:
	MCell* m_field;
	const int m_n;
	const int m_m;
};

