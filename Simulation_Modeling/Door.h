#pragma once

#ifndef _DOOR_H_
#define _DOOR_H_

#include "Object.h"
#include "Board.h"


class Door : public Object
{
private:
	enum { Idle, ToPaintingBench, ToPackingBench, DoneAndShow, Done } State = Idle; // State of the door, related to movement along a conveyor belt
	enum { NoGrade, FirstGrade, SecondGrade, ThirdGrade } grade = NoGrade;  // Door grade

public:
	inline Door();

	inline bool isIdle();
	inline bool isToPaintingBench();
	inline bool isToPackingBench();
	inline bool isDoneAndShow();
	inline bool isDone();
	inline void setIdle();
	inline void setToPaintingBench();
	inline void setToPackingBench();
	inline void setDoneAndShow();
	inline void setDone();

	inline bool isFirstGrade();
	inline bool isSecondGrade();
	inline bool isThirdGrade();
	inline void setFirstGrade();
	inline void setSecondGrade();
	inline void setThirdGrade();
	
	inline bool isHumidityDefect();
	inline bool isKnotCountDefect();
	inline bool isWidthDefect();
	inline bool isHeightDefect();
	inline bool isMouldDefect();
	inline bool isCrackDefect();
	inline bool isDeformationDefect();
	inline bool isPaintingDefect();

	inline virtual ~Door(){};

	double humidity = 0;
	unsigned int knotCount = 0;
	double width = 0;
	double height = 0;
	bool isMould = false;
	bool isCrack = false;
	bool isDeformation = false;
	bool isPainitingDefect = false;

	vector<Board> boards; // Boards of which the door is assembled
};

Door::Door()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 552, 656 };
	sizeOnTex = { 120, 120 };
	texSize = { 1918, 1091 };
	texPath = "images/products/door1.tga";
}


bool Door::isIdle()
{ return State == Idle; }

bool Door::isToPaintingBench()
{ return State == ToPaintingBench; }

bool Door::isToPackingBench()
{ return State == ToPackingBench; }

bool Door::isDoneAndShow()
{ return State == DoneAndShow; }

bool Door::isDone()
{ return State == Done; }

void Door::setIdle()
{
	State = Idle;
}

void Door::setToPaintingBench()
{
	State = ToPaintingBench;
}

void Door::setToPackingBench()
{
	State = ToPackingBench;
}

void Door::setDoneAndShow()
{
	State = DoneAndShow;

	//if (width < 0.85 && width > 0.75 && height < 2.1 && height > 1.9 && (isThirdGrade() ? true : !isMould) && !isCrack && (isThirdGrade() ? true : !isDeformation) && !isPainitingDefect)
	//	deffective = false;
	//else
	//	deffective = true;
}

void Door::setDone()
{
	State = Done;

	//if (width < 0.85 && width > 0.75 && height < 2.1 && height > 1.9 && (isThirdGrade() ? true : !isMould) && !isCrack && (isThirdGrade() ? true : !isDeformation) && !isPainitingDefect)
	//	deffective = false;
	//else
	//	deffective = true;
}

bool Door::isFirstGrade()
{ return grade == FirstGrade; }

bool Door::isSecondGrade()
{ return grade == SecondGrade; }

bool Door::isThirdGrade()
{ return grade == ThirdGrade; }

void Door::setFirstGrade()
{
	grade = FirstGrade;
}

void Door::setSecondGrade()
{
	grade = SecondGrade;
}

void Door::setThirdGrade()
{
	grade = ThirdGrade;
}


inline bool Door::isHumidityDefect()
{
	return humidity > 20;
}

inline bool Door::isKnotCountDefect()
{
	return isFirstGrade() ? knotCount > 4 : isSecondGrade() ? knotCount > 10 : knotCount > 14;
}

inline bool Door::isWidthDefect()
{
	return width > 0.85 || width < 0.75;
}
inline bool Door::isHeightDefect()
{
	return height > 2.1 || height < 1.9;
}
inline bool Door::isMouldDefect()
{
	return isFirstGrade() ? isMould : isSecondGrade() ? isMould : false;
}
inline bool Door::isCrackDefect()
{
	return isFirstGrade() ? isCrack : isSecondGrade() ? isCrack : isCrack;
}
inline bool Door::isDeformationDefect()
{
	return isFirstGrade() ? isDeformation : isSecondGrade() ? isDeformation : false;
}
inline bool Door::isPaintingDefect()
{
	return isFirstGrade() ? isPainitingDefect : isSecondGrade() ? isPainitingDefect : isPainitingDefect;
}

#endif // _DOOR_H_