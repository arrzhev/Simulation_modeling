#pragma once

#ifndef _LINE_H_
#define _LINE_H_

#include "Point.h"

class Line;
class LineF;

// Двумерная прямая линия.
class Line
{
public:
	Point p1, p2;

	inline Line() NOTHROW;
	inline Line(const Point& p1, const Point& p2) NOTHROW;
	inline Line(int x1, int y1, int x2, int y2) NOTHROW;
	inline Line(const Line& line) NOTHROW;

	Line(const LineF& line) NOTHROW;

	inline void set(const Point& p1, const Point& p2) NOTHROW;
	inline void set(int x1, int y1, int x2, int y2) NOTHROW;

	inline bool isNull() const NOTHROW;

	// Вычисляет длину линии.
	inline double length() const NOTHROW;
	inline double lengthSquared() const NOTHROW;

	inline void translate(const Point& p) NOTHROW;
	inline void translate(int dx, int dy) NOTHROW;

	inline Line translated(const Point& p) const NOTHROW;
	inline Line translated(int dx, int dy) const NOTHROW;

	// Обнуляет координаты вершин.
	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline Line& operator=(const Line& line) NOTHROW;

	friend inline bool operator==(const Line& l1, const Line& l2) NOTHROW;
	friend inline bool operator!=(const Line& l1, const Line& l2) NOTHROW;
};

inline Line::Line() NOTHROW : p1(), p2() {}
inline Line::Line(const Point& p1, const Point& p2) NOTHROW : p1(p1), p2(p2) {}
inline Line::Line(int x1, int y1, int x2, int y2) NOTHROW : p1(x1, y1), p2(x2, y2) {}
inline Line::Line(const Line& line) NOTHROW : p1(line.p1), p2(line.p2) {}

inline void Line::set(const Point& p1, const Point& p2) NOTHROW
{
	this->p1 = p1;
	this->p2 = p2;
}

inline void Line::set(int x1, int y1, int x2, int y2) NOTHROW
{ this->set(Point(x1, y1), Point(x2, y2)); }

inline bool Line::isNull() const NOTHROW
{ return (this->p1 == this->p2); }

// Вычисляет длину линии.
inline double Line::length() const NOTHROW
{ return sqrt(this->lengthSquared()); }

inline double Line::lengthSquared() const NOTHROW
{
	return (this->p1.x - this->p2.x) * (this->p1.x - this->p2.x) +
	       (this->p1.y - this->p2.y) * (this->p1.y - this->p2.y);
}

inline void Line::translate(const Point& p) NOTHROW
{
	this->p1 += p;
	this->p2 += p;
}

inline void Line::translate(int dx, int dy) NOTHROW
{ this->translate(Point(dx, dy)); }

inline Line Line::translated(const Point& p) const NOTHROW
{ return Line(this->p1 + p, this->p2 + p); }

inline Line Line::translated(int dx, int dy) const NOTHROW
{ return this->translated(Point(dx, dy)); }

// Обнуляет координаты вершин.
inline void Line::clear() NOTHROW
{ this->set(0, 0, 0, 0); }

inline Line& Line::operator=(const Line& line) NOTHROW
{
	this->set(line.p1, line.p2);
	return *this;
}

inline bool operator==(const Line& l1, const Line& l2) NOTHROW
{
	return (l1.p1 == l2.p1 && l1.p2 == l2.p2) ||
           (l1.p1 == l2.p2 && l1.p2 == l2.p1);
}

inline bool operator!=(const Line& l1, const Line& l2) NOTHROW
{
	return (l1.p1 != l2.p1 || l1.p2 != l2.p2) &&
	       (l1.p1 != l2.p2 || l1.p2 != l2.p1);
}



// Двумерная прямая линия.
class LineF
{
public:
	PointF p1, p2;

	inline LineF() NOTHROW;
	inline LineF(const PointF& p1, const PointF& p2) NOTHROW;
	inline LineF(double x1, double y1, double x2, double y2) NOTHROW;
	inline LineF(const LineF& line) NOTHROW;

	LineF(const Line& line) NOTHROW;

	inline void set(const PointF& p1, const PointF& p2) NOTHROW;
	inline void set(double x1, double y1, double x2, double y2) NOTHROW;

	inline bool isNull() const NOTHROW;

	// Вычисляет длину линии.
	inline double length() const NOTHROW;
	inline double lengthSquared() const NOTHROW;

	inline void translate(const PointF& p) NOTHROW;
	inline void translate(double dx, double dy) NOTHROW;

	inline LineF translated(const PointF& p) const NOTHROW;
	inline LineF translated(double dx, double dy) const NOTHROW;

	// Обнуляет координаты вершин.
	inline void clear() NOTHROW;

	//std::string toString() const NOTHROW;

	inline LineF& operator=(const LineF& line) NOTHROW;

	friend inline bool operator==(const LineF& l1, const LineF& l2) NOTHROW;
	friend inline bool operator!=(const LineF& l1, const LineF& l2) NOTHROW;
};

inline LineF::LineF() NOTHROW : p1(), p2() {}
inline LineF::LineF(const PointF& p1, const PointF& p2) NOTHROW : p1(p1), p2(p2) {}
inline LineF::LineF(double x1, double y1, double x2, double y2) NOTHROW : p1(x1, y1), p2(x2, y2) {}
inline LineF::LineF(const LineF& line) NOTHROW : p1(line.p1), p2(line.p2) {}

inline void LineF::set(const PointF& p1, const PointF& p2) NOTHROW
{
	this->p1 = p1;
	this->p2 = p2;
}

inline void LineF::set(double x1, double y1, double x2, double y2) NOTHROW
{ this->set(PointF(x1, y1), PointF(x2, y2)); }

inline bool LineF::isNull() const NOTHROW
{ return (this->p1 == this->p2); }

// Вычисляет длину линии.
inline double LineF::length() const NOTHROW
{ return sqrt(this->lengthSquared()); }

inline double LineF::lengthSquared() const NOTHROW
{
	return (this->p1.x - this->p2.x) * (this->p1.x - this->p2.x) +
	       (this->p1.y - this->p2.y) * (this->p1.y - this->p2.y);
}

inline void LineF::translate(const PointF& p) NOTHROW
{
	this->p1 += p;
	this->p2 += p;
}

inline void LineF::translate(double dx, double dy) NOTHROW
{ this->translate(PointF(dx, dy)); }

inline LineF LineF::translated(const PointF& p) const NOTHROW
{ return LineF(this->p1 + p, this->p2 + p); }

inline LineF LineF::translated(double dx, double dy) const NOTHROW
{ return this->translated(PointF(dx, dy)); }

// Обнуляет координаты вершин.
inline void LineF::clear() NOTHROW
{ this->set(0.0, 0.0, 0.0, 0.0); }

inline LineF& LineF::operator=(const LineF& line) NOTHROW
{
	this->set(line.p1, line.p2);
	return *this;
}

inline bool operator==(const LineF& l1, const LineF& l2) NOTHROW
{
	return (l1.p1 == l2.p1 && l1.p2 == l2.p2) ||
           (l1.p1 == l2.p2 && l1.p2 == l2.p1);
}

inline bool operator!=(const LineF& l1, const LineF& l2) NOTHROW
{
	return (l1.p1 != l2.p1 || l1.p2 != l2.p2) &&
           (l1.p1 != l2.p2 || l1.p2 != l2.p1);
}

#endif // _LINE_H_
