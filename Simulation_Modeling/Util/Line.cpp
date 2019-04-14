#include "stdafx.h"
#include "Line.h"

//#include <boost/lexical_cast.hpp>

Line::Line(const LineF& line) NOTHROW : p1(line.p1), p2(line.p2) {}
LineF::LineF(const Line& line) NOTHROW : p1(line.p1), p2(line.p2) {}

//std::string Line::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "line{ [" + boost::lexical_cast<std::string>(this->p1.x) + ", " + boost::lexical_cast<std::string>(this->p1.y) + "], [" + boost::lexical_cast<std::string>(this->p2.x) + ", " + boost::lexical_cast<std::string>(this->p2.y) + "] }";
//
//	std::locale::global(loc);
//
//	return str;
//}
//
//std::string LineF::toString() const NOTHROW
//{
//	std::locale loc;
//	std::locale::global(std::locale::classic());
//
//	std::string str = "line{ [" + boost::lexical_cast<std::string>(this->p1.x) + ", " + boost::lexical_cast<std::string>(this->p1.y) + "], [" + boost::lexical_cast<std::string>(this->p2.x) + ", " + boost::lexical_cast<std::string>(this->p2.y) + "] }";
//
//	std::locale::global(loc);
//
//	return str;
//}
