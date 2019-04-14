#include "stdafx.h"
#include "Point.h"

//#include <boost/lexical_cast.hpp>

Point::Point(const PointF& point) NOTHROW : x((int)point.x), y((int)point.y) {}
PointF::PointF(const Point& point) NOTHROW : x((double)point.x), y((double)point.y) {}

//std::string Point::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "point[" + boost::lexical_cast<std::string>(this->x) + ", " + boost::lexical_cast<std::string>(this->y) + "]";
//
//	std::locale::global(loc);
//
//	return str;
//}
//
//std::string PointF::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "point[" + boost::lexical_cast<std::string>(this->x) + ", " + boost::lexical_cast<std::string>(this->y) + "]";
//
//	std::locale::global(loc);
//
//	return str;
//}
