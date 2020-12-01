#pragma once

#include "MCell.h"

class Maze
{
public:
	enum path
	{
		p_none = 0b0000,
		p_up = 0b1000,
		p_right = 0b0100,
		p_down = 0b0010,
		p_left = 0b0001,
		p_up_down = p_up | p_down,
		p_up_down_left = p_up | p_down | p_left,
		p_down_left = p_down | p_left,
		p_up_right = p_up | p_right,
		p_up_left_right = p_up | p_left | p_right,
		p_down_left_right = p_down | p_left | p_right,
		p_up_down_right = p_up | p_down | p_right,
		p_left_right = p_left | p_right,
		p_up_down_left_right = p_up | p_down | p_left | p_right,
		p_up_left = p_up | p_left,
		p_down_right = p_down | p_right,
	};

	enum side
	{
		s_none,
		s_up,
		s_right,
		s_down,
		s_left
	};

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

	static wchar_t getPathChar(path path);

	bool inBounds(int i, int j) const;

	side getNeighbourSide(int i1, int j1, int i2, int j2) const;

	void toggleConnection(int i1, int j1, side side);
};

