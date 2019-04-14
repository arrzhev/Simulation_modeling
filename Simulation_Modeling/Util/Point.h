#pragma once

#ifndef _POINT_H_
#define _POINT_H_
#include "Math.h"
#include <cassert>

#include "Defines.h"


class Point;
class PointF;

// Определяет точку в двумерном пространстве.
class Point
{
public:
	int x, y;

	inline Point() NOTHROW;
	inline Point(int x, int y) NOTHROW;
	inline Point(const Point& point) NOTHROW;

	Point(const PointF& point) NOTHROW;

	inline void move(int x, int y) NOTHROW;
	inline void move(const Point& point) NOTHROW;

	inline void moveTo(int x, int y) NOTHROW;
	inline void moveTo(const Point& point) NOTHROW;

	inline void scale(int x, int y) NOTHROW;
	inline void scale(const Point& point) NOTHROW;

	inline bool isNull() const NOTHROW;

	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline Point& operator=(const Point& point) NOTHROW;

	inline Point& operator+=(const Point& point) NOTHROW;
	inline Point& operator-=(const Point& point) NOTHROW;
	inline Point& operator*=(double value) NOTHROW;
	inline Point& operator/=(double value);

	friend inline Point operator-(const Point& point) NOTHROW;

	friend inline Point operator+(const Point& point1, const Point& point2) NOTHROW;
	friend inline Point operator-(const Point& point1, const Point& point2) NOTHROW;
	friend inline Point operator*(const Point& point, double value) NOTHROW;
	friend inline Point operator*(double value, const Point& point) NOTHROW;
	friend inline Point operator/(const Point& point, double value) NOTHROW;

	friend inline bool operator==(const Point& point1, const Point& point2) NOTHROW;
	friend inline bool operator!=(const Point& point1, const Point& point2) NOTHROW;
};

inline Point::Point() NOTHROW : x(0), y(0) {}
inline Point::Point(int x, int y) NOTHROW : x(x), y(y) {}
inline Point::Point(const Point& point) NOTHROW : x(point.x), y(point.y) {}

inline void Point::move(int x, int y) NOTHROW
{
	this->x += x;
	this->y += y;
}

inline void Point::move(const Point& point) NOTHROW
{
	this->x += point.x;
	this->y += point.y;
}

inline void Point::moveTo(int x, int y) NOTHROW
{
	this->x = x;
	this->y = y;
}

inline void Point::moveTo(const Point& point) NOTHROW
{
	this->x = point.x;
	this->y = point.y;
}

inline void Point::scale(int x, int y) NOTHROW
{
	this->x *= x;
	this->y *= y;
}

inline void Point::scale(const Point& point) NOTHROW
{
	this->x *= point.x;
	this->y *= point.y;
}

inline bool Point::isNull() const NOTHROW
{ return (this->x == 0 && this->y == 0); }

inline void Point::clear() NOTHROW
{ this->moveTo(0, 0); }

inline Point& Point::operator=(const Point& point) NOTHROW
{
	this->moveTo(point);
	return *this;
}

inline Point& Point::operator+=(const Point& point) NOTHROW
{
	this->move(point);
	return *this;
}

inline Point& Point::operator-=(const Point& point) NOTHROW
{
	this->move(-point);
	return *this;
}

inline Point& Point::operator*=(double value) NOTHROW
{
	this->x = Math::round((double)this->x * value);
	this->y = Math::round((double)this->y * value);
	return *this;
}

inline Point& Point::operator/=(double value)
{
	assert(value != 0.0);
	this->x = Math::round((double)this->x / value);
	this->y = Math::round((double)this->y / value);
	return *this;
}

inline Point operator-(const Point& point) NOTHROW
{ return Point(-point.x, -point.y); }

inline Point operator+(const Point& point1, const Point& point2) NOTHROW
{ return Point(point1.x + point2.x, point1.y + point2.y); }

inline Point operator-(const Point& point1, const Point& point2) NOTHROW
{ return Point(point1.x - point2.x, point1.y - point2.y); }

inline Point operator*(const Point& point, double value) NOTHROW
{ return Point(Math::round((double)point.x * value), Math::round((double)point.y * value)); }

inline Point operator*(double value, const Point& point) NOTHROW
{ return Point(Math::round((double)point.x * value), Math::round((double)point.y * value)); }

inline Point operator/(const Point& point, double value) NOTHROW
{
	assert(value != 0.0);
	return Point(Math::round((double)point.x / value), Math::round((double)point.y / value));
}

inline bool operator==(const Point& point1, const Point& point2) NOTHROW
{ return (point1.x == point2.x && point1.y == point2.y); }

inline bool operator!=(const Point& point1, const Point& point2) NOTHROW
{ return (point1.x != point2.x || point1.y != point2.y); }



// Определяет точку в двумерном пространстве.
class PointF
{
public:
	double x, y;

	inline PointF() NOTHROW;
	inline PointF(double x, double y) NOTHROW;
	inline PointF(const PointF& point) NOTHROW;

	PointF(const Point& point) NOTHROW;

	inline void move(double x, double y) NOTHROW;
	inline void move(const PointF& point) NOTHROW;

	inline void moveTo(double x, double y) NOTHROW;
	inline void moveTo(const PointF& point) NOTHROW;

	inline void scale(double x, double y) NOTHROW;
	inline void scale(const PointF& point) NOTHROW;

	inline bool isNull() const NOTHROW;

	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline PointF& operator=(const PointF& point) NOTHROW;

	inline PointF& operator+=(const PointF& point) NOTHROW;
	inline PointF& operator-=(const PointF& point) NOTHROW;
	inline PointF& operator*=(double value) NOTHROW;
	inline PointF& operator/=(double value);

	friend inline PointF operator-(const PointF& point) NOTHROW;

	friend inline PointF operator+(const PointF& point1, const PointF& point2) NOTHROW;
	friend inline PointF operator-(const PointF& point1, const PointF& point2) NOTHROW;
	friend inline PointF operator*(const PointF& point, double value) NOTHROW;
	friend inline PointF operator*(double value, const PointF& point) NOTHROW;
	friend inline PointF operator/(const PointF& point, double value) NOTHROW;

	friend inline bool operator==(const PointF& point1, const PointF& point2) NOTHROW;
	friend inline bool operator!=(const PointF& point1, const PointF& point2) NOTHROW;
};

inline PointF::PointF() NOTHROW : x(0.0), y(0.0) {}
inline PointF::PointF(double x, double y) NOTHROW : x(x), y(y) {}
inline PointF::PointF(const PointF& point) NOTHROW : x(point.x), y(point.y) {}

inline void PointF::move(double x, double y) NOTHROW
{
	this->x += x;
	this->y += y;
}

inline void PointF::move(const PointF& point) NOTHROW
{
	this->x += point.x;
	this->y += point.y;
}

inline void PointF::moveTo(double x, double y) NOTHROW
{
	this->x = x;
	this->y = y;
}

inline void PointF::moveTo(const PointF& point) NOTHROW
{
	this->x = point.x;
	this->y = point.y;
}

inline void PointF::scale(double x, double y) NOTHROW
{
	this->x *= x;
	this->y *= y;
}

inline void PointF::scale(const PointF& point) NOTHROW
{
	this->x *= point.x;
	this->y *= point.y;
}

inline bool PointF::isNull() const NOTHROW
{ return (this->x == 0.0 && this->y == 0.0); }

inline void PointF::clear() NOTHROW
{ this->moveTo(0.0, 0.0); }

inline PointF& PointF::operator=(const PointF& point) NOTHROW
{
	this->moveTo(point);
	return *this;
}

inline PointF& PointF::operator+=(const PointF& point) NOTHROW
{
	this->move(point);
	return *this;
}

inline PointF& PointF::operator-=(const PointF& point) NOTHROW
{
	this->move(-point);
	return *this;
}

inline PointF& PointF::operator*=(double value) NOTHROW
{
	this->x = Math::round(this->x * value);
	this->y = Math::round(this->y * value);
	return *this;
}

inline PointF& PointF::operator/=(double value)
{
	assert(value != 0.0);
	this->x = Math::round(this->x / value);
	this->y = Math::round(this->y / value);
	return *this;
}

inline PointF operator-(const PointF& point) NOTHROW
{ return PointF(-point.x, -point.y); }

inline PointF operator+(const PointF& point1, const PointF& point2) NOTHROW
{ return PointF(point1.x + point2.x, point1.y + point2.y); }

inline PointF operator-(const PointF& point1, const PointF& point2) NOTHROW
{ return PointF(point1.x - point2.x, point1.y - point2.y); }

inline PointF operator*(const PointF& point, double value) NOTHROW
{ return PointF(Math::round(point.x * value), Math::round(point.y * value)); }

inline PointF operator*(double value, const PointF& point) NOTHROW
{ return PointF(Math::round(point.x * value), Math::round(point.y * value)); }

inline PointF operator/(const PointF& point, double value) NOTHROW
{
	assert(value != 0.0);
	return PointF(Math::round(point.x / value), Math::round(point.y / value));
}

inline bool operator==(const PointF& point1, const PointF& point2) NOTHROW
{ return (point1.x == point2.x && point1.y == point2.y); }

inline bool operator!=(const PointF& point1, const PointF& point2) NOTHROW
{ return (point1.x != point2.x || point1.y != point2.y); }

#endif // _POINT_H_
