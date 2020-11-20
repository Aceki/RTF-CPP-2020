#pragma once

enum class path
{
	//urdl
	//0000
	none = 0b0000,
	up = 0b1000,
	right = 0b0100,
	down = 0b0010,
	left = 0b0001,
	up_down = 0b1010,
	up_left_down = 0b1011,
	left_down = 0b0011,
	up_right = 0b1100,
	up_left_right = 0b1101,
	left_down_right = 0b0111,
	up_down_right = 0b1110,
	left_right = 0b0101,
	up_left_down_right = 0b1111,
	up_left = 0b1001,
	down_right = 0b0110,
};
