#pragma once

#ifndef _PAINTINGBENCH_H_
#define _PAINTINGBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Door.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class PaintingBench : public Object
{
public:

	PaintingBench(const Settings& settings);

	/// <param name="door">Reference to the door to be painted</param>
	void painting(Door& door);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }

	/// <summary> See <see cref="PaintingBench.isBrokenPainting1"/> </summary>
	inline void repairPainting1() { isBrokenPainting1 = false; }
	/// <summary> See <see cref="PaintingBench.isBrokenPainting2"/> </summary>
	inline void repairPainting2() { isBrokenPainting2 = false; }
	/// <summary> See <see cref="PaintingBench.isBrokenPainting3"/> </summary>
	inline void repairPainting3() { isBrokenPainting3 = false; }

	inline virtual ~PaintingBench(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	UINT numOfPaintedDoors = 0;  // The number of doors painted on the bench for all the time
	bool isBrokenPainting1 = false; // Bench deffect, related to wrong painting of the first grade door
	bool isBrokenPainting2 = false; // Bench deffect, related to wrong painting of the second grade door
	bool isBrokenPainting3 = false;// Bench deffect, related to wrong painting of the third grade door
};

#endif // _PAINTINGBENCH_H_