#pragma once

#include <iostream>

namespace Chess 
{
	struct Position
	{
	public:
		enum Horizontal
		{
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H
		};

		enum Vertical
		{
			One = 1,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight
		};

		explicit Position(Horizontal h, Vertical v) : m_h(h), m_v(v) { }

		Horizontal horizontal() const { return m_h; }

		Vertical vertical() const { return m_v; }
	private:
		const Horizontal m_h;
		const Vertical m_v;
	};

	std::ostream& operator<<(std::ostream& os, const Position& position);
}
