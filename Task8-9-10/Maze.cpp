#include <cmath>
#include <cassert>
#include <iostream>

#include "Maze.h"

Maze::Maze(int n, int m) : m_n(n), m_m(m)
{
	m_field = new MCell[n * m];
}

MCell& Maze::cell(int i, int j) const
{
	assert(i >= 0 && i < m_n && j >= 0 && j < m_m);

	return m_field[i * m_m + j];
}

void Maze::printMaze() const
{
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

	for (int n = 0; n < m_n; n++)
	{
		for (int m = 0; m < m_m; m++)
		{
			bool up = n > 0 && cell(n - 1, m).m_down;
			bool down = cell(n, m).m_down;
			bool left = m > 0 && cell(n, m - 1).m_right;
			bool right = cell(n, m).m_right;

			path p = static_cast<path>((p_none) | (up * p_up) | (down * p_down) | (left * p_left) | (right * p_right));

			wchar_t path_char;

			switch (p)
			{
			case p_none:
				path_char = L'0';
				break;
			case p_up:
				path_char = L'0';
				break;
			case p_down:
				path_char = L'0';
				break;
			case p_left:
				path_char = L'0';
				break;
			case p_right:
				path_char = L'0';
				break;
			case p_up_down:
				path_char = L'|';
				break;
			case p_up_down_left:
				path_char = L'┤';
				break;
			case p_down_left:
				path_char = L'┐';
				break;
			case p_up_right:
				path_char = L'└';
				break;
			case p_up_left_right:
				path_char = L'┴';
				break;
			case p_down_left_right:
				path_char = L'┬';
				break;
			case p_up_down_right:
				path_char = L'├';
				break;
			case p_left_right:
				path_char = L'─';
				break;
			case p_up_down_left_right:
				path_char = L'┼';
				break;
			case p_up_left:
				path_char = L'┘';
				break;
			case p_down_right:
				path_char = L'┌';
				break;
			default:
				path_char = L'E';
				break;
			}

			std::wcout << path_char;
		}
		std::wcout << std::endl;
	}
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
	if (!isNeighbours(i1, j1, i2, j2) || !inBounds(i1, j1) || !inBounds(i2, j2))
		return false;

	const int abs_offset_i = abs(i2 - i1);
	const int abs_offset_j = abs(j2 - j1);

	MCell& chg_cell = cell(std::min(i1, i2), std::min(j1, j2));

	return abs_offset_i == 1 ? chg_cell.m_down : chg_cell.m_right;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (!isNeighbours(i1, j1, i2, j2) || !inBounds(i1, j1) || !inBounds(i2, j2))
		return false;

	const int abs_offset_i = abs(i2 - i1);
	const int abs_offset_j = abs(j2 - j1);

	MCell& chg_cell = cell(std::min(i1, i2), std::min(j1, j2));

	if (abs_offset_i == 1) {
		if (!chg_cell.m_down)
			chg_cell.m_down = true;
		else
			return false;
	} 
	else {
		if (!chg_cell.m_right)
			chg_cell.m_right = true;
		else
			return false;
	}

	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (!isNeighbours(i1, j1, i2, j2) || !inBounds(i1, j1) || !inBounds(i2, j2))
		return false;

	const int abs_offset_i = abs(i2 - i1);
	const int abs_offset_j = abs(j2 - j1);

	MCell& chg_cell = cell(std::min(i1, i2), std::min(j1, j2));

	if (abs_offset_i == 1) {
		if (chg_cell.m_down)
			chg_cell.m_down = false;
		else
			return false;
	}
	else {
		if (chg_cell.m_right)
			chg_cell.m_right = false;
		else
			return false;
	}

	return true;
}

Maze::~Maze()
{
	delete[] m_field;
}

