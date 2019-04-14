#pragma once

#ifndef _BOARD_H_
#define _BOARD_H_

#include "Object.h"
#include "Timber.h"

class Board : public Object
{
private:
	enum { Idle, ToDryerBench, ToSortingBench, ToMillingBench, ToAssemblingBench, Done } State = Idle; // State of the board, related to movement along a conveyor belt
	enum { NoGrade, FirstGrade, SecondGrade, ThirdGrade, Crap } grade = NoGrade; // Board grade

public:
	inline Board();

	/// <summary>Overload of the window sizing function to display the board (does not set the position on the screen)</summary>
	inline void setWndSize(UINT width, UINT height);

	inline bool isIdle();
	inline bool isToDryerBench();
	inline bool isToSortingBench();
	inline bool isToMillingBench();
	inline bool isToAssemblingBench();
	inline bool isDone();
	inline void setIdle();
	inline void setToDryerBench();
	inline void setToSortingBench();
	inline void setToMillingBench();
	inline void setToAssemblingBench();
	inline void setDone();

	inline bool isFirstGrade();
	inline bool isSecondGrade();
	inline bool isThirdGrade();
	inline bool isCrap();
	inline void setFirstGrade();
	inline void setSecondGrade();
	inline void setThirdGrade();
	inline void setCrap();

	inline virtual ~Board(){};


	double humidity;
	unsigned int knotCount;
	double width;
	double length;
	bool isMould;
	bool isCrack;
	bool isDeformation;

	Timber timber; // Timber of which the board is made
	
};

Board::Board()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 0, 0 };
	sizeOnTex = { 70, 140 };
	texSize = { 1918, 1091 };
	texPath = "images/products/board.tga";
}


bool Board::isIdle()
{ return State == Idle; }

bool Board::isToDryerBench()
{ return State == ToDryerBench; }

bool Board::isToSortingBench()
{ return State == ToSortingBench; }

bool Board::isToMillingBench()
{ return State == ToMillingBench; }

bool Board::isToAssemblingBench()
{ return State == ToAssemblingBench; }

bool Board::isDone()
{ return State == Done; }

void Board::setIdle()
{
	State = Idle;
}

void Board::setToDryerBench()
{
	State = ToDryerBench;
}

void Board::setToSortingBench()
{
	State = ToSortingBench;
}

void Board::setToMillingBench()
{
	State = ToMillingBench;
}

void Board::setToAssemblingBench()
{
	State = ToAssemblingBench;
}

void Board::setDone()
{
	State = Done;
}

bool Board::isFirstGrade()
{ return grade == FirstGrade; }

bool Board::isSecondGrade()
{ return grade == SecondGrade; }

bool Board::isThirdGrade()
{ return grade == ThirdGrade; }

bool Board::isCrap()
{ return grade == Crap; }

void Board::setFirstGrade()
{
	grade = FirstGrade;
}

void Board::setSecondGrade()
{
	grade = SecondGrade;
}

void Board::setThirdGrade()
{
	grade = ThirdGrade;
}

void Board::setCrap()
{
	grade = Crap;
}

void Board::setWndSize(UINT width, UINT height)
{
	size.x = width / (texSize.x / sizeOnTex.x);
	size.y = height / (texSize.y / sizeOnTex.y);
}

#endif // _BOARD_H_