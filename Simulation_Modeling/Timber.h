#pragma once

#ifndef _TIMBER_H_
#define _TIMBER_H_

#include "stdafx.h"
#include "Object.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

#define RANDNUM (double)rand() / (RAND_MAX + 1.0)

class Timber : public Object
{
private:

	double m_humidity = 65; // Expected humidity of the timber
	double sg_humidity = 7; // Humidity dispersion of the timber
	double m_knotCount = 2.5; // Expected knot count of the timber
	double sg_knotCount = 2; // Knot count dispersion of the timber
	double m_diametr = 0.35; // Expected diametr of the timber
	double sg_diametr = 0.15; // Diametr dispersion of the timber
	double m_length = 4; // Expected length of the timber
	double sg_length = 2; // Length dispersion of the timber

	enum { Idle, ToPSBench, Done, Skiped } State = Idle; // State of the timber, related to movement along a conveyor belt

public:
	Timber() {};
	inline Timber(bool humidity, bool knotCount, bool diametr, bool length, bool mould, bool crack, UINT batchNum, std::default_random_engine& generator);
	
	inline void genParams(bool humidity, bool knotCount, bool diametr, bool length, bool mould, bool crack, std::default_random_engine& generator);
	
	inline bool isIdle();
	inline bool isToPSBench();
	inline bool isDone();
	inline bool isSkiped();
	inline void setIdle();
	inline void setToPSBench();
	inline void setDone();
	inline void setSkiped();

	inline virtual ~Timber(){};


	double humidity;
	unsigned int knotCount;
	double diametr;
	double length;
	bool isMould;
	bool isCrack;
	UINT batchNum; // Batch number from which the timber was taken
};

Timber::Timber(bool humidity, bool knotCount, bool diametr, bool length, bool mould, bool crack, UINT batchNum, std::default_random_engine& generator)
{
	genParams(humidity, knotCount, diametr, length, mould, crack, generator);

	this->batchNum = batchNum;
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 188, 796 };
	sizeOnTex = { 50, 176};
	texSize = { 1918, 1091 };
	texPath = "images/products/timber.tga";

}

bool Timber::isIdle()
{ return State == Idle; }

bool Timber::isToPSBench()
{ return State == ToPSBench; }

bool Timber::isDone()
{ return State == Done; }

bool Timber::isSkiped()
{ return State == Skiped; }

void Timber::setIdle()
{
	State = Idle;
}

void Timber::setToPSBench()
{
	State = ToPSBench;
}

void Timber::setDone()
{
	State = Done;
}

void Timber::setSkiped()
{
	State = Skiped;
}

void Timber::genParams(bool humidity, bool knotCount, bool diametr, bool length, bool mould, bool crack, std::default_random_engine& generator)
{

	if (!humidity)
	{
		std::normal_distribution<double> humidityDistr(m_humidity, sg_humidity);
		this->humidity = abs(humidityDistr(generator));
		this->humidity = this->humidity> 100 ? 100 : this->humidity;
	}
	else
	{
		std::normal_distribution<double> humidityDistr(m_humidity + 20, sg_humidity);
		this->humidity = abs(humidityDistr(generator));
		this->humidity = this->humidity> 100 ? 100 : this->humidity;
	}

	if (!knotCount)
	{
		std::normal_distribution<double> knotCountDistr(m_knotCount, sg_knotCount);
		this->knotCount = (int)abs(knotCountDistr(generator));
	}
	else
	{
		std::normal_distribution<double> knotCountDistr(m_knotCount + 3, sg_knotCount);
		this->knotCount = (int)abs(knotCountDistr(generator));
	}

	if (!diametr)
	{
		std::normal_distribution<double> diametrDistr(m_diametr, sg_diametr);
		this->diametr = abs(diametrDistr(generator));
		this->diametr = this->diametr < 0.2 ? 0.2 : (this->diametr > 1 ? 1 : this->diametr);
	}
	else
	{
		std::normal_distribution<double> diametrDistr(m_diametr - 0.1, sg_diametr - 0.1);
		this->diametr = abs(diametrDistr(generator));
		this->diametr = this->diametr < 0.2 ? 0.2 : (this->diametr > 1 ? 1 : this->diametr);
	}

	if (!length)
	{
		std::normal_distribution<double> lenghtDistr(m_length, sg_length);
		this->length = abs(lenghtDistr(generator));
		this->length = this->length < 1 ? 1 : (this->length > 8 ? 8 : this->length);
	}
	else
	{
		std::normal_distribution<double> lenghtDistr(m_length - 2, sg_length);
		this->length = abs(lenghtDistr(generator));
		this->length = this->length < 0.5 ? 0.5 : (this->length > 8 ? 8 : this->length);
	}

	if (!mould)
		this->isMould = RANDNUM < 0.03 ? true : false;
	else
		this->isMould = RANDNUM < 0.35 ? true : false;

	if (!crack)
		this->isCrack = RANDNUM < 0.05 ? true : false;
	else
		this->isCrack = RANDNUM < 0.35 ? true : false;
}

#endif // _TIMBER_H_