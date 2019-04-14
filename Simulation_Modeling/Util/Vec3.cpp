#include "stdafx.h"

#include "Vec3.h"
#include "Vec2.h"
#include "Point.h"

//#include <boost/lexical_cast.hpp>

Vec3::Vec3(const Vec2& vec, double z) NOTHROW
	: x(vec.x)
	, y(vec.y)
	, z(z)
{}

Vec3::Vec3(const Point& point, double z) NOTHROW
	: x(point.x)
	, y(point.y)
	, z(z)
{}

// Вычисляет квадрат расстояния между векторами.
double Vec3::distance(const Vec3& vec) const NOTHROW
{
	return ((vec.x - this->x) * (vec.x - this->x) +
	        (vec.y - this->y) * (vec.y - this->y) +
			(vec.z - this->z) * (vec.z - this->z));
}

// Вычисляет скалярное произведение векторов.
double Vec3::dot(const Vec3& vec) const NOTHROW
{
	return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
}

// Вычисляет угол между векторами.
double Vec3::angle(const Vec3& vec) const NOTHROW
{
	return acos(this->normalized().dot(vec.normalized()));
}

// Нормализует вектор.
void Vec3::normalize() NOTHROW
{
	double length = this->length();

	this->x /= length;
	this->y /= length;
	this->z /= length;
}

Vec3 Vec3::normalized() const NOTHROW
{
	Vec3 vec(*this);
	vec.normalize();
	return vec;
}

//std::string Vec3::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "vec[" +
//		boost::lexical_cast<std::string>(this->x) + ", " +
//		boost::lexical_cast<std::string>(this->y) + ", " +
//		boost::lexical_cast<std::string>(this->z) + "]";
//
//	std::locale::global(loc);
//
//	return str;
//}
