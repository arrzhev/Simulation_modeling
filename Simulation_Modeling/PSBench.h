#pragma once

#ifndef _PSBENCH_H_
#define _PSBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Timber.h"
#include "Board.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

/*
Power-saw bench
*/
class PSBench : public Object
{
public:

	PSBench(const Settings& settings);

	/// <summary>Sawing timber on boards</summary>
	/// <param name="timber">Const reference to the timber to be sawed</param>
	/// <param name="generator">Reference to the gnerator for simulating normal distribution</param>
	/// <returns> Array of the boards </returns>
	vector<Board> sawing(const Timber& timber, std::default_random_engine& generator);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }

	/// <summary> See <see cref="PSBench.isBrokenLength"/> </summary>
	inline void repairLength() { isBrokenLength = false; }
	/// <summary> See <see cref="PSBench.isBrokenWidth"/> </summary>
	inline void repairWidth(){ isBrokenWidth = false; }
	/// <summary> See <see cref="PSBench.isBrokenCrack"/> </summary>
	inline void repairCrack() { isBrokenCrack = false; }

	inline virtual ~PSBench(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	UINT numOfSawnTimbers = 0;  // The number of timber sawed on the bench for all the time
	bool isBrokenLength = false;  // Bench deffect, related to the wrong length of the boards after sawing
	bool isBrokenWidth = false;   // Bench deffect, related to the wrong width of the boards after sawing
	bool isBrokenCrack = false;    // Bench deffect, related to cracking boards after sawing

};

#endif // _PSBENCH_H_