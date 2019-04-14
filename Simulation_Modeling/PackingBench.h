#pragma once

#ifndef _PACKINGBENCH_H_
#define _PACKINGBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class PackingBench : public Object
{
public:

	inline PackingBench();

	inline virtual ~PackingBench(){};

};


PackingBench::PackingBench()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 1446, 32 };
	sizeOnTex = { 360, 842 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/packingBench.tga";

}

#endif // _PACKINGBENCH_H_