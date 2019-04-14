#include "DryerBench.h"
#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

DryerBench::DryerBench(const Settings& settings)
{
	this->settings = &settings;

	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { -20, -20 };
	sizeOnTex = { 370, 266 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/dryingBench.tga";

}

void DryerBench::drying(Board& board, std::default_random_engine& generator)
{
	double effectiveCoef = 1;
	if (brigade)
		effectiveCoef = brigade->effectiveCoef;

	std::normal_distribution<double> humidityDistr;

	humidityDistr = !isBrokenHumidity ? std::normal_distribution<double>(m_humidity, sg_humidity * effectiveCoef) : std::normal_distribution<double>(4 * m_humidity, 10 * sg_humidity * effectiveCoef);

	board.humidity = abs(humidityDistr(generator));
	board.humidity = board.humidity < 5 ? 5 : (board.humidity > 100 ? 100 : board.humidity);

	if (!isBrokenCrack)
		board.isCrack = board.isCrack ? true : (RANDNUM / effectiveCoef < 0.02 ? true : false);
	else
		board.isCrack = board.isCrack ? true : (RANDNUM / effectiveCoef < 0.06 ? true : false);

	if (!isBrokenDeformation)
		board.isDeformation = board.isDeformation ? true : (RANDNUM / effectiveCoef < 0.05 ? true : false);
	else
		board.isDeformation = board.isDeformation ? true : (RANDNUM / effectiveCoef < 0.15 ? true : false);

	numOfDryedBoards++;
	if (numOfDryedBoards == settings->secondSetList.bench[1].toFirstBreakdown)
	{
		isBrokenHumidity = isBrokenHumidity ? isBrokenHumidity : settings->fourthSetList.breakdown[0].humidity;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->fourthSetList.breakdown[0].crack;
		isBrokenDeformation = isBrokenDeformation ? isBrokenDeformation : settings->fourthSetList.breakdown[0].deformation;
	}
	else if (numOfDryedBoards == settings->secondSetList.bench[1].toSecondBreakdown)
	{
		isBrokenHumidity = isBrokenHumidity ? isBrokenHumidity : settings->fourthSetList.breakdown[1].humidity;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->fourthSetList.breakdown[1].crack;
		isBrokenDeformation = isBrokenDeformation ? isBrokenDeformation : settings->fourthSetList.breakdown[1].deformation;
	}
	else if (numOfDryedBoards == settings->secondSetList.bench[1].toThirdBreakdown)
	{
		isBrokenHumidity = isBrokenHumidity ? isBrokenHumidity : settings->fourthSetList.breakdown[2].humidity;
		isBrokenCrack = isBrokenCrack ? isBrokenCrack : settings->fourthSetList.breakdown[2].crack;
		isBrokenDeformation = isBrokenDeformation ? isBrokenDeformation : settings->fourthSetList.breakdown[2].deformation;
	}

}