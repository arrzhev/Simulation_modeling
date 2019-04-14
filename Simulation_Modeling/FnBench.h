#pragma once

#ifndef _FNBENCH_H_
#define _FNBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

/*
Bench for installation of fittings
*/
class FnBench : public Object
{
public:

	inline FnBench();
	inline virtual ~FnBench(){};
};

FnBench::FnBench()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 1427, 872 };
	sizeOnTex = { 310, 214 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/furnitureBench.tga";

}

#endif // _FNBENCH_H_