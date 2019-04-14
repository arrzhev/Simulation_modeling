#pragma once

#ifndef _VEC2_H_
#define _VEC2_H_
#include "Math.h"
#include <cassert>


#include "Defines.h"

class Vec3;
class Point;
class PointF;

// Двумерный вектор.
class Vec2
{
public:
	double x, y;

	inline Vec2() NOTHROW;
	inline Vec2(double x, double y) NOTHROW;
	inline Vec2(const Vec2& point1, const Vec2& point2) NOTHROW;
	inline Vec2(const Vec2& vec) NOTHROW;

	Vec2(const Vec3& vec) NOTHROW;
	Vec2(const Point& point) NOTHROW;
	Vec2(const PointF& point) NOTHROW;

	inline void set  (double x, double y) NOTHROW;
	inline void add  (double x, double y) NOTHROW;
	inline void scale(double x, double y) NOTHROW;

	// Проверяет на нулевой вектор.
	inline bool isNull() const NOTHROW;

	// Вычисляет длину вектора.
	inline double length() const NOTHROW;
	inline double lengthSquared() const NOTHROW;

	// Вычисляет квадрат расстояния между векторами.
	double distance(const Vec2& vec) const NOTHROW;

	// Вычисляет скалярное произведение векторов.
	double dot(const Vec2& vec) const NOTHROW;

	// Вычисляет угол между векторами.
	double angle(const Vec2& vec) const NOTHROW;

	// Нормализует вектор.
	void normalize() NOTHROW;
	Vec2 normalized() const NOTHROW;

	// Обнуляет вектор.
	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline Vec2& operator=(const Vec2& vec) NOTHROW;
	inline Vec2& operator=(double value) NOTHROW;

	inline Vec2& operator+=(const Vec2& vec) NOTHROW;
	inline Vec2& operator+=(double value) NOTHROW;

	inline Vec2& operator-=(const Vec2& vec) NOTHROW;
	inline Vec2& operator-=(double value) NOTHROW;

	inline Vec2& operator*=(double value) NOTHROW;
	inline Vec2& operator/=(double value);

	inline double& operator[](int i);
	inline double  operator[](int i) const;

	friend inline Vec2 operator-(const Vec2& vec) NOTHROW;

	friend inline Vec2 operator+(const Vec2& vec1, const Vec2& vec2) NOTHROW;
	friend inline Vec2 operator+(const Vec2& vec, double value) NOTHROW;

	friend inline Vec2 operator-(const Vec2& vec1, const Vec2& vec2) NOTHROW;
	friend inline Vec2 operator-(const Vec2& vec, double value) NOTHROW;

	friend inline Vec2 operator*(const Vec2& vec, double value) NOTHROW;
	friend inline Vec2 operator/(const Vec2& vec, double value);

	friend inline bool operator==(const Vec2& vec1, const Vec2& vec2) NOTHROW;
	friend inline bool operator!=(const Vec2& vec1, const Vec2& vec2) NOTHROW;
};

inline Vec2::Vec2() NOTHROW : x(0.0) , y(0.0) {}
inline Vec2::Vec2(double x, double y) NOTHROW : x(x) , y(y) {}

inline Vec2::Vec2(const Vec2& vec) NOTHROW : x(vec.x) , y(vec.y) {}

inline void Vec2::set(double x, double y) NOTHROW
{
	this->x = x;
	this->y = y;
}

inline void Vec2::add(double x, double y) NOTHROW
{
	this->x += x;
	this->y += y;
}

inline void Vec2::scale(double x, double y) NOTHROW
{
	this->x *= x;
	this->y *= y;
}

// Проверяет на нулевой вектор.
inline bool Vec2::isNull() const NOTHROW
{ return ((this->x == 0.0) && (this->y == 0.0)); }

// Вычисляет длину вектора.
inline double Vec2::length() const NOTHROW
{ return sqrt(this->lengthSquared()); }

inline double Vec2::lengthSquared() const NOTHROW
{ return (this->x * this->x + this->y * this->y); }

// Обнуляет вектор.
inline void Vec2::clear() NOTHROW
{ this->set(0.0, 0.0); }

inline Vec2& Vec2::operator=(const Vec2& vec) NOTHROW
{
	this->set(vec.x, vec.y);
	return *this;
}

inline Vec2& Vec2::operator=(double value) NOTHROW
{
	this->set(value, value);
	return *this;
}

inline Vec2& Vec2::operator+=(const Vec2& vec) NOTHROW
{
	this->add(vec.x, vec.y);
	return *this;
}

inline Vec2& Vec2::operator+=(double value) NOTHROW
{
	this->add(value, value);
	return *this;
}

inline Vec2& Vec2::operator-=(const Vec2& vec) NOTHROW
{
	this->add(-vec.x, -vec.y);
	return *this;
}

inline Vec2& Vec2::operator-=(double value) NOTHROW
{
	this->add(-value, -value);
	return *this;
}

inline Vec2& Vec2::operator*=(double value) NOTHROW
{
	this->scale(value, value);
	return *this;
}

inline Vec2& Vec2::operator/=(double value)
{
	assert(value != 0.0);
	this->x /= value;
	this->y /= value;
	return *this;
}

inline double& Vec2::operator[](int i)
{
	assert(uint(i) < 2);
	return *(&this->x + i);
}

inline double Vec2::operator[](int i) const
{
	assert(uint(i) < 2);
	return *(&this->x + i);
}

inline Vec2 operator-(const Vec2& vec) NOTHROW
{ return Vec2(-vec.x, -vec.y); }

inline Vec2 operator+(const Vec2& vec1, const Vec2& vec2) NOTHROW
{ return Vec2(vec1.x + vec2.x, vec1.y + vec2.y); }

inline Vec2 operator+(const Vec2& vec, double value) NOTHROW
{ return Vec2(vec.x + value, vec.y + value); }

inline Vec2 operator-(const Vec2& vec1, const Vec2& vec2) NOTHROW
{ return Vec2(vec1.x - vec2.x, vec1.y - vec2.y); }

inline Vec2 operator-(const Vec2& vec, double value) NOTHROW
{ return Vec2(vec.x - value, vec.y - value); }

inline Vec2 operator*(const Vec2& vec, double value) NOTHROW
{ return Vec2(vec.x * value, vec.y * value); }

inline Vec2 operator/(const Vec2& vec, double value)
{
	assert(value != 0.0);
	return Vec2(vec.x + value, vec.y + value);
}

inline bool operator==(const Vec2& vec1, const Vec2& vec2) NOTHROW
{ return (vec1.x == vec2.x && vec1.y == vec2.y); }

inline bool operator!=(const Vec2& vec1, const Vec2& vec2) NOTHROW
{ return (vec1.x != vec2.x || vec1.y != vec2.y); }

#endif // _VEC2_H_
