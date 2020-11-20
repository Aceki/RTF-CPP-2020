#include <cmath>
#include <iostream>

#include "Maze.h"

side Maze::getNeighbourSide(int i1, int j1, int i2, int j2) const
{
	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (offset_i == 1)
		return side::right;
	if (offset_i == -1)
		return side::left;
	if (offset_j == -1)
		return side::up;
	if (offset_j == 1)
		return side::down;

	throw "Not a neighbours!";
}

bool Maze::inBounds(int i, int j) const
{
	return i >= 0 && j >= 0 && ((i * m_n + j) < (m_n * m_m));
}

wchar_t Maze::getPathChar(path path) const
{
	switch (path)
	{
	case path::none:
		return L'°';
	case path::up_down:
		return L'|';
	case path::up_left_down:
		return L'┤';
	case path::left_down:
		return L'┐';
	case path::up_right:
		return L'└';
	case path::up_left_right:
		return L'┴';
	case path::left_down_right:
		return L'┬';
	case path::up_down_right:
		return L'├';
	case path::left_right:
		return L'─';
	case path::up_left_down_right:
		return L'┼';
	case path::up_left:
		return L'┘';
	case path::down_right:
		return L'┌';
	case path::up:
		return L'└';
	case path::right:
		return L'─';
	case path::down:
		return L'┐';
	case path::left:
		return L'─';
	default:
		return L'E';
	}
}

void Maze::toggleConnection(int i, int j, side side)
{
	switch (side)
	{
	case side::up:
		cell(i, j - 1).m_down = !cell(i, j - 1).m_down;
		break;
	case side::right:
		cell(i, j).m_right = !cell(i, j).m_right;
		break;
	case side::down:
		cell(i, j).m_down = !cell(i, j).m_down;
		break;
	case side::left:
		cell(i - 1, j).m_right = !cell(i - 1, j).m_right;
		break;
	}
}

Maze::Maze(const Maze& obj) : m_n(obj.m_n), m_m(obj.m_m)
{
	int m_field_length = obj.m_n * obj.m_m;
	m_field = new MCell[m_field_length];
	for (int i = 0; i < m_field_length; i++)
		m_field[i] = obj.m_field[i];
}

Maze::Maze(int n, int m) : m_n(n), m_m(m)
{
	m_field = new MCell[n * m];
}

MCell& Maze::cell(int i, int j) const
{
	if (!inBounds(i, j))
		throw "Index out of range!";
	return m_field[i * m_n + j];
}

void Maze::printMaze() const
{
	for (int m = 0; m < m_m; m++)
	{
		for (int n = 0; n < m_n; n++)
		{
			bool up = inBounds(n, m - 1) && cell(n, m - 1).m_down;
			bool right = cell(n, m).m_right;
			bool down = cell(n, m).m_down;
			bool left = inBounds(n - 1, m) && cell(n - 1, m).m_right;

			int flag = up;
			flag = flag << 1 | right;
			flag = flag << 1 | down;
			flag = flag << 1 | left;

			path p = static_cast<path>(flag);
			
			std::wcout << getPathChar(p);
		}
		std::cout << std::endl;
	}	
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
	switch (getNeighbourSide(i1, j1, i2, j2))
	{
	case side::right:
		return cell(i1, j1).m_right;
	case side::left:
		return cell(i2, j2).m_right;
	case side::up:
		return cell(i2, j2).m_down;
	case side::down:
		return cell(i1, j1).m_down;
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
