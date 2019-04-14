#pragma once

#ifndef _MILLINGBENCH_H_
#define _MILLINGBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class MillingBench : public Object
{
public:

	MillingBench(const Settings& settings);

	/// <param name="board">Reference to the board to be milled</param>
	/// <param name="generator">Reference to the gnerator for simulating normal distribution</param>
	void milling(Board& board, std::default_random_engine& generator);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }

	/// <summary> See <see cref="MillingBench.isBrokenLength"/> </summary>
	inline void repairLength(){ isBrokenLength = false; }
	/// <summary> See <see cref="MillingBench.isBrokenWidth"/> </summary>
	inline void repairWidth(){ isBrokenWidth = false; }
	/// <summary> See <see cref="MillingBench.isBrokenCrack"/> </summary>
	inline void repairCrack(){ isBrokenCrack = false; }

	inline virtual ~MillingBench(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	UINT numOfMilledBoards = 0; // The number of boards milled on the bench for all the time
	bool isBrokenLength = false; // Bench deffect, related to the wrong length of the boards after milling
	bool isBrokenWidth = false; // Bench deffect, related to the wrong width of the boards after milling
	bool isBrokenCrack = false; // Bench deffect, related to cracking boards after milling
};

#endif // _MILLINGBENCH_H_