#include "position.h"

std::ostream& Chess::operator<<(std::ostream& os, const Position& position)
{
	char h_char;

	switch (position.horizontal())
	{
	case Position::Horizontal::A:
		h_char = 'A';
		break;
	case Position::Horizontal::B:
		h_char = 'B';
		break;
	case Position::Horizontal::C:
		h_char = 'C';
		break;
	case Position::Horizontal::D:
		h_char = 'D';
		break;
	case Position::Horizontal::E:
		h_char = 'E';
		break;
	case Position::Horizontal::F:
		h_char = 'F';
		break;
	case Position::Horizontal::G:
		h_char = 'G';
		break;
	case Position::Horizontal::H:
		h_char = 'H';
		break;
	default:
		throw std::ios::failbit;
	}

	return (os << h_char << position.vertical());
}
