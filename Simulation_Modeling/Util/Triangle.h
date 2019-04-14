#pragma once

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <cassert>

#include "Point.h"

class Line;
class LineF;

// Описывает треугольник.
class Triangle
{
public:
	PointF p1, p2, p3;

	inline Triangle();
	inline Triangle(const PointF& p1, const PointF& p2, const PointF& p3);
	inline Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	inline Triangle(const Triangle& triangle);

	inline void set(const PointF& p1, const PointF& p2, const PointF& p3);
	inline void set(double x1, double y1, double x2, double y2, double x3, double y3);

	LineF edge1() const;
	LineF edge2() const;
	LineF edge3() const;

	// Преверяет, является ли точка вершиной треугольника.
	inline bool hasVertex(const PointF& p) const;

	// Проверяет, входит ли вершина в описанную окружность.
	bool circleContainsVertex(const PointF& p) const;

	inline void clear();

	//std::string toString() const;

	inline Triangle& operator=(const Triangle& triangle);

	inline const PointF& operator[](int i) const;
	inline PointF& operator[](int i);

	friend inline bool operator==(const Triangle& triangle1, const Triangle& triangle2);
	friend inline bool operator!=(const Triangle& triangle1, const Triangle& triangle2);
};

inline Triangle::Triangle() : p1(), p2(), p3() {}
inline Triangle::Triangle(const PointF& p1, const PointF& p2, const PointF& p3) : p1(p1), p2(p2), p3(p3) {}
inline Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}
inline Triangle::Triangle(const Triangle& triangle) : p1(triangle.p1), p2(triangle.p2), p3(triangle.p3) {}

inline void Triangle::set(const PointF& p1, const PointF& p2, const PointF& p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

inline void Triangle::set(double x1, double y1, double x2, double y2, double x3, double y3)
{ this->set(PointF(x1, y1), PointF(x2, y2), PointF(x3, y3)); }

// Преверяет, является ли точка вершиной треугольника.
inline bool Triangle::hasVertex(const PointF& p) const
{ return (this->p1 == p || this->p2 == p || this->p3 == p); }

inline void Triangle::clear()
{ this->set(PointF(), PointF(), PointF()); }

inline Triangle& Triangle::operator=(const Triangle& triangle)
{
	this->set(triangle.p1, triangle.p2, triangle.p3);
	return *this;
}

inline const PointF& Triangle::operator[](int i) const
{
	assert(uint(i) < 3);
	return *(&this->p1 + i);
}

inline PointF& Triangle::operator[](int i)
{
	assert(uint(i) < 3);
	return *(&this->p1 + i);
}

inline bool operator==(const Triangle& t1, const Triangle& t2)
{
	return (t1.p1 == t2.p1 || t1.p1 == t2.p2 || t1.p1 == t2.p3) &&
		   (t1.p2 == t2.p1 || t1.p2 == t2.p2 || t1.p2 == t2.p3) &&
		   (t1.p3 == t2.p1 || t1.p3 == t2.p2 || t1.p3 == t2.p3);
}

inline bool operator!=(const Triangle& t1, const Triangle& t2)
{ return !(t1 == t2); }

#endif // _TRIANGLE_H_
