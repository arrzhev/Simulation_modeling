#pragma once

#ifndef _BRIGADE_H_
#define _BRIGADE_H_

#include "stdafx.h"
#include "Object.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Settings;

class Employee : public Object
{
public:

	inline Employee();
	inline virtual ~Employee(){};
};

Employee::Employee()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 414, 586 };
	sizeOnTex = { 86, 222 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/1brigade1employee.tga";
}

class Brigade
{
public:
	Employee employee1;
	Employee employee2;
	Employee employee3;

	bool isActive = false; // Is the brigade working
	double effectiveCoef = 1; // Brigade efficiency ratio(the higher the more likely the deffects)

	inline Brigade(const Settings& settings);

	/// <summary> Setting the brigade efficiency ratio to 1 </summary>
	inline void trianBrigade() { setEffectiveCoef(1.0); }

	inline void setEffectiveCoef(double effectiveCoef){ this->effectiveCoef = effectiveCoef; }

	inline virtual ~Brigade(){};

private:
	const Settings* settings = nullptr; // Simulation settings, includes breakdown script
};

Brigade::Brigade(const Settings& settings)
{
	this->settings = &settings;

}

#endif // _BRIGADE_H_