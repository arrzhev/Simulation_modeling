#pragma once

#ifndef _MATH_H_
#define _MATH_H_

#define _USE_MATH_DEFINES
#include <math.h>

#include "Defines.h"

// Дополнительные математические функции.
namespace Math
{
	inline double rad(double angle);
	inline double deg(double angle);

	inline float rad(float angle);
	inline float deg(float angle);

	inline int ceil (double value);
	inline int round(double value);
	inline int floor(double value);

	inline int ceil (float value);
	inline int round(float value);
	inline int floor(float value);
};

inline double Math::rad(double angle)
{ return (M_PI * angle / 180.0); }

inline double Math::deg(double angle)
{ return (180.0 * angle / M_PI); }

inline float Math::rad(float angle)
{ return ((float)M_PI * angle / 180.0f); }

inline float Math::deg(float angle)
{ return (180.0f * angle / (float)M_PI); }

inline int Math::ceil(double value)
{ return (int)(value + 1.0); }

inline int Math::round(double value)
{ return ((value - (double)((int)value)) > 0.5 ? ceil(value) : floor(value)); }

inline int Math::floor(double value)
{ return (int)value; }

inline int Math::ceil(float value)
{ return (int)(value + 1.0f); }

inline int Math::round(float value)
{ return ((value - (float)((int)value)) > 0.5f ? ceil(value) : floor(value)); }

inline int Math::floor(float value)
{ return (int)value; }

#endif // _MATH_H_
