#pragma once

#ifndef _DRYERBENCH_H_
#define _DRYERBENCH_H_

#include "stdafx.h"
#include "Object.h"
#include "Board.h"
#include "Brigade.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class DryerBench : public Object
{
public:

	DryerBench(const Settings& settings);
	
	/// <param name="board">Reference to the board to be dryed</param>
	/// <param name="generator">Reference to the gnerator for simulating normal distribution</param>
	void drying(Board& board, std::default_random_engine& generator);

	/// <summary>Setting brigade currently working on the bench </summary>
	inline void setBrigade(const Brigade& brigade) { this->brigade = &brigade; }

	/// <summary> See <see cref="DryerBench.isBrokenHumidity"/> </summary>
	inline void repairHumidity(){ isBrokenHumidity = false; }
	/// <summary> See <see cref="DryerBench.isBrokenCrack"/> </summary>
	inline void repairCrack(){ isBrokenCrack = false; }
	/// <summary> See <see cref="DryerBench.isBrokenDeformation"/> </summary>
	inline void repairDeformation(){ isBrokenDeformation = false; }

	inline virtual ~DryerBench(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
	const Brigade* brigade = nullptr; // The brigade currently working on the bench

	double m_humidity = 10; // Expected humidity of the board after drying
	double sg_humidity = 2; // Humidity dispersion of the board fter drying

	UINT numOfDryedBoards = 0; // The number of boards dryed on the bench for all the time
	bool isBrokenHumidity = false; // Bench deffect, related to the wrong humidity of the boards after drying
	bool isBrokenCrack = false;  // Bench deffect, related to cracking boards after drying
	bool isBrokenDeformation = false; // Bench deffect, related to deformating boards after drying
};

#endif // _DRYERBENCH_H_