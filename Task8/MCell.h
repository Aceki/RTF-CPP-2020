#pragma once

class MCell
{
	//true => проход открыт.
	bool m_down = false;
	bool m_right = false;

	MCell(bool down = false, bool right = false) : m_down(down), m_right(right) {}
public:
	bool down() const { return m_down; }

	bool right() const { return m_right; }

	friend class Maze;
};

