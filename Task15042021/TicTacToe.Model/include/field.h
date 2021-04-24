#pragma once

#include "cell.h"

namespace TicTacToe
{
	class Field
	{
	public:
		const Cell& cell(int i, int j) const;

		Cell& cell(int i, int j);

		int size() const;
	private:
		int toIndex(int i, int j) const;

		static const int m_size = 3;
		Cell m_cells[9];
	};

	inline const Cell& Field::cell(int i, int j) const 
	{ 
		int index = toIndex(i, j);

		if (index < 0 || index >= m_size * m_size)
			throw "Exception here!";

		return m_cells[j * m_size + i];
	}

	inline Cell& Field::cell(int i, int j)
	{
		int index = toIndex(i, j);

		if (index < 0 || index >= m_size * m_size)
			throw "Exception here!";

		return m_cells[j * m_size + i];
	}

	inline int Field::toIndex(int i, int j) const { return j * m_size + i; }

	inline int Field::size() const { return m_size; }
}
