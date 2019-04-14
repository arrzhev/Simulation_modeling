#include "Simulation.h"

Simulation::Simulation(const Settings& set)
	: mainCycle(&Simulation::doAction, this), settings(set)
	, pSBench(settings)
	, dryerBench(settings)
	, sortingBench(settings)
	, millingBenchs({MillingBench(settings), MillingBench(settings), MillingBench(settings)})
	, assemblingBenchs({AssemblingBench(settings), AssemblingBench(settings), AssemblingBench(settings)})
	, paintingBench(settings)
	, brigades({ Brigade(settings), Brigade(settings), Brigade(settings) })
{

	for (int i = 0; i < 3; i++)
		brigades[i].setEffectiveCoef(settings.ninthSetList.brigade[i].effectiveCoef);
	brigades[0].isActive = true;

	pSBench.setBrigade(brigades[0]);
	dryerBench.setBrigade(brigades[0]);
	sortingBench.setBrigade(brigades[0]);
	paintingBench.setBrigade(brigades[0]);
	for (auto& millingBench : millingBenchs)
		millingBench.setBrigade(brigades[0]);
	for (auto& assemblingBench : assemblingBenchs)
		assemblingBench.setBrigade(brigades[0]);

	setBenchLocation();
	setTimbersParam();

	money = settings.firstSetList.money;
}

void Simulation::setBenchLocation()
{
	Vec2 texSize(1918, 1091);

	timberLoader.setLocationOnTex({ 88, 774 }, { 250, 312 }, texSize, {30,15});
	pSBench.setLocationOnTex({ 8, 390 }, { 382, 244 }, texSize, { 24, 20 });
	dryerBench.setLocationOnTex({ -20, -20 }, { 370, 266 }, texSize, { 22, 24 });
	sortingBench.setLocationOnTex({ 434, -40 }, { 1030, 310 }, texSize, { 30, 44 });
	millingBenchs[0].setLocationOnTex({ 390, 280 }, { 400, 280 }, texSize, { 40, 12 }, "images/benches/millingBench1.tga");
	millingBenchs[1].setLocationOnTex({ 770, 280 }, { 350, 280 }, texSize, { 36, 12 }, "images/benches/millingBench2.tga");
	millingBenchs[2].setLocationOnTex({ 1086, 280 }, { 380, 280 }, texSize, { 26, 16 }, "images/benches/millingBench3.tga");
	assemblingBenchs[0].setLocationOnTex({ 494, 556 }, { 248, 284 }, texSize, { 24, 12 }, "images/benches/assemblingBench1.tga");
	assemblingBenchs[1].setLocationOnTex({ 810, 556 }, { 262, 284 }, texSize, { 24, 12 }, "images/benches/assemblingBench2.tga");
	assemblingBenchs[2].setLocationOnTex({ 1136, 556 }, { 248, 284 }, texSize, { 22, 12 }, "images/benches/assemblingBench3.tga");
	paintingBench.setLocationOnTex({ 350, 800 }, { 1150, 370 }, texSize, { 50, 50 });
	packingBench.setLocationOnTex({ 1446, 32 }, { 360, 842 }, texSize, { 0, 0 });
	fnBench.setLocationOnTex({ 1427, 872 }, { 310, 214 }, texSize, {0,0});
	brigades[0].employee1.setLocationOnTex({ 414, 586 }, { 120, 222 }, texSize, { 15, 15 }, "images/benches/1brigade1employee.tga");
	brigades[0].employee2.setLocationOnTex({ 706, 600 }, { 160, 210 }, texSize, { 15, 15 }, "images/benches/1brigade2employee.tga");
	brigades[0].employee3.setLocationOnTex({ 1062, 594 }, { 120, 222 }, texSize, { 15, 15 }, "images/benches/1brigade3employee.tga");
	brigades[1].employee1.setLocationOnTex({ 412, 586 }, { 120, 230 }, texSize, { 15, 15 }, "images/benches/2brigade1employee.tga");
	brigades[1].employee2.setLocationOnTex({ 740, 586 }, { 120, 230 }, texSize, { 15, 15 }, "images/benches/2brigade2employee.tga");
	brigades[1].employee3.setLocationOnTex({ 1026, 590 }, { 160, 230 }, texSize, { 15, 15 }, "images/benches/2brigade3employee.tga");
	brigades[2].employee1.setLocationOnTex({ 412, 596 }, { 120, 230 }, texSize, { 15, 15 }, "images/benches/3brigade1employee.tga");
	brigades[2].employee2.setLocationOnTex({ 740, 586 }, { 120, 230 }, texSize, { 15, 15 }, "images/benches/3brigade2employee.tga");
	brigades[2].employee3.setLocationOnTex({ 1034, 590 }, { 160, 230 }, texSize, { 15, 15 }, "images/benches/3brigade3employee.tga");
	firstGradeDoorButton.setLocationOnTex({ 1820, 695 }, { 50, 60 }, texSize, { 0, 0 }, "images/button.tga");
	secondGradeDoorButton.setLocationOnTex({ 1820, 415 }, { 50, 60 }, texSize, { 0, 0 }, "images/button.tga");
	thirdGradeDoorButton.setLocationOnTex({ 1820, 155 }, { 50, 60 }, texSize, { 0, 0 }, "images/button.tga");
}

void Simulation::setTimbersParam()
{
	srand(time(0));
	if (&settings)
	{
		std::default_random_engine generator;
		generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < settings.firstSetList.batch[i].count; j++)
			{
				Timber tmp(
					settings.firstSetList.batch[i].hymidity,
					settings.firstSetList.batch[i].knotCount,
					settings.firstSetList.batch[i].diametr,
					settings.firstSetList.batch[i].length,
					settings.firstSetList.batch[i].mould,
					settings.firstSetList.batch[i].crack,
					i
					,
					generator);
				timbers.push_back(tmp);
			}		
		}
	}

}

void Simulation::setWndParams(UINT width, UINT height)
{
	wndWidth = width;
	wndHeight = height;

	timberLoader.setWndSize(width, height);
	pSBench.setWndSize(width, height);
	dryerBench.setWndSize(width, height);
	sortingBench.setWndSize(width, height);
	for (auto& millingBench : millingBenchs)
		millingBench.setWndSize(width, height);
	for (auto& assemblingBench : assemblingBenchs)
		assemblingBench.setWndSize(width, height);
	paintingBench.setWndSize(width, height);
	packingBench.setWndSize(width, height);
	fnBench.setWndSize(width, height);
	for (auto& brigade : brigades)
	{
		brigade.employee1.setWndSize(width, height);
		brigade.employee2.setWndSize(width, height);
		brigade.employee3.setWndSize(width, height);
	}


	for (auto& timber : timbers)
		timber.setWndSize(width, height);
	for (auto& timber : shownTimbers)
		timber.setWndSize(width, height);

	for (auto& board : boards)
		board.setWndSize(width, height);
	for (auto& board : shownBoards)
		board.setWndSize(width, height);

	for (auto& door : doors)
		door.setWndSize(width, height);
	for (auto& door : shownDoors)
		door.setWndSize(width, height);

	firstGradeDoorButton.setWndSize(width, height);
	secondGradeDoorButton.setWndSize(width, height);
	thirdGradeDoorButton.setWndSize(width, height);
}

std::vector<UINT> Simulation::getLastInBatch()
{
	std::vector<UINT> lastInBatch;

	for (int i = 0; i < 10; i++)
	{
		UINT last = 0;
		int first = 0;
		for (int j = 0; j < i; j++)
			first += settings.firstSetList.batch[j].count;
		for (int j = 0; j < settings.firstSetList.batch[i].count; j++)
			if (timbers[first + j].isIdle())
				last++;
		lastInBatch.push_back(last);
	}

	return lastInBatch;
}

UINT Simulation::getFirstGradeDoorsCount()
{
	UINT count = 0;
	for (auto& door : doors)
		if (door.isFirstGrade() && (door.isDone() || door.isDoneAndShow()))
			count++;

	return count;
}
UINT Simulation::getSecondGradeDoorsCount()
{
	UINT count = 0;
	for (auto& door : doors)
		if (door.isSecondGrade() && (door.isDone() || door.isDoneAndShow()))
			count++;

	return count;
}
UINT Simulation::getThirdGradeDoorsCount()
{
	UINT count = 0;
	for (auto& door : doors)
		if (door.isThirdGrade() && (door.isDone() || door.isDoneAndShow()))
			count++;

	return count;
}
vector<UINT> Simulation::getFirstGradeDoorDefectsCount()
{
	vector<UINT> count(8);
	for (auto& door : doors)
	{
		if (door.isFirstGrade() && (door.isDone() || door.isDoneAndShow()))
		{
			if (door.isHumidityDefect())
				count[0]++;
			if (door.isKnotCountDefect())
				count[1]++;
			if (door.isWidthDefect())
				count[2]++;
			if (door.isHeightDefect())
				count[3]++;
			if (door.isMouldDefect())
				count[4]++;
			if (door.isCrackDefect())
				count[5]++;
			if (door.isDeformationDefect())
				count[6]++;
			if (door.isPaintingDefect())
				count[7]++;
		}
	}

	return count;
}
vector<UINT> Simulation::getFSecondGradeDoorDefectsCount()
{
	vector<UINT> count(8);
	for (auto& door : doors)
	{
		if (door.isSecondGrade() && (door.isDone() || door.isDoneAndShow()))
		{
			if (door.isHumidityDefect())
				count[0]++;
			if (door.isKnotCountDefect())
				count[1]++;
			if (door.isWidthDefect())
				count[2]++;
			if (door.isHeightDefect())
				count[3]++;
			if (door.isMouldDefect())
				count[4]++;
			if (door.isCrackDefect())
				count[5]++;
			if (door.isDeformationDefect())
				count[6]++;
			if (door.isPaintingDefect())
				count[7]++;
		}
	}

	return count;
}
vector<UINT> Simulation::getThirdGradeDoorDefectsCount()
{
	vector<UINT> count(8);
	for (auto& door : doors)
	{
		if (door.isThirdGrade() && (door.isDone() || door.isDoneAndShow()))
		{
			if (door.isHumidityDefect())
				count[0]++;
			if (door.isKnotCountDefect())
				count[1]++;
			if (door.isWidthDefect())
				count[2]++;
			if (door.isHeightDefect())
				count[3]++;
			if (door.isMouldDefect())
				count[4]++;
			if (door.isCrackDefect())
				count[5]++;
			if (door.isDeformationDefect())
				count[6]++;
			if (door.isPaintingDefect())
				count[7]++;
		}
	}

	return count;
}

void Simulation::doAction()
{
	srand(time(0));
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
	UINT iterationToBrChange = brigadesChangeRate  * pps;
	UINT iteration = 0;
	while (!exitFlag)
	{
		std::this_thread::sleep_for(chrono::microseconds(1000000/pps));

		if (isPlayed && !settings.isVisible())
		{
				///////////////////////////////////////////////TIMBRES//////////////////////////////////////////////

				auto idleTimber = std::find_if(timbers.begin(), timbers.end(), [](Timber& timber) { return timber.isIdle(); });
				auto lastActiveTimber = std::find_if(timbers.rbegin(), timbers.rend(), [](Timber& timber) { return timber.isToPSBench(); });
				auto firstActiveTimber = std::find_if(timbers.begin(), timbers.end(), [](Timber& timber) { return timber.isToPSBench(); });

				if (idleTimber != timbers.end() && (lastActiveTimber == timbers.rend() || abs(lastActiveTimber->position.y - idleTimber->position.y) > lastActiveTimber->size.y + 10))
				{
					idleTimber->setToPSBench();
					timberMutex.lock();
					shownTimbers.push_back(*idleTimber);
					timberMutex.unlock();
				}

				if (firstActiveTimber != timbers.end() && pSBench.position.y + pSBench.size.y / 2 > firstActiveTimber->position.y + firstActiveTimber->size.y / 2)
				{
					firstActiveTimber->setDone();
					timberMutex.lock();
					shownTimbers.erase(shownTimbers.begin());
					timberMutex.unlock();
					vector<Board> tmp = pSBench.sawing(*firstActiveTimber, generator);
					for (auto& board : tmp)
						board.setWndSize(wndWidth, wndHeight);
					std::copy(tmp.begin(), tmp.end(), std::back_inserter(boards));
				}

				for (auto& timber : timbers)
				{
					if (timber.isToPSBench())
						timber.position.y -= 1;
				}

				for (auto& timber : shownTimbers)
				{
					timber.position.y -= 1;
				}

				///////////////////////////////////////////////BOARDS///////////////////////////////////////////////

				auto idleBoard = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isIdle(); });
				auto lastToDryerBenchBoard = std::find_if(boards.rbegin(), boards.rend(), [](Board& board) { return board.isToDryerBench(); });
				auto firstToDryerBenchBoard = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isToDryerBench(); });
			
				if (idleBoard != boards.end() && (lastToDryerBenchBoard == boards.rend() || abs(lastToDryerBenchBoard->position.y - idleBoard->position.y) > lastToDryerBenchBoard->size.y + 10))
				{
					idleBoard->setToDryerBench();
					boardMutex.lock();
					shownBoards.push_back(*idleBoard);
					boardMutex.unlock();
				}

				if (firstToDryerBenchBoard != boards.end() && dryerBench.position.y + dryerBench.size.y / 2 - 5> firstToDryerBenchBoard->position.y + firstToDryerBenchBoard->size.y / 2)
				{
					firstToDryerBenchBoard->setToSortingBench();
					dryerBench.drying(*firstToDryerBenchBoard, generator);
					*std::find_if(shownBoards.begin(), shownBoards.end(), [](Board& board) { return board.isToDryerBench(); }) = *firstToDryerBenchBoard;
				}

				auto firstToSortingBenchBoard = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isToSortingBench(); });

				if (firstToSortingBenchBoard != boards.end() && firstToSortingBenchBoard->position.x - 20 > sortingBench.position.x)
				{
					firstToSortingBenchBoard->setToMillingBench();
					sortingBench.sorting(*firstToSortingBenchBoard);

					if (firstToSortingBenchBoard->isCrap())
					{
						boardMutex.lock();
						shownBoards.erase(std::find_if(shownBoards.begin(), shownBoards.end(), [](Board& board) { return board.isToSortingBench(); }));
						boardMutex.unlock();
					}
					else
						*std::find_if(shownBoards.begin(), shownBoards.end(), [](Board& board) { return board.isToSortingBench(); }) = *firstToSortingBenchBoard;
				}

				auto firstToMillingBenchBoard = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isToMillingBench(); });

				if (firstToMillingBenchBoard != boards.end() && firstToMillingBenchBoard->position.y > (firstToMillingBenchBoard->isFirstGrade() ? millingBenchs[0].position.y : (firstToMillingBenchBoard->isSecondGrade() ? millingBenchs[1].position.y : millingBenchs[2].position.y)))
				{
					firstToMillingBenchBoard->setToAssemblingBench();
					firstToMillingBenchBoard->isFirstGrade() ? millingBenchs[0].milling(*firstToMillingBenchBoard, generator) : (firstToMillingBenchBoard->isSecondGrade() ? millingBenchs[1].milling(*firstToMillingBenchBoard, generator) : millingBenchs[2].milling(*firstToMillingBenchBoard, generator));
					*std::find_if(shownBoards.begin(), shownBoards.end(), [](Board& board) { return board.isToMillingBench(); }) = *firstToMillingBenchBoard;
				}

				auto firstToAssemblingBenchBoard = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isToAssemblingBench(); });

				if (firstToAssemblingBenchBoard != boards.end() && firstToAssemblingBenchBoard->position.y - 12 > (firstToAssemblingBenchBoard->isFirstGrade() ? assemblingBenchs[0].position.y : (firstToAssemblingBenchBoard->isSecondGrade() ? assemblingBenchs[1].position.y : assemblingBenchs[2].position.y)))
				{
					firstToAssemblingBenchBoard->setDone();
					boardMutex.lock();
					shownBoards.erase(shownBoards.begin());
					boardMutex.unlock();
					Door tmp = firstToAssemblingBenchBoard->isFirstGrade() ? assemblingBenchs[0].assembling(*firstToAssemblingBenchBoard, generator) : (firstToAssemblingBenchBoard->isSecondGrade() ? assemblingBenchs[1].assembling(*firstToAssemblingBenchBoard, generator) : assemblingBenchs[2].assembling(*firstToAssemblingBenchBoard, generator));
					tmp.setWndSize(wndWidth, wndHeight);
					if (tmp.isIdle())
					{
						if (tmp.isFirstGrade())
						{
							auto idleFirstGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isFirstGrade(); });
							if (idleFirstGradeDoor == doors.end())
							{
								doors.push_back(tmp);
								doorMutex.lock();
								shownDoors.push_back(tmp);
								doorMutex.unlock();
							}
						}
						else if (tmp.isSecondGrade())
						{
							auto idleSecondGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isSecondGrade(); });
							if (idleSecondGradeDoor == doors.end())
							{
								doors.push_back(tmp);
								doorMutex.lock();
								shownDoors.push_back(tmp);
								doorMutex.unlock();
							}
						}
						else
						{
							auto idleThirdGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isThirdGrade(); });
							if (idleThirdGradeDoor == doors.end())
							{
								doors.push_back(tmp);
								doorMutex.lock();
								shownDoors.push_back(tmp);
								doorMutex.unlock();
							}
						}
					}
					else if (tmp.isToPaintingBench())
					{
						if (tmp.isFirstGrade())
						{
							auto idleFirstGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isFirstGrade(); });
							auto idleFirstGradeShownDoors = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isIdle() && door.isFirstGrade(); });
							if (idleFirstGradeDoor != doors.end())
							{
								auto it = doors.erase(idleFirstGradeDoor);
								doors.insert(it, tmp);
								doorMutex.lock();
								auto it1 = shownDoors.erase(idleFirstGradeShownDoors);
								shownDoors.insert(it1, tmp);
								doorMutex.unlock();
							}
								
						}
						else if (tmp.isSecondGrade())
						{
							auto idleSecondGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isSecondGrade(); });
							auto idleSecondGradeShownDoors = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isIdle() && door.isSecondGrade(); });
							if (idleSecondGradeDoor != doors.end())
							{
								auto it = doors.erase(idleSecondGradeDoor);
								doors.insert(it, tmp);
								doorMutex.lock();
								auto it1 = shownDoors.erase(idleSecondGradeShownDoors);
								shownDoors.insert(it1, tmp);
								doorMutex.unlock();
							}
						}
						else
						{
							auto idleThirdGradeDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isIdle() && door.isThirdGrade(); });
							auto idleThirdGradeShownDoors = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isIdle() && door.isThirdGrade(); });
							if (idleThirdGradeDoor != doors.end())
							{
								auto it = doors.erase(idleThirdGradeDoor);
								doors.insert(it, tmp);
								doorMutex.lock();
								auto it1 = shownDoors.erase(idleThirdGradeShownDoors);
								shownDoors.insert(it1, tmp);
								doorMutex.unlock();
							}
						}
					}

				}

				for (auto& board : boards)
				{
					if (board.isToDryerBench())
						board.position.y -= 1;
					if (board.isToSortingBench())
						board.position.x += 1;
					if (board.isToMillingBench() || board.isToAssemblingBench())
						board.position.y += 1;
				}

				for (auto& board : shownBoards)
				{
					if (board.isToDryerBench())
						board.position.y -= 1;
					if (board.isToSortingBench())
						board.position.x += 1;
					if (board.isToMillingBench() || board.isToAssemblingBench())
						board.position.y += 1;
				}


				///////////////////////////////////////////////DOORS///////////////////////////////////////////////


				auto firstToPaintingBenchDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isToPaintingBench(); });

				if (firstToPaintingBenchDoor != doors.end() && firstToPaintingBenchDoor->position.y - 40 > paintingBench.position.y)
				{
					firstToPaintingBenchDoor->setToPackingBench();
					paintingBench.painting(*firstToPaintingBenchDoor);
					firstToPaintingBenchDoor->setWndSize(wndWidth, wndHeight);
				}

				auto firstToPaintingBenchShownDoor = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isToPaintingBench(); });

				if (firstToPaintingBenchShownDoor != shownDoors.end() && firstToPaintingBenchShownDoor->position.y - 40> paintingBench.position.y)
				{
					firstToPaintingBenchShownDoor->setToPackingBench();
					paintingBench.painting(*firstToPaintingBenchShownDoor);
					firstToPaintingBenchShownDoor->setWndSize(wndWidth, wndHeight);
				}

				auto firstToPackingBenchDoor1 = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isToPackingBench() && door.isFirstGrade(); });
				auto firstToPackingBenchDoor2 = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isToPackingBench() && door.isSecondGrade(); });
				auto firstToPackingBenchDoor3 = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isToPackingBench() && door.isThirdGrade(); });

				if (firstToPackingBenchDoor1 != doors.end() && firstToPackingBenchDoor1->position.y < packingBench.position.y + packingBench.size.y * 0.675)
				{
					auto toDoneDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isDoneAndShow() && door.isFirstGrade(); });
					if (toDoneDoor != doors.end())
						toDoneDoor->setDone();
					firstToPackingBenchDoor1->setDoneAndShow();
				}

				if (firstToPackingBenchDoor2 != doors.end() && firstToPackingBenchDoor2->position.y < packingBench.position.y + packingBench.size.y * 0.35)
				{
					auto toDoneDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isDoneAndShow() && door.isSecondGrade(); });
					if (toDoneDoor != doors.end())
						toDoneDoor->setDone();
					firstToPackingBenchDoor2->setDoneAndShow();
				}

				if (firstToPackingBenchDoor3 != doors.end() && firstToPackingBenchDoor3->position.y < packingBench.position.y + packingBench.size.y * 0.05)
				{
					auto toDoneDoor = std::find_if(doors.begin(), doors.end(), [](Door& door) { return door.isDoneAndShow() && door.isThirdGrade(); });
					if (toDoneDoor != doors.end())
						toDoneDoor->setDone();
					firstToPackingBenchDoor3->setDoneAndShow();
				}

				auto firstToPackingBenchShownDoor1 = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isToPackingBench() && door.isFirstGrade(); });

				if (firstToPackingBenchShownDoor1 != shownDoors.end() && firstToPackingBenchShownDoor1->position.y < packingBench.position.y + packingBench.size.y * 0.675)
				{
					auto toDoneDoor = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isDoneAndShow() && door.isFirstGrade(); });
					firstToPackingBenchShownDoor1->setDoneAndShow();
					if (toDoneDoor != shownDoors.end())
					{
						doorMutex.lock();
						shownDoors.erase(toDoneDoor);
						doorMutex.unlock();
					}			
				}

				auto firstToPackingBenchShownDoor2 = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isToPackingBench() && door.isSecondGrade(); });

				if (firstToPackingBenchShownDoor2 != shownDoors.end() && firstToPackingBenchShownDoor2->position.y < packingBench.position.y + packingBench.size.y * 0.35)
				{
					auto toDoneDoor = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isDoneAndShow() && door.isSecondGrade(); });
					firstToPackingBenchShownDoor2->setDoneAndShow();
					if (toDoneDoor != shownDoors.end())
					{
						doorMutex.lock();
						shownDoors.erase(toDoneDoor);
						doorMutex.unlock();
					}
					
				}

				auto firstToPackingBenchShownDoor3 = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isToPackingBench() && door.isThirdGrade(); });

				if (firstToPackingBenchShownDoor3 != shownDoors.end() && firstToPackingBenchShownDoor3->position.y < packingBench.position.y + packingBench.size.y * 0.05)
				{
					auto toDoneDoor = std::find_if(shownDoors.begin(), shownDoors.end(), [](Door& door) { return door.isDoneAndShow() && door.isThirdGrade(); });
					firstToPackingBenchShownDoor3->setDoneAndShow();
					if (toDoneDoor != shownDoors.end())
					{
						doorMutex.lock();
						shownDoors.erase(toDoneDoor);
						doorMutex.unlock();
					}
					
				}

				for (auto& door : doors)
				{
					if (door.isToPaintingBench())
						door.position.y += 1;
					if (door.isToPackingBench())
						door.position.y -= 1;
				}


				for (auto& door : shownDoors)
				{
					if (door.isToPaintingBench())
						door.position.y += 1;
					if (door.isToPackingBench())
						door.position.y -= 1;
				}

				///////////////////////////////////////////////Brigades///////////////////////////////////////////////
				
				if (iteration == iterationToBrChange)
				{
					for (int i = 0; i < brigades.size(); i++)
					{
						if (brigades[i].isActive)
						{
							brigades[i].isActive = false;
							i = i == brigades.size() - 1 ? 0 : i + 1;
							brigades[i].isActive = true;

							pSBench.setBrigade(brigades[i]);
							dryerBench.setBrigade(brigades[i]);
							sortingBench.setBrigade(brigades[i]);
							paintingBench.setBrigade(brigades[i]);
							for (auto& millingBench : millingBenchs)
								millingBench.setBrigade(brigades[i]);
							for (auto& assemblingBench : assemblingBenchs)
								assemblingBench.setBrigade(brigades[i]);
							break;
						}
					}

					iteration = 0;
				}
				iteration++;

		}

	}
}

Simulation::~Simulation()
{
	isPlayed = false;
	exitFlag = true;
	if (mainCycle.joinable())
		mainCycle.join();
}