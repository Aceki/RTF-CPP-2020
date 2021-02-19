#include <cmath>

#include "vector2d.h"

double Math::Vector2D::dot(const Vector2D& vec1, const Vector2D& vec2)
{
	return vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y;
}

Math::Vector3D Math::Vector2D::cross(const Vector2D& vec1, const Vector2D& vec2)
{
	return Vector3D::k() * (vec1.m_x * vec2.m_y - vec2.m_x * vec1.m_y);
}

double Math::Vector2D::getLength() const
{
	return std::sqrt(m_x * m_x + m_y * m_y);
}

Math::Vector2D Math::Vector2D::normalized() const
{
	return *this / getLength();
}

inline Math::Vector2D Math::Vector2D::operator+(const Vector2D& vec) const
{
	return Vector2D(m_x + vec.m_x, m_y + vec.m_y);
}

inline Math::Vector2D Math::Vector2D::operator-(const Vector2D& vec) const
{
	return Vector2D(m_x - vec.m_x, m_y - vec.m_y);
}

inline Math::Vector2D Math::Vector2D::operator/(const double& number) const
{
	return Vector2D(m_x / number, m_y / number);
}

std::ostream& Math::operator<<(std::ostream& os, const Vector2D& vec)
{
	return (os << '{' << vec.x() << ", " << vec.y() << '}');
}

Math::Vector2D Math::operator*(const Vector2D& vec, const double& number)
{
	return Vector2D(vec.x() * number, vec.y() * number);
}

Math::Vector2D Math::operator*(const double& number, const Vector2D& vec)
{
	return vec * number;
}
