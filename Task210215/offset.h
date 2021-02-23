#pragma once

namespace Chess
{
	struct Position;

	struct Offset
	{
	public:
		static Offset calculate(const Position& start, const Position& end);

		int horizontal() const { return m_h; }

		int vertical() const { return m_v; }
	private:
		Offset(int h, int v) : m_h(h), m_v(v) { }

		const int m_v;
		const int m_h;
	};
}