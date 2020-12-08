#pragma once

class MCell
{
public:
	bool down() const { return m_down; }

	bool right() const { return m_right; }

	friend class Maze;
private:
	bool m_down = false;
	bool m_right = false;

	MCell() = default;
};

