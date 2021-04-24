#pragma once

#include "figure.h"

namespace TicTacToe
{
	class Cell
	{
	public:
		Cell() : m_figure(Figure(0)) { }

		Figure figure() const;

		bool isEmpty() const;

		void fill(Figure);

		void clear();

		operator bool() const;

	private:		
		Figure m_figure;
	};

	inline Figure Cell::figure() const { return m_figure; }

	inline bool Cell::isEmpty() const { return m_figure == Figure(0) ? true : false; }

	inline void Cell::fill(Figure figure) { m_figure = figure; }

	inline void Cell::clear() { m_figure = Figure(0); }

	inline Cell::operator bool() const { return !isEmpty(); }
}

