#pragma once

#ifndef _VEC3_H_
#define _VEC3_H_

#include <cassert>

#include "Math.h"
#include "Defines.h"

class Vec2;
class Point;

// Трёхмерный вектор.
class Vec3
{
public:
	double x, y, z;

	inline Vec3() NOTHROW;
	inline Vec3(double x, double y, double z) NOTHROW;
	inline Vec3(const Vec3& point1, const Vec3& point2) NOTHROW;
	inline Vec3(const Vec3& vec) NOTHROW;

	Vec3(const Vec2& vec   , double z = 0.0) NOTHROW;
	Vec3(const Point& point, double z = 0.0) NOTHROW;

	inline void set  (double x, double y, double z) NOTHROW;
	inline void add  (double x, double y, double z) NOTHROW;
	inline void scale(double x, double y, double z) NOTHROW;

	// Проверяет на нулевой вектор.
	inline bool isNull() const NOTHROW;

	// Вычисляет длину вектора.
	inline double length() const NOTHROW;
	inline double lengthSquared() const NOTHROW;

	// Вычисляет квадрат расстояния между векторами.
	double distance(const Vec3& vec) const NOTHROW;

	// Вычисляет скалярное произведение векторов.
	double dot(const Vec3& vec) const NOTHROW;

	// Вычисляет угол между векторами.
	double angle(const Vec3& vec) const NOTHROW;

	// Нормализует вектор.
	void normalize() NOTHROW;
	Vec3 normalized() const NOTHROW;

	// Обнуляет вектор.
	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline Vec3& operator=(const Vec3& vec) NOTHROW;
	inline Vec3& operator=(double value) NOTHROW;

	inline Vec3& operator+=(const Vec3& vec) NOTHROW;
	inline Vec3& operator+=(double value) NOTHROW;

	inline Vec3& operator-=(const Vec3& vec) NOTHROW;
	inline Vec3& operator-=(double value) NOTHROW;

	inline Vec3& operator*=(double value) NOTHROW;
	inline Vec3& operator/=(double value);

	inline double& operator[](int i);
	inline double  operator[](int i) const;

	friend inline Vec3 operator-(const Vec3& vec) NOTHROW;

	friend inline Vec3 operator+(const Vec3& vec1, const Vec3& vec2) NOTHROW;
	friend inline Vec3 operator+(const Vec3& vec, double value) NOTHROW;

	friend inline Vec3 operator-(const Vec3& vec1, const Vec3& vec2) NOTHROW;
	friend inline Vec3 operator-(const Vec3& vec, double value) NOTHROW;

	friend inline Vec3 operator*(const Vec3& vec, double value) NOTHROW;
	friend inline Vec3 operator/(const Vec3& vec, double value);

	friend inline bool operator==(const Vec3& vec1, const Vec3& vec2) NOTHROW;
	friend inline bool operator!=(const Vec3& vec1, const Vec3& vec2) NOTHROW;
};

inline Vec3::Vec3() NOTHROW : x(0.0) , y(0.0) , z(0.0) {}
inline Vec3::Vec3(double x, double y, double z) NOTHROW : x(x), y(y), z(z) {}

inline Vec3::Vec3(const Vec3& point1, const Vec3& point2) NOTHROW
	: x(point1.x - point2.x)
	, y(point1.y - point2.y)
	, z(point1.z - point2.z)
{}

inline Vec3::Vec3(const Vec3& vec) NOTHROW : x(vec.x) , y(vec.y) , z(vec.z) {}

inline void Vec3::set(double x, double y, double z) NOTHROW
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void Vec3::add(double x, double y, double z) NOTHROW
{
	this->x += x;
	this->y += y;
	this->z += z;
}

inline void Vec3::scale(double x, double y, double z) NOTHROW
{
	this->x *= x;
	this->y *= y;
	this->z *= z;
}

// Проверяет на нулевой вектор.
inline bool Vec3::isNull() const NOTHROW
{ return ((this->x == 0.0) && (this->y == 0.0) && (this->z == 0.0)); }

// Вычисляет длину вектора.
inline double Vec3::length() const NOTHROW
{ return sqrt(this->lengthSquared()); }

inline double Vec3::lengthSquared() const NOTHROW
{ return (this->x * this->x + this->y * this->y + this->z * this->z); }

// Обнуляет вектор.
inline void Vec3::clear() NOTHROW
{ this->set(0.0, 0.0, 0.0); }

inline Vec3& Vec3::operator=(const Vec3& vec) NOTHROW
{
	this->set(vec.x, vec.y, vec.z);
	return *this;
}

inline Vec3& Vec3::operator=(double value) NOTHROW
{
	this->set(value, value, value);
	return *this;
}

inline Vec3& Vec3::operator+=(const Vec3& vec) NOTHROW
{
	this->add(vec.x, vec.y, vec.z);
	return *this;
}

inline Vec3& Vec3::operator+=(double value) NOTHROW
{
	this->add(value, value, value);
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& vec) NOTHROW
{
	this->add(-vec.x, -vec.y, -vec.z);
	return *this;
}

inline Vec3& Vec3::operator-=(double value) NOTHROW
{
	this->add(-value, -value, -value);
	return *this;
}

inline Vec3& Vec3::operator*=(double value) NOTHROW
{
	this->scale(value, value, value);
	return *this;
}

inline Vec3& Vec3::operator/=(double value)
{
	assert(value != 0.0);
	this->x /= value;
	this->y /= value;
	this->z /= value;
	return *this;
}

inline double& Vec3::operator[](int i)
{
	assert(uint(i) < 3);
	return *(&this->x + i);
}

inline double Vec3::operator[](int i) const
{
	assert(uint(i) < 3);
	return *(&this->x + i);
}

inline Vec3 operator-(const Vec3& vec) NOTHROW
{ return Vec3(-vec.x, -vec.y, -vec.z); }

inline Vec3 operator+(const Vec3& vec1, const Vec3& vec2) NOTHROW
{ return Vec3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z); }

inline Vec3 operator+(const Vec3& vec, double value) NOTHROW
{ return Vec3(vec.x + value, vec.y + value, vec.z + value); }

inline Vec3 operator-(const Vec3& vec1, const Vec3& vec2) NOTHROW
{ return Vec3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z); }

inline Vec3 operator-(const Vec3& vec, double value) NOTHROW
{ return Vec3(vec.x - value, vec.y - value, vec.z - value); }

inline Vec3 operator*(const Vec3& vec, double value) NOTHROW
{ return Vec3(vec.x * value, vec.y * value, vec.z * value); }

inline Vec3 operator/(const Vec3& vec, double value)
{
	assert(value != 0.0);
	return Vec3(vec.x + value, vec.y + value, vec.z + value);
}

inline bool operator==(const Vec3& vec1, const Vec3& vec2) NOTHROW
{ return (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z); }

inline bool operator!=(const Vec3& vec1, const Vec3& vec2) NOTHROW
{ return (vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z); }

#endif // _VEC3_H_
