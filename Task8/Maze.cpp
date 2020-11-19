#include <cmath>
#include <iostream>

#include "Maze.h"

bool Maze::isNeigbours(int i1, int j1, int i2, int j2) const
{
	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (abs(offset_i) > 1 || abs(offset_j) > 1)
		return false;
	return (abs(offset_i) == 1 && offset_j == 0)
		|| (offset_i == 0 && abs(offset_j) == 1);
}

bool Maze::inBounds(int i, int j) const
{
	return i >= 0 && j >= 0 && ((i * m_n + j) < (m_n * m_m));
}

wchar_t Maze::cellChar(Maze::path path) const
{
	switch (path)
	{
	case Maze::path::none:
		return L'°';
	case Maze::path::up_down:
		return L'|';
	case Maze::path::up_left_down:
		return L'┤';
	case Maze::path::left_down:
		return L'┐';
	case Maze::path::up_right:
		return L'└';
	case Maze::path::up_left_right:
		return L'┴';
	case Maze::path::left_down_right:
		return L'┬';
	case Maze::path::up_down_right:
		return L'├';
	case Maze::path::left_right:
		return L'─';
	case Maze::path::up_left_down_right:
		return L'┼';
	case Maze::path::up_left:
		return L'┘';
	case Maze::path::down_right:
		return L'┌';
	case Maze::path::up:
		return L'└';
	case Maze::path::right:
		return L'─';
	case Maze::path::down:
		return L'┐';
	case Maze::path::left:
		return L'─';
	default:
		return L'E';
	}
}

void Maze::toggleConnection(int i1, int j1, int i2, int j2)
{
	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (offset_i == 1)
		cell(i1, j1).m_right = !cell(i1, j1).m_right;
	if (offset_i == -1)
		cell(i2, j2).m_right = !cell(i2, j2).m_right;
	if (offset_j == -1)
		cell(i2, j2).m_down = !cell(i2, j2).m_down;
	if (offset_j == 1)
		cell(i1, j1).m_down = !cell(i1, j1).m_down;
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
			
			std::wcout << cellChar(p);
		}
		std::cout << std::endl;
	}	
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
	if (!isNeigbours(i1, j1, i2, j2))
		return false;

	int offset_i = i2 - i1;
	int offset_j = j2 - j1;

	if (offset_i == 1)
		return cell(i1, j1).m_right;
	if (offset_i == -1)
		return cell(i2, j2).m_right;
	if (offset_j == -1)
		return cell(i2, j2).m_down;
	if (offset_j == 1)
		return cell(i1, j1).m_down;
	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (!isNeigbours(i1, j1, i2, j2))
		return false;
	if (!hasConnection(i1, j1, i2, j2))
		toggleConnection(i1, j1, i2, j2);
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (!isNeigbours(i1, j1, i2, j2))
		return false;
	if (hasConnection(i1, j1, i2, j2))
		toggleConnection(i1, j1, i2, j2);
	return true;
}

Maze::~Maze()
{
	delete[] m_field;
}
