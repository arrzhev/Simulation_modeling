#include "PaintingBench.h"
#include "Settings.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

PaintingBench::PaintingBench(const Settings& settings)
{
	this->settings = &settings;

	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 350, 800 };
	sizeOnTex = { 1150, 370 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/paintingBench.tga";
}

void PaintingBench::painting(Door& door)
{
	door.setToPackingBench();
	door.posOnTex.x = 1600;
	door.posOnTex.y = 880;

	if (door.isFirstGrade())
	{
		door.texPath = "images/products/door1.tga";
		door.isPainitingDefect = !isBrokenPainting1 ? RANDNUM < 0.03 : RANDNUM < 0.1;
	}
	else if (door.isSecondGrade())
	{
		door.texPath = "images/products/door2.tga";
		door.isPainitingDefect = !isBrokenPainting2 ? RANDNUM < 0.03 : RANDNUM < 0.1;
	}
	else
	{
		door.texPath = "images/products/door3.tga";
		door.isPainitingDefect = !isBrokenPainting3 ? RANDNUM < 0.03 : RANDNUM < 0.1;
	}


	numOfPaintedDoors++;
	if (numOfPaintedDoors == settings->secondSetList.bench[9].toFirstBreakdown)
	{
		isBrokenPainting1 = isBrokenPainting1 ? isBrokenPainting1 : settings->eighthSetList.grade[0].breakdown[0].paintingDefect;
		isBrokenPainting2 = isBrokenPainting2 ? isBrokenPainting2 : settings->eighthSetList.grade[1].breakdown[0].paintingDefect;
		isBrokenPainting3 = isBrokenPainting3 ? isBrokenPainting3 : settings->eighthSetList.grade[2].breakdown[0].paintingDefect;

	}
	else if (numOfPaintedDoors == settings->secondSetList.bench[9].toSecondBreakdown)
	{
		isBrokenPainting1 = isBrokenPainting1 ? isBrokenPainting1 : settings->eighthSetList.grade[0].breakdown[1].paintingDefect;
		isBrokenPainting2 = isBrokenPainting2 ? isBrokenPainting2 : settings->eighthSetList.grade[1].breakdown[1].paintingDefect;
		isBrokenPainting3 = isBrokenPainting3 ? isBrokenPainting3 : settings->eighthSetList.grade[2].breakdown[1].paintingDefect;
	}
	else if (numOfPaintedDoors == settings->secondSetList.bench[9].toThirdBreakdown)
	{
		isBrokenPainting1 = isBrokenPainting1 ? isBrokenPainting1 : settings->eighthSetList.grade[0].breakdown[2].paintingDefect;
		isBrokenPainting2 = isBrokenPainting2 ? isBrokenPainting2 : settings->eighthSetList.grade[1].breakdown[2].paintingDefect;
		isBrokenPainting3 = isBrokenPainting3 ? isBrokenPainting3 : settings->eighthSetList.grade[2].breakdown[2].paintingDefect;
	}

}