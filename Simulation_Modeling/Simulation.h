#pragma once

#ifndef _Simulation_H_
#define _Simulation_H_

#include "stdafx.h"

#include "Settings.h"

#include "TimberLoader.h"
#include "PSBench.h"
#include "DryerBench.h"
#include "SortingBench.h"
#include "MillingBench.h"
#include "AssemblingBench.h"
#include "PaintingBench.h"
#include "PackingBench.h"
#include "FnBench.h"
#include "Brigade.h"
#include "Button.h"

#include "Timber.h"
#include "Board.h"
#include "Door.h"

#include <thread>
#include <mutex>

class Simulation
{
public:
	Settings settings; // Simulation settings

	TimberLoader timberLoader;
	PSBench pSBench;
	DryerBench dryerBench;
	SortingBench sortingBench;
	vector<MillingBench> millingBenchs;
	vector<AssemblingBench> assemblingBenchs;
	PaintingBench paintingBench;
	PackingBench packingBench;
	FnBench fnBench;
	vector<Brigade> brigades;
	Button firstGradeDoorButton;
	Button secondGradeDoorButton;
	Button thirdGradeDoorButton;

	vector<Timber> timbers;
	vector<Timber> shownTimbers;
	mutex timberMutex;
	vector<Board> boards;
	vector<Board> shownBoards;
	mutex boardMutex;
	vector<Door> doors;
	vector<Door> shownDoors;
	mutex doorMutex;

	bool isPlayed = false; // Set the simulation state (true - simalution is active; flase - not)
	unsigned int money = 0; // Player's money

	UINT pps = 80; // Curent pixel per second
	const UINT ppsNormal = 80; // Normal pixel per second

	Simulation(const Settings& set);

	void setBenchLocation();
	/// <summary>Generate initial timbers array according to settings</summary>
	void setTimbersParam();
	void setWndParams(UINT width, UINT height);

	/// <summary>Get number of the timbers last in the batches</summary>
	/// <returns>Array of the number of timbers remaining in batches(size - 10)</returns>
	std::vector<UINT> getLastInBatch();

	UINT getFirstGradeDoorsCount();
	UINT getSecondGradeDoorsCount();
	UINT getThirdGradeDoorsCount();

	/// <returns>Array of the number of 1 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</returns>
	vector<UINT> getFirstGradeDoorDefectsCount();
	/// <returns>Array of the number of 2 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</returns>
	vector<UINT> getFSecondGradeDoorDefectsCount();
	/// <returns>Array of the number of 3 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</returns>
	vector<UINT> getThirdGradeDoorDefectsCount();

	virtual ~Simulation();

private:
	bool exitFlag = false; // Flag to exit from main simulation thread
	std::thread mainCycle; // Main simulation thread

	UINT brigadesChangeRate = 20; // second per change

	UINT wndWidth = 0;
	UINT wndHeight = 0;

	/// <summary>Function to bedone in main simulation thred</summary>
	void doAction();
};


#endif //_Simulation_H_