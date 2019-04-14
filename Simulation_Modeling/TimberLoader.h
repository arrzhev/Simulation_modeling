#pragma once

#ifndef _TIMBERLOADER_H_
#define _TIMBERLOADER_H_

#include "stdafx.h"
#include "Object.h"
#include "Timber.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class TimberLoader : public Object
{
public:

	inline TimberLoader();
	inline virtual ~TimberLoader(){};

};

TimberLoader::TimberLoader()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 88, 774 };
	sizeOnTex = { 250, 312 };
	texSize = { 1918, 1091 };
	texPath = "images/benches/timberCarrier.tga";
}


#endif // _TIMBERLOADER_H_