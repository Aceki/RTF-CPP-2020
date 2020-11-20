#pragma once

#include "path.h"
#include "side.h"
#include "MCell.h"

class Maze
{
	MCell* m_field;
	const int m_n;
	const int m_m;

	bool inBounds(int i, int j) const;

	wchar_t getPathChar(path path) const;

	side getNeighbourSide(int i1, int j1, int i2, int j2) const;

	void toggleConnection(int i1, int j1, side side);
public:
	Maze(const Maze& obj);

	Maze(int n, int m);

	MCell& cell(int i, int j) const;

	void printMaze() const;

	bool hasConnection(int i1, int j1, int i2, int j2) const;

	bool makeConnection(int i1, int j1, int i2, int j2);

	bool removeConnection(int i1, int j1, int i2, int j2);

	~Maze();
};

