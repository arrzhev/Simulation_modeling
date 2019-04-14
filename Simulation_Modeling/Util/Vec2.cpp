#include "stdafx.h"

#include "Vec2.h"
#include "Vec3.h"
#include "Point.h"

//#include <boost/lexical_cast.hpp>

Vec2::Vec2(const Vec3& vec) NOTHROW
	: x(vec.x)
	, y(vec.y)
{}

Vec2::Vec2(const Point& point) NOTHROW
	: x(point.x)
	, y(point.y)
{}
Vec2::Vec2(const PointF& point) NOTHROW
	: x(point.x)
	, y(point.y)
{}

// Вычисляет квадрат расстояния между векторами.
double Vec2::distance(const Vec2& vec) const NOTHROW
{
	return ((vec.x - this->x) * (vec.x - this->x) +
	        (vec.y - this->y) * (vec.y - this->y));
}

// Вычисляет скалярное произведение векторов.
double Vec2::dot(const Vec2& vec) const NOTHROW
{
	return (this->x * vec.x + this->y * vec.y);
}

// Вычисляет угол между векторами.
double Vec2::angle(const Vec2& vec) const NOTHROW
{
	return acos(this->normalized().dot(vec.normalized()));
}

// Нормализует вектор.
void Vec2::normalize() NOTHROW
{
	double length = this->length();

	this->x /= length;
	this->y /= length;
}

Vec2 Vec2::normalized() const NOTHROW
{
	Vec2 vec(*this);
	vec.normalize();
	return vec;
}

//std::string Vec2::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "vec[" + boost::lexical_cast<std::string>(this->x) + ", " + boost::lexical_cast<std::string>(this->y) + "]";
//
//	std::locale::global(loc);
//
//	return str;
//}
