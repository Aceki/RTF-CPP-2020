#include <cmath>
#include <iostream>

#include "Maze.h"

Maze::Maze(int n, int m) : m_n(n), m_m(m)
{
	m_field = new MCell[n * m];
}

MCell& Maze::cell(int i, int j) const
{
	return m_field[j * m_n + i];
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

	for (int m = 0; m < m_m; m++)
	{
		for (int n = 0; n < m_n; n++)
		{
			bool up = cell(m - 1, n).m_down && m > 0;
			bool down = cell(m, n).m_down;
			bool left = cell(m, n - 1).m_right && n > 0;
			bool right = cell(m, n).m_right;

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
		std::cout << std::endl;
	}
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (offset_i == -1)
		return cell(i2, j2).m_down;
	if (offset_i == 1)
		return cell(i1, j1).m_down;
	if (offset_j == -1)
		return cell(i2, j2).m_right;
	if (offset_j == 1)
		return cell(i1, j1).m_right;

	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (!hasConnection(i1, j1, i2, j2))
	{
		int offset_i = i2 - i1;
		int offset_j = j2 - j1;

		if (offset_i == -1)
		{
			cell(i2, j2).m_down = true;
			return true;
		}
		if (offset_i == 1)
		{
			cell(i1, j1).m_down = true;
			return true;
		}
		if (offset_j == -1)
		{
			cell(i2, j2).m_right = true;
			return true;
		}
		if (offset_j == 1)
		{
			cell(i1, j1).m_right = true;
			return true;
		}

		return false;
	}
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (hasConnection(i1, j1, i2, j2))
	{
		int offset_i = i2 - i1;
		int offset_j = j2 - j1;

		if (offset_i == -1)
		{
			cell(i2, j2).m_down = false;
			return true;
		}
		if (offset_i == 1)
		{
			cell(i1, j1).m_down = false;
			return true;
		}
		if (offset_j == -1)
		{
			cell(i2, j2).m_right = false;
			return true;
		}
		if (offset_j == 1)
		{
			cell(i1, j1).m_right = false;
			return true;
		}

		return false;
	}
	return true;
}

Maze::~Maze()
{
	delete[] m_field;
}
