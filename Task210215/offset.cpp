#include "offset.h"
#include "position.h"

Chess::Offset Chess::Offset::calculate(const Position& start, const Position& end)
{
	int horizontal_offset = end.horizontal() - start.horizontal();
	int vertical_offset = end.vertical() - start.vertical();

	return Offset(horizontal_offset, vertical_offset);
}
