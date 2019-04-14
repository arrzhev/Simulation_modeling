#include "SortingBench.h"

#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

SortingBench::SortingBench(const Settings& settings)
{
	this->settings = &settings;

	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 434, -40 };
	sizeOnTex = { 1030, 310 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/sortingBench.tga";
}

void SortingBench::sorting(Board& board)
{
	double effectiveCoef = 1;
	if (brigade)
		effectiveCoef = brigade->effectiveCoef;

	if ((board.humidity < 11 ? (!isBrokenHumidity1 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenHumidity1 ? RANDNUM / effectiveCoef < 0.03 : RANDNUM / effectiveCoef < 0.1))
		&& (board.knotCount < 2 ? (!isBrokenKnotCount1 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenKnotCount1 ? RANDNUM / effectiveCoef < 0.03 : RANDNUM / effectiveCoef < 0.1))
		&& (!board.isMould ? (!isBrokenMould1 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenMould1 ? RANDNUM / effectiveCoef < 0.03 : RANDNUM / effectiveCoef < 0.1))
		&& (!board.isCrack ? (!isBrokenCrack1 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenCrack1 ? RANDNUM / effectiveCoef < 0.03 : RANDNUM / effectiveCoef < 0.1))
		&& (!board.isDeformation ? (!isBrokenDeformation1 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenDeformation1 ? RANDNUM / effectiveCoef < 0.03 : RANDNUM / effectiveCoef < 0.1)))
	{
		board.setFirstGrade();
		board.position.x += (550 - this->posOnTex.x) / this->sizeOnTex.x * this->size.x;
		board.texPath = "images/products/board1.tga";
	}
	else if ((board.humidity < 15 ? (!isBrokenHumidity2 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenHumidity2 ? RANDNUM / effectiveCoef < 0.08 : RANDNUM / effectiveCoef < 0.15))
			&& (board.knotCount < 4 ? (!isBrokenKnotCount2 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenKnotCount2 ? RANDNUM / effectiveCoef < 0.08 : RANDNUM / effectiveCoef < 0.15))
			&& (!board.isMould ? (!isBrokenMould2 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenMould2 ? RANDNUM / effectiveCoef < 0.08 : RANDNUM / effectiveCoef < 0.15))
			&& (!board.isCrack ? (!isBrokenCrack2 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenCrack2 ? RANDNUM / effectiveCoef < 0.08 : RANDNUM / effectiveCoef < 0.15))
			&& (!board.isDeformation ? (!isBrokenDeformation2 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenDeformation2 ? RANDNUM / effectiveCoef < 0.08 : RANDNUM / effectiveCoef < 0.15)))
	{
		board.setSecondGrade();
		board.position.x += (880 - this->posOnTex.x) / this->sizeOnTex.x * this->size.x;
		board.texPath = "images/products/board2.tga";
	}
	else if ((board.humidity < 50 ? (!isBrokenHumidity3 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenHumidity3 ? RANDNUM / effectiveCoef < 0.1 : RANDNUM / effectiveCoef < 0.2))
			&& (board.knotCount < 6 ? (!isBrokenKnotCount3 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenKnotCount3 ? RANDNUM / effectiveCoef < 0.1 : RANDNUM / effectiveCoef < 0.2))
			&& (!board.isMould ? (!isBrokenMould3 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenMould3 ? RANDNUM / effectiveCoef < 0.75 : RANDNUM / effectiveCoef < 0.9))
			&& (!board.isCrack ? (!isBrokenCrack3 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenCrack3 ? RANDNUM / effectiveCoef < 0.1 : RANDNUM / effectiveCoef < 0.2))
			&& (!board.isDeformation ? (!isBrokenDeformation3 ? RANDNUM * effectiveCoef < 0.97 : RANDNUM * effectiveCoef < 0.75) : (!isBrokenDeformation3 ? RANDNUM / effectiveCoef < 0.75 : RANDNUM / effectiveCoef < 0.9)))
	{
		board.setThirdGrade();
		board.position.x += (1190 - this->posOnTex.x) / this->sizeOnTex.x * this->size.x;
		board.texPath = "images/products/board3.tga";
	}
	else
	{
		board.setCrap();
		board.setDone();
	}

	board.isCrack = !board.isCrack ? (board.humidity < 0.2 ? RANDNUM < 0.01 : RANDNUM < 0.05) : board.isCrack;

	numOfSortedBoards++;
	if (numOfSortedBoards == settings->secondSetList.bench[2].toFirstBreakdown)
	{
		isBrokenHumidity1 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[0].breakdown[0].humidity;
		isBrokenKnotCount1 = isBrokenKnotCount1 ? isBrokenKnotCount1 : settings->fifthSetList.grade[0].breakdown[0].knotCount;
		isBrokenMould1 = isBrokenMould1 ? isBrokenMould1 : settings->fifthSetList.grade[0].breakdown[0].mould;
		isBrokenCrack1 = isBrokenCrack1 ? isBrokenCrack1 : settings->fifthSetList.grade[0].breakdown[0].crack;
		isBrokenDeformation1 = isBrokenDeformation1 ? isBrokenDeformation1 : settings->fifthSetList.grade[0].breakdown[0].deformation;

		isBrokenHumidity2 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[1].breakdown[0].humidity;
		isBrokenKnotCount2 = isBrokenKnotCount2 ? isBrokenKnotCount2 : settings->fifthSetList.grade[1].breakdown[0].knotCount;
		isBrokenMould2 = isBrokenMould2 ? isBrokenMould2 : settings->fifthSetList.grade[1].breakdown[0].mould;
		isBrokenCrack2 = isBrokenCrack2 ? isBrokenCrack2 : settings->fifthSetList.grade[1].breakdown[0].crack;
		isBrokenDeformation2 = isBrokenDeformation2 ? isBrokenDeformation2 : settings->fifthSetList.grade[1].breakdown[0].deformation;

		isBrokenHumidity3 = isBrokenHumidity3 ? isBrokenHumidity3 : settings->fifthSetList.grade[2].breakdown[0].humidity;
		isBrokenKnotCount3 = isBrokenKnotCount3 ? isBrokenKnotCount3 : settings->fifthSetList.grade[2].breakdown[0].knotCount;
		isBrokenMould3 = isBrokenMould3 ? isBrokenMould3 : settings->fifthSetList.grade[2].breakdown[0].mould;
		isBrokenCrack3 = isBrokenCrack3 ? isBrokenCrack3 : settings->fifthSetList.grade[2].breakdown[0].crack;
		isBrokenDeformation3 = isBrokenDeformation3 ? isBrokenDeformation3 : settings->fifthSetList.grade[2].breakdown[0].deformation;
	}
	else if (numOfSortedBoards == settings->secondSetList.bench[2].toSecondBreakdown)
	{
		isBrokenHumidity1 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[0].breakdown[1].humidity;
		isBrokenKnotCount1 = isBrokenKnotCount1 ? isBrokenKnotCount1 : settings->fifthSetList.grade[0].breakdown[1].knotCount;
		isBrokenMould1 = isBrokenMould1 ? isBrokenMould1 : settings->fifthSetList.grade[0].breakdown[1].mould;
		isBrokenCrack1 = isBrokenCrack1 ? isBrokenCrack1 : settings->fifthSetList.grade[0].breakdown[1].crack;
		isBrokenDeformation1 = isBrokenDeformation1 ? isBrokenDeformation1 : settings->fifthSetList.grade[0].breakdown[1].deformation;

		isBrokenHumidity2 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[1].breakdown[1].humidity;
		isBrokenKnotCount2 = isBrokenKnotCount2 ? isBrokenKnotCount2 : settings->fifthSetList.grade[1].breakdown[1].knotCount;
		isBrokenMould2 = isBrokenMould2 ? isBrokenMould2 : settings->fifthSetList.grade[1].breakdown[1].mould;
		isBrokenCrack2 = isBrokenCrack2 ? isBrokenCrack2 : settings->fifthSetList.grade[1].breakdown[1].crack;
		isBrokenDeformation2 = isBrokenDeformation2 ? isBrokenDeformation2 : settings->fifthSetList.grade[1].breakdown[1].deformation;

		isBrokenHumidity3 = isBrokenHumidity3 ? isBrokenHumidity3 : settings->fifthSetList.grade[2].breakdown[1].humidity;
		isBrokenKnotCount3 = isBrokenKnotCount3 ? isBrokenKnotCount3 : settings->fifthSetList.grade[2].breakdown[1].knotCount;
		isBrokenMould3 = isBrokenMould3 ? isBrokenMould3 : settings->fifthSetList.grade[2].breakdown[1].mould;
		isBrokenCrack3 = isBrokenCrack3 ? isBrokenCrack3 : settings->fifthSetList.grade[2].breakdown[1].crack;
		isBrokenDeformation3 = isBrokenDeformation3 ? isBrokenDeformation3 : settings->fifthSetList.grade[2].breakdown[1].deformation;
	}
	else if (numOfSortedBoards == settings->secondSetList.bench[2].toThirdBreakdown)
	{
		isBrokenHumidity1 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[0].breakdown[2].humidity;
		isBrokenKnotCount1 = isBrokenKnotCount1 ? isBrokenKnotCount1 : settings->fifthSetList.grade[0].breakdown[2].knotCount;
		isBrokenMould1 = isBrokenMould1 ? isBrokenMould1 : settings->fifthSetList.grade[0].breakdown[2].mould;
		isBrokenCrack1 = isBrokenCrack1 ? isBrokenCrack1 : settings->fifthSetList.grade[0].breakdown[2].crack;
		isBrokenDeformation1 = isBrokenDeformation1 ? isBrokenDeformation1 : settings->fifthSetList.grade[0].breakdown[2].deformation;

		isBrokenHumidity2 = isBrokenHumidity1 ? isBrokenHumidity1 : settings->fifthSetList.grade[1].breakdown[2].humidity;
		isBrokenKnotCount2 = isBrokenKnotCount2 ? isBrokenKnotCount2 : settings->fifthSetList.grade[1].breakdown[2].knotCount;
		isBrokenMould2 = isBrokenMould2 ? isBrokenMould2 : settings->fifthSetList.grade[1].breakdown[2].mould;
		isBrokenCrack2 = isBrokenCrack2 ? isBrokenCrack2 : settings->fifthSetList.grade[1].breakdown[2].crack;
		isBrokenDeformation2 = isBrokenDeformation2 ? isBrokenDeformation2 : settings->fifthSetList.grade[1].breakdown[2].deformation;

		isBrokenHumidity3 = isBrokenHumidity3 ? isBrokenHumidity3 : settings->fifthSetList.grade[2].breakdown[2].humidity;
		isBrokenKnotCount3 = isBrokenKnotCount3 ? isBrokenKnotCount3 : settings->fifthSetList.grade[2].breakdown[2].knotCount;
		isBrokenMould3 = isBrokenMould3 ? isBrokenMould3 : settings->fifthSetList.grade[2].breakdown[2].mould;
		isBrokenCrack3 = isBrokenCrack3 ? isBrokenCrack3 : settings->fifthSetList.grade[2].breakdown[2].crack;
		isBrokenDeformation3 = isBrokenDeformation3 ? isBrokenDeformation3 : settings->fifthSetList.grade[2].breakdown[2].deformation;
	}

}