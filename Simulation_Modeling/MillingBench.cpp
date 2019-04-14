#include "MillingBench.h"
#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

MillingBench::MillingBench(const Settings& settings)
{
	this->settings = &settings;

	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 390, 280 };
	sizeOnTex = { 400, 280 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/millingBench1.tga";
}

void MillingBench::milling(Board& board, std::default_random_engine& generator)
{
	double effectiveCoef = 1;
	if (brigade)
		effectiveCoef = brigade->effectiveCoef;

	std::normal_distribution<double> lengthDistr;
	std::normal_distribution<double> widthDistr;

	lengthDistr = !isBrokenLength ? std::normal_distribution<double>(board.length * 0.98, board.length * 0.01 * effectiveCoef) : std::normal_distribution<double>(board.length * 0.98, board.length * 0.05 * effectiveCoef);
	widthDistr = !isBrokenWidth ? std::normal_distribution<double>(board.width * 0.98, board.width * 0.01 * effectiveCoef) : std::normal_distribution<double>(board.width * 0.98, board.width * 0.05 * effectiveCoef);

	auto tmp = abs(lengthDistr(generator));
	board.length = tmp > board.length ? board.length : tmp;

	tmp = abs(widthDistr(generator));
	board.width = tmp > board.width ? board.width : tmp;

	board.isCrack = !board.isCrack ? (!isBrokenCrack ? RANDNUM / effectiveCoef < 0.01 : RANDNUM / effectiveCoef < 0.1) : board.isCrack;

	board.isCrack = !board.isCrack ? (board.humidity < 0.2 ? RANDNUM < 0.01 : RANDNUM < 0.1) : board.isCrack;

	numOfMilledBoards++;
	if (board.isFirstGrade())
	{
		if (numOfMilledBoards == settings->secondSetList.bench[3].toFirstBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[0].breakdown[0].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[0].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[0].breakdown[0].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[3].toSecondBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[0].breakdown[1].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[0].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[0].breakdown[1].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[3].toThirdBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[0].breakdown[2].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[0].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[0].breakdown[2].crack;
		}
	}
	else if (board.isSecondGrade())
	{
		if (numOfMilledBoards == settings->secondSetList.bench[4].toFirstBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[1].breakdown[0].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[1].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[1].breakdown[0].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[4].toSecondBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[1].breakdown[1].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[1].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[1].breakdown[1].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[4].toThirdBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[1].breakdown[2].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[1].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[1].breakdown[2].crack;
		}
	}
	else
	{
		if (numOfMilledBoards == settings->secondSetList.bench[5].toFirstBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[2].breakdown[0].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[2].breakdown[0].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[2].breakdown[0].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[5].toSecondBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[2].breakdown[1].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[2].breakdown[1].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[2].breakdown[1].crack;
		}
		else if (numOfMilledBoards == settings->secondSetList.bench[5].toThirdBreakdown)
		{
			isBrokenLength = isBrokenLength ? isBrokenLength : settings->sixthSetList.grade[2].breakdown[2].length;
			isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->sixthSetList.grade[2].breakdown[2].width;
			isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->sixthSetList.grade[2].breakdown[2].crack;
		}
	}

}