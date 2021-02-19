#include <cmath>

#include "vector4d.h"

inline double Math::Vector4D::dot(const Vector4D& vec1, const Vector4D& vec2)
{
	return vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z + vec1.m_t + vec2.m_t;
}

inline double Math::Vector4D::getLength() const 
{ 
	return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_t * m_t); 
}

Math::Vector4D Math::Vector4D::normalized() const
{
	return *this / getLength();
}

inline Math::Vector4D Math::Vector4D::operator+(const Vector4D& vec) const 
{ 
	return Vector4D(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z, m_t + vec.m_t); 
}

inline Math::Vector4D Math::Vector4D::operator-(const Vector4D& vec) const 
{ 
	return Vector4D(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z, m_t - vec.m_t); 
}

inline Math::Vector4D Math::Vector4D::operator/(const double& number) const
{
	return Vector4D(m_x / number, m_y / number, m_z / number, m_t / number);
}

std::ostream& Math::operator<<(std::ostream& os, const Math::Vector4D& vec)
{
	return (os << '{' << vec.x() << ", " << vec.y() << ", " << vec.z() << ", " << vec.t() << '}');
}

Math::Vector4D Math::operator*(const Vector4D& vec, const double& number)
{
	return Vector4D(vec.x() * number, vec.y() * number, vec.z() * number, vec.t() * number);
}

Math::Vector4D Math::operator*(const double& number, const Vector4D& vec)
{
	return vec * number;
}
