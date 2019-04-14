#include "stdafx.h"
#include "Triangle.h"
#include "Line.h"
#include "Vec2.h"

//#include <boost/lexical_cast.hpp>

LineF Triangle::edge1() const
{ return LineF(this->p1, this->p2); }

LineF Triangle::edge2() const
{ return LineF(this->p2, this->p3); }

LineF Triangle::edge3() const
{ return LineF(this->p3, this->p1); }

// Проверяет, входит ли вершина в описанную окружность.
bool Triangle::circleContainsVertex(const PointF& p) const
{
	double len1 = Vec2(this->p1).lengthSquared();
	double len2 = Vec2(this->p2).lengthSquared();
	double len3 = Vec2(this->p3).lengthSquared();

	Vec2 circle;

	circle.x = (len1 * (this->p3.y - this->p2.y) + len2 * (this->p1.y - this->p3.y) + len3 * (this->p2.y - this->p1.y)) /
		       (this->p1.x * (this->p3.y - this->p2.y) + this->p2.x * (this->p1.y - this->p3.y) + this->p3.x * (this->p2.y - this->p1.y)) / 2.0;

	circle.y = (len1 * (this->p3.x - this->p2.x) + len2 * (this->p1.x - this->p3.x) + len3 * (this->p2.x - this->p1.x)) /
		       (this->p1.y * (this->p3.x - this->p2.x) + this->p2.y * (this->p1.x - this->p3.x) + this->p3.y * (this->p2.x - this->p1.x)) / 2.0;

	double radius   = circle.distance(this->p1);
	double distance = circle.distance(p);

	return (distance <= radius);
}

//std::string Triangle::toString() const
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "triangle{ [" + boost::lexical_cast<std::string>(this->p1.x) + ", " + boost::lexical_cast<std::string>(this->p1.y) + "], [" + boost::lexical_cast<std::string>(this->p2.x) + ", " + boost::lexical_cast<std::string>(this->p2.y) + "], [" + boost::lexical_cast<std::string>(this->p3.x) + ", " + boost::lexical_cast<std::string>(this->p3.y) + "] }";
//
//	std::locale::global(loc);
//
//	return str;
//}
