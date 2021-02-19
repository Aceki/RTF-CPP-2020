#pragma once

#include <iostream>

namespace Math 
{
	struct Vector4D
	{
	public:
		Vector4D(double x, double y, double z, double t) : m_x(x), m_y(y), m_z(z), m_t(t) { }

		Vector4D() : Vector4D(0, 0, 0, 0) { }

		static double dot(const Vector4D& vec1, const Vector4D& vec2);

		static Vector4D zero() { return Vector4D(0, 0, 0, 0); }

		double x() const { return m_x; }

		double y() const { return m_y; }

		double z() const { return m_z; }

		double t() const { return m_t; }

		double getLength() const;

		Vector4D normalized() const;

		Vector4D operator+(const Vector4D& vec) const;

		Vector4D operator-(const Vector4D& vec) const;

		Vector4D operator/(const double& number) const;
	private:
		const double m_x;
		const double m_y;
		const double m_z;
		const double m_t;
	};

	std::ostream& operator<<(std::ostream& os, const Vector4D& vec);

	Vector4D operator*(const Vector4D& vec, const double& number);

	Vector4D operator*(const double& number, const Vector4D& vec);
}

