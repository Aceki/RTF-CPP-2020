#include <cmath>

#include "vector3d.h"
#include "vector2d.h"

double Math::Vector3D::dot(const Vector3D& vec1, const Vector3D& vec2)
{
	return vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z;
}

Math::Vector3D Math::Vector3D::cross(const Vector3D& vec1, const Vector3D& vec2)
{
	return Vector3D::i() * (vec1.m_y * vec2.m_z - vec2.m_y * vec1.m_z) -
		   Vector3D::j() * (vec1.m_x * vec2.m_z - vec2.m_x * vec1.m_z) +
		   Vector3D::k() * (vec1.m_x * vec2.m_y - vec2.m_x * vec1.m_y);
}

double Math::Vector3D::getLength() const 
{ 
	return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z); 
}

Math::Vector3D Math::Vector3D::normalized() const 
{ 
	return *this / getLength(); 
}

Math::Vector3D Math::Vector3D::operator+(const Vector3D& vec) const
{
	return Vector3D(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

Math::Vector3D Math::Vector3D::operator-(const Vector3D& vec) const
{
	return Vector3D(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z);
}

Math::Vector3D Math::Vector3D::operator/(const double& number) const
{
	return Vector3D(m_x / number, m_y / number, m_z / number);
}

std::ostream& Math::operator<<(std::ostream& os, const Vector3D& vec)
{
	return (os << '{' << vec.x() << ", " << vec.y() << ", " << vec.z() << '}');
}

Math::Vector3D Math::operator*(const Vector3D& vec, const double& number)
{
	return Vector3D(vec.x() * number, vec.y() * number, vec.z() * number);
}

Math::Vector3D Math::operator*(const double& number, const Vector3D& vec)
{
	return vec * number;
}
