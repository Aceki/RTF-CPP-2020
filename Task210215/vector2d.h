#pragma once

#include <iostream>

#include "vector3d.h"

namespace Math
{
	struct Vector2D
	{
	public:
		Vector2D(double x, double y) : m_x(x), m_y(y) { }

		Vector2D() : Vector2D(0, 0) { }

		static double dot(const Vector2D& vec1, const Vector2D& vec2);

		static Vector3D cross(const Vector2D& vec1, const Vector2D& vec2);

		static Vector2D zero() { return Vector2D(0, 0); }

		double x() const { return m_x; }

		double y() const { return m_y; }

		double getLength() const;

		Vector2D normalized() const;

		Vector2D operator+(const Vector2D& vec) const;

		Vector2D operator-(const Vector2D& vec) const;

		Vector2D operator/(const double& number) const;
	private:
		const double m_x;
		const double m_y;
	};

	std::ostream& operator<<(std::ostream& os, const Vector2D& vec);

	Vector2D operator*(const Vector2D& vec, const double& number);

	Vector2D operator*(const double& number, const Vector2D& vec);
}
