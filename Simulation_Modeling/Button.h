#pragma once

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "stdafx.h"
#include "Object.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

class Button : public Object
{
public:
	inline Button();

	inline virtual ~Button(){};

};

Button::Button()
{
	position = { 0, 0 };
	size = { 0, 0 };
	posOnTex = { 1820, 695 };
	sizeOnTex = { 50, 60 };
	texSize = { 1918, 1091 };
	texPath = "images/button.tga";
}

#endif // _BUTTON_H_