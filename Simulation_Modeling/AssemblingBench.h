#pragma once

#ifndef _ASSEMBLINGBENCH_H_
#define _ASSEMBLINGBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Door.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class AssemblingBench : public Object
{
public:

	AssemblingBench(const Settings& settings);

	/// <summary>Assembling door from board</summary>
	/// <param name="board">The board from wich the door is assembling</param>
	/// <param name="generator">Reference to the gnerator for simulating normal distribution</param>
	/// <returns> Door(can be already assembled or not)</returns>
	Door assembling(Board board, std::default_random_engine& generator);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }
	
	/// <summary> See <see cref="AssemblingBench.isBrokenWidth"/> </summary>
	inline void repairWidth(){ isBrokenWidth = false; }
	/// <summary> See <see cref="AssemblingBench.isBrokenHeight"/> </summary>
	inline void repairHeight(){ isBrokenHeight = false; }
	/// <summary> See <see cref="AssemblingBench.isBrokenCrack"/> </summary>
	inline void repairCrack(){ isBrokenCrack = false; }

	inline virtual ~AssemblingBench(){};

private:
	vector<Board> boards; // Array of boards from wich the door is assembling or already assembled
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	double m_width = 0.8; // Expected width of the doors assembled on the bench
	double sg_width = 0.02; // Width dispersion of the doors assembled on the bench
	double m_height = 2; // Expected height of the doors assembled on the bench
	double sg_height = 0.05; // Height dispersion of the doors assembled on the bench
	double upperCoef = 2; // Multiplying factor in the formula for calculating the number of boards for one door assembly

	///// The formula for calculating the number of boards for one door assembly /////

	//    n = (upperCoef * m_width * m_height) / (board_width * board_height)

	////////////////////////////////////////////////////////////////////////

	UINT numOfAssembledDoors = 0; // The number of doors assembled on the bench for all the time
	bool isBrokenWidth = false;   // Bench deffect, related to the wrong width of the doors assembled on it
	bool isBrokenHeight = false;  // Bench deffect, related to the wrong height of the doors assembled on it
	bool isBrokenCrack = false;   // Bench deffect, related to cracking doors assembled on it
};

#endif // _ASSEMBLINGBENCH_H_