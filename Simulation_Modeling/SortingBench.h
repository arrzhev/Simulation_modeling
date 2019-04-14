#pragma once

#ifndef _SORTINGBENCH_H_
#define _SORTINGBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class SortingBench : public Object
{
public:

	SortingBench(const Settings& settings);

	/// <param name="board">Reference to the board to be sorted</param>
	void sorting(Board& board);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }

	/// <summary> See <see cref="SortingBench.isBrokenHumidity1"/> </summary>
	inline void repairHumidity1(){ isBrokenHumidity1 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenKnotCount1"/> </summary>
	inline void repairKnotCount1(){ isBrokenKnotCount1 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenMould1"/> </summary>
	inline void repairMould1(){ isBrokenMould1 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenCrack1"/> </summary>
	inline void repairCrack1(){ isBrokenCrack1 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenDeformation1"/> </summary>
	inline void repairDeformation1(){ isBrokenDeformation1 = false; }

	/// <summary> See <see cref="SortingBench.isBrokenHumidity2"/> </summary>
	inline void repairHumidity2(){ isBrokenHumidity2 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenKnotCount2"/> </summary>
	inline void repairKnotCount2(){ isBrokenKnotCount2 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenMould2"/> </summary>
	inline void repairMould2(){ isBrokenMould2 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenCrack2"/> </summary>
	inline void repairCrack2(){ isBrokenCrack2 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenDeformation2"/> </summary>
	inline void repairDeformation2(){ isBrokenDeformation2 = false; }

	/// <summary> See <see cref="SortingBench.isBrokenHumidity3"/> </summary>
	inline void repairHumidity3(){ isBrokenHumidity3 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenKnotCount3"/> </summary>
	inline void repairKnotCount3(){ isBrokenKnotCount3 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenMould3"/> </summary>
	inline void repairMould3(){ isBrokenMould3 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenCrack3"/> </summary>
	inline void repairCrack3(){ isBrokenCrack3 = false; }
	/// <summary> See <see cref="SortingBench.isBrokenDeformation3"/> </summary>
	inline void repairDeformation3(){ isBrokenDeformation3 = false; }

	inline virtual ~SortingBench(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	UINT numOfSortedBoards = 0;  // The number of boards sprted on the bench for all the time

	bool isBrokenHumidity1 = false;  // Bench deffect, related to the wrong sorting by humidity for 1 grade boards
	bool isBrokenKnotCount1 = false; // Bench deffect, related to the wrong sorting by knot count for 1 grade boards
	bool isBrokenMould1 = false; // Bench deffect, related to the wrong sorting by mould for 1 grade boards
	bool isBrokenCrack1 = false; // Bench deffect, related to the wrong sorting by crack for 1 grade boards
	bool isBrokenDeformation1 = false; // Bench deffect, related to the wrong sorting by deformation for 1 grade boards

	bool isBrokenHumidity2 = false;  // Bench deffect, related to the wrong sorting by humidity for 2 grade boards
	bool isBrokenKnotCount2 = false; // Bench deffect, related to the wrong sorting by knot count for 2 grade boards
	bool isBrokenMould2 = false; // Bench deffect, related to the wrong sorting by mould for 2 grade boards
	bool isBrokenCrack2 = false; // Bench deffect, related to the wrong sorting by crack for 2 grade boards
	bool isBrokenDeformation2 = false; // Bench deffect, related to the wrong sorting by deformation for 2 grade boards

	bool isBrokenHumidity3 = false;  // Bench deffect, related to the wrong sorting by humidity for 3 grade boards
	bool isBrokenKnotCount3 = false;  // Bench deffect, related to the wrong sorting by knot count for 3 grade boards
	bool isBrokenMould3 = false; // Bench deffect, related to the wrong sorting by mould for 3 grade boards
	bool isBrokenCrack3 = false; // Bench deffect, related to the wrong sorting by crack for 3 grade boards
	bool isBrokenDeformation3 = false; // Bench deffect, related to the wrong sorting by deformation for 3 grade boards
};

#endif // _SORTINGBENCH_H_