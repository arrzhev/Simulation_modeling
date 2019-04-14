#pragma once

#ifndef _BENCH_H_
#define _BENCH_H_

#include "stdafx.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Object 
{
public:
	Vec2 posOnTex;
	Point sizeOnTex;
	Vec2 texSize;
	Point position;
	Vec2 size;
	string texPath;
	Vec2 haloSize = {0,0}; // Size of the "Halo" when object is selected
	bool isActive = true;

	/// <summary> Setting object position and size(based on window size) </summary>
	inline void setWndSize(const UINT& width, const UINT& height) 
	{
		position.x = width / (texSize.x / posOnTex.x);
		position.y = height / (texSize.y / posOnTex.y);
		size.x = width / (texSize.x / sizeOnTex.x);
		size.y = height / (texSize.y / sizeOnTex.y);
	}

	inline const bool isMouseOn(const UINT& x, const UINT& y) const
	{
		return (position.x + size.x - haloSize.x > x && position.x + haloSize.x < x && position.y + size.y - haloSize.y > y && position.y + haloSize.y < y);
	}
	inline const bool isMouseOn(const Point& p) const
	{
		
		return (position.x + size.x - haloSize.x > p.x && position.x + haloSize.x < p.x && position.y + size.y - haloSize.y > p.y && position.y + haloSize.y < p.y);
	}

	inline void setLocationOnTex(const Vec2& posOnTex, const Point& sizeOnTex, const Vec2& texSize, const Vec2& haloSize) { this->posOnTex = posOnTex; this->sizeOnTex = sizeOnTex; this->texSize = texSize; this->haloSize = haloSize; }
	inline void setLocationOnTex(const Vec2& posOnTex, const Point& sizeOnTex, const Vec2& texSize, const Vec2& haloSize, const string& texPath) { setLocationOnTex(posOnTex, sizeOnTex, texSize, haloSize); this->texPath = texPath; }

	virtual ~Object() = 0 {};
};

#endif // _BENCH_H_