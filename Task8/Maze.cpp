#include <cmath>
#include <iostream>

#include "Maze.h"

Maze::side Maze::getNeighbourSide(int i1, int j1, int i2, int j2) const
{
	if (!inBounds(i1, j1) || !inBounds(i2, j2))
		return s_none;

	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (offset_i == -1)
		return s_up;
	if (offset_i == 1)
		return s_down;
	if (offset_j == -1)
		return s_left;
	if (offset_j == 1)
		return s_right;

	return s_none;
}

bool Maze::inBounds(int i, int j) const
{
	return i >= 0 && j >= 0 && ((j * m_n + i) < (m_n * m_m));
}

wchar_t Maze::getPathChar(path path)
{
	switch (path)
	{
	case p_none:
		return L'0';
	case p_up:
		return L'└';
	case p_down:
		return L'┐';
	case p_left:
		return L'─';
	case p_right:
		return L'─';
	case p_up_down:
		return L'|';
	case p_up_down_left:
		return L'┤';
	case p_down_left:
		return L'┐';
	case p_up_right:
		return L'└';
	case p_up_left_right:
		return L'┴';
	case p_down_left_right:
		return L'┬';
	case p_up_down_right:
		return L'├';
	case p_left_right:
		return L'─';
	case p_up_down_left_right:
		return L'┼';
	case p_up_left:
		return L'┘';
	case p_down_right:
		return L'┌';
	default:
		return L'E';
	}
}

void Maze::toggleConnection(int i, int j, side side)
{
	switch (side)
	{
	case s_up:
		cell(i - 1, j).m_down = !cell(i - 1, j).m_down;
		break;
	case s_right:
		cell(i, j).m_right = !cell(i, j).m_right;
		break;
	case s_down:
		cell(i, j).m_down = !cell(i, j).m_down;
		break;
	case s_left:
		cell(i, j - 1).m_right = !cell(i, j - 1).m_right;
		break;
	}
}

Maze::Maze(int n, int m) : m_n(n), m_m(m)
{
	m_field = new MCell[n * m];
}

MCell& Maze::cell(int i, int j) const
{
	if (!inBounds(i, j))
		throw "Index out of range!";
	return m_field[j * m_n + i];
}

void Maze::printMaze() const
{
	for (int m = 0; m < m_m; m++)
	{
		for (int n = 0; n < m_n; n++)
		{
			bool up = inBounds(m - 1, n) && cell(m - 1, n).m_down;
			bool down = cell(m, n).m_down;
			bool left = inBounds(m, n - 1) && cell(m, n - 1).m_right;
			bool right = cell(m, n).m_right;

			int path = path::p_none;
			path |= (up * p_up) | (down * p_down) | (left * p_left) | (right * p_right);

			std::wcout << Maze::getPathChar(static_cast<Maze::path>(path));
		}
		std::cout << std::endl;
	}	
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
	switch (getNeighbourSide(i1, j1, i2, j2))
	{
	case s_up:
		return cell(i2, j2).m_down;
	case s_down:
		return cell(i1, j1).m_down;
	case s_left:
		return cell(i2, j2).m_right;
	case s_right:
		return cell(i1, j1).m_right;
	default:
		return false;
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (!hasConnection(i1, j1, i2, j2))
		toggleConnection(i1, j1, getNeighbourSide(i1, j1, i2, j2));
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (hasConnection(i1, j1, i2, j2))
		toggleConnection(i1, j1, getNeighbourSide(i1, j1, i2, j2));
	return true;
}

Maze::~Maze()
{
	delete[] m_field;
}
