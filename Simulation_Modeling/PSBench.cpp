#include "PSBench.h"
#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

PSBench::PSBench(const Settings& settings)
{
	this->settings = &settings;
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 8, 390 };
	sizeOnTex = { 382, 244 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/PSBench.tga";

}

vector<Board> PSBench::sawing(const Timber& timber, std::default_random_engine& generator)
{
	double effectiveCoef = 1;
	if (brigade)
		effectiveCoef = brigade->effectiveCoef;

	vector <Board> boards;
	UINT boardFromTimberCount = floor(0.75 * M_PI * timber.diametr * timber.diametr * timber.length / (4 * timber.diametr * 0.75 * timber.length * 0.9 * 0.08));
	std::normal_distribution<double> lengthDistr;
	std::normal_distribution<double> widthDistr;

	lengthDistr = !isBrokenLength ? std::normal_distribution<double>(timber.length * 0.9, 0.01 * timber.length * effectiveCoef) : std::normal_distribution<double>(timber.length * 0.8, 0.03 * timber.length * effectiveCoef);
	widthDistr = !isBrokenWidth ? std::normal_distribution<double>(timber.diametr * 0.75, timber.diametr * 0.25 * effectiveCoef) : std::normal_distribution<double>(timber.diametr * 0.75, timber.diametr * 0.25 * effectiveCoef);


	for (int i = 0; i < boardFromTimberCount; i++)
	{
		Board board;

		board.timber = timber;
		board.position.x = timber.position.x - 10;
		board.position.y = timber.position.y;
		board.humidity = timber.humidity;
		board.knotCount = ceil( (double)timber.knotCount / (double)boardFromTimberCount);
		board.isMould = timber.isMould;
		board.isDeformation = false;

		board.length = abs(lengthDistr(generator));
		board.length = board.length > timber.length ? timber.length : (board.length < 1.0 ? 1.0 : board.length);

		board.width = abs(widthDistr(generator));
		board.width = board.width > timber.diametr ? timber.diametr : (board.width < 0.2 ? 0.2 : board.width);

		if (!isBrokenCrack)
			board.isCrack = timber.isCrack ? (RANDNUM / effectiveCoef < 0.2 ? true : false) : (RANDNUM / effectiveCoef < 0.03 ? true : false);
		else
			board.isCrack = timber.isCrack ? (RANDNUM / effectiveCoef < 0.4 ? true : false) : (RANDNUM / effectiveCoef < 0.06 ? true : false);

		boards.push_back(board);
	}

	numOfSawnTimbers++;
	if (numOfSawnTimbers == settings->secondSetList.bench[0].toFirstBreakdown)
	{
		isBrokenLength = isBrokenLength ? isBrokenLength : settings->thirdSetList.breakdown[0].length;
		isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->thirdSetList.breakdown[0].width;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->thirdSetList.breakdown[0].crack;
	}
	else if (numOfSawnTimbers == settings->secondSetList.bench[0].toSecondBreakdown)
	{
		isBrokenLength = isBrokenLength ? isBrokenLength : settings->thirdSetList.breakdown[1].length;
		isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->thirdSetList.breakdown[1].width;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->thirdSetList.breakdown[1].crack;
	}
	else if (numOfSawnTimbers == settings->secondSetList.bench[0].toThirdBreakdown)
	{
		isBrokenLength = isBrokenLength ? isBrokenLength : settings->thirdSetList.breakdown[2].length;
		isBrokenWidth = isBrokenWidth ? isBrokenWidth : settings->thirdSetList.breakdown[2].width;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->thirdSetList.breakdown[2].crack;
	}

	return boards;
}
