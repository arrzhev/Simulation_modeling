#include "AssemblingBench.h"
#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

AssemblingBench::AssemblingBench(const Settings& settings)
{
	this->settings = &settings;

	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 494, 556 };
	sizeOnTex = { 248, 284 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/assemblingBench1.tga";
}

Door AssemblingBench::assembling(Board board, std::default_random_engine& generator)
{
	double effectiveCoef = 1;
	if (brigade)
		effectiveCoef = brigade->effectiveCoef;

	boards.push_back(board);
	double boardsHeight = 0;
	double boardsWidth = 0;
	for (auto& board : boards)
	{
		boardsHeight += board.length;
		boardsWidth += board.width;
	}

	double toDoorCoef = m_width * m_height * upperCoef / (boardsHeight * boardsWidth);

	Door door;
	board.isFirstGrade() ? door.setFirstGrade() : (board.isSecondGrade() ? door.setSecondGrade() : door.setThirdGrade());

	if (toDoorCoef <= 1)
	{
		door.setToPaintingBench();
		door.boards = boards;
		std::normal_distribution<double> widthDistr;
		std::normal_distribution<double> heightDistr;

		widthDistr = !isBrokenWidth ? std::normal_distribution<double>(m_width, sg_width * effectiveCoef) : std::normal_distribution<double>(m_width, sg_width * 3 * effectiveCoef);
		heightDistr = !isBrokenHeight ? std::normal_distribution<double>(m_height, sg_height * effectiveCoef) : std::normal_distribution<double>(m_height, sg_height * 3 * effectiveCoef);

		auto tmp = abs(widthDistr(generator));
		door.width = tmp > m_width * 1.25 ? (m_width * 1.25) : (tmp < m_width * 0.75 ? m_width * 0.75 : tmp);

		tmp = abs(heightDistr(generator));
		door.height = tmp > m_height * 1.25 ? (m_height * 1.25) : (tmp < m_height * 0.75 ? m_height * 0.75 : tmp);
		
		double avgHum = 0;

		for (auto& board : boards)
		{
			door.knotCount += board.knotCount;
			avgHum += board.humidity;
		}

		avgHum /= boards.size();

		door.isMould = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isMould; }) != boards.end() ? true : false;
		door.isCrack = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isCrack; }) != boards.end() ? true : false;
		door.isDeformation = std::find_if(boards.begin(), boards.end(), [](Board& board) { return board.isDeformation; }) != boards.end() ? true : false;

		door.isCrack = !door.isCrack ? (!isBrokenCrack ? RANDNUM / effectiveCoef < 0.01 : RANDNUM / effectiveCoef < 0.1) : door.isCrack;

		door.isDeformation = !door.isDeformation ? (avgHum < 20 ? RANDNUM < 0.03 : RANDNUM < 0.15) : door.isDeformation;

		if (door.isFirstGrade())
		{
			door.posOnTex = { 568, 616 };
			door.sizeOnTex = { 110, 200 };
			door.texPath = "images/products/notPaintedDoor1.tga";
			
		}
		else if (door.isSecondGrade())
		{
			door.posOnTex = { 884, 616 };
			door.sizeOnTex = { 110, 200 };
			door.texPath = "images/products/notPaintedDoor2.tga";
		}
		else
		{
			door.posOnTex = { 1210, 616 };
			door.sizeOnTex = { 110, 200 };
			door.texPath = "images/products/notPaintedDoor3.tga";
		}
		
		boards.clear();
	}
	else
	{
		if (door.isFirstGrade())
		{
			door.posOnTex = { 552, 656 };
			door.sizeOnTex = { 120, 120 };
			door.texPath = "images/products/bunchOfBoards1.tga";
		}
		else if (board.isSecondGrade())
		{
			door.posOnTex = { 882, 656 };
			door.sizeOnTex = { 120, 120 };
			door.texPath = "images/products/bunchOfBoards2.tga";
		}
		else
		{
			door.posOnTex = { 1204, 671 };
			door.sizeOnTex = { 120, 86 };
			door.texPath = "images/products/bunchOfBoards3.tga";
		}
	}

	numOfAssembledDoors++;
	if (door.isFirstGrade())
	{
		if (numOfAssembledDoors == settings->secondSetList.bench[6].toFirstBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[0].breakdown[0].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[0].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[0].breakdown[0].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[6].toSecondBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[0].breakdown[1].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[0].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[0].breakdown[1].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[6].toThirdBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[0].breakdown[2].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[0].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[0].breakdown[2].crack;
		}
	}
	else if (door.isSecondGrade())
	{
		if (numOfAssembledDoors == settings->secondSetList.bench[7].toFirstBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[1].breakdown[0].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[1].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[1].breakdown[0].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[7].toSecondBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[1].breakdown[1].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[1].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[1].breakdown[1].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[7].toThirdBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[1].breakdown[2].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[1].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[1].breakdown[2].crack;
		}
	}
	else
	{
		if (numOfAssembledDoors == settings->secondSetList.bench[8].toFirstBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[2].breakdown[0].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[2].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[2].breakdown[0].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[8].toSecondBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[2].breakdown[1].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[2].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[2].breakdown[1].crack;
		}
		else if (numOfAssembledDoors == settings->secondSetList.bench[8].toThirdBreakdown)
		{
			isBrokenHeight = isBrokenHeight ? isBrokenHeight : settings->seventhSetList.grade[2].breakdown[2].height;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->seventhSetList.grade[2].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->seventhSetList.grade[2].breakdown[2].crack;
		}
	}

	return door;
}