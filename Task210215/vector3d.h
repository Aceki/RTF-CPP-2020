#pragma once

#include <iostream>

namespace Math 
{
	struct Vector3D
	{
	public:
		Vector3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) { }

		Vector3D() : Vector3D(0, 0, 0) { }

		static double dot(const Vector3D& vec1, const Vector3D& vec2);

		static Vector3D cross(const Vector3D vec1, const Vector3D& vec2);

		static Vector3D zero() { return Vector3D(0, 0, 0); }

		static Vector3D i() { return Vector3D(1, 0, 0); }

		static Vector3D j() { return Vector3D(0, 1, 0); }

		static Vector3D k() { return Vector3D(0, 0, 1); }

		double x() const { return m_x; }

		double y() const { return m_y; }

		double z() const { return m_z; }

		double getLength() const;

		Vector3D normalized() const;

		Vector3D operator+(const Vector3D& vec) const;

		Vector3D operator-(const Vector3D& vec) const;

		Vector3D operator/(const double& number) const;
	private:
		const double m_x;
		const double m_y;
		const double m_z;
	};

	std::ostream& operator<<(std::ostream& os, const Vector3D& vec);

	Vector3D operator*(const Vector3D& vec, const double& number);

	Vector3D operator*(const double& number, const Vector3D& vec);
}
