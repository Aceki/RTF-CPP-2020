#pragma once

#include "MCell.h"

class Maze
{
	MCell* m_field;
	const int m_n;
	const int m_m;

	enum path
	{
		//urdl
		//0000
		none = 0b0000,
		up = 0b1000,
		right = 0b0100,
		down = 0b0010,
		left = 0b0001,
		up_down = 0b1010,
		up_left_down = 0b1011,
		left_down = 0b0011,
		up_right = 0b1100,
		up_left_right = 0b1101,
		left_down_right = 0b0111,
		up_down_right = 0b1110,
		left_right = 0b0101,
		up_left_down_right = 0b1111,
		up_left = 0b1001,
		down_right = 0b0110,
	};

	bool inBounds(int i, int j) const;

	wchar_t cellChar(path path) const;

	bool isNeigbours(int i1, int j1, int i2, int j2) const;

	void toggleConnection(int i1, int j1, int i2, int j2);
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

