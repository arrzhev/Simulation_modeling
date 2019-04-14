#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "GL/GLU.h"
#include "IL/include/IL/il.h"
#include "stdafx.h"
#include "Texture.h"

CTexture::CTexture()
{
	uId = 0;
	uWidth = 0;
	uHeight = 0;
}

CTexture::CTexture(const std::string& strFilename)
{
	UINT uIlId;
	uId     = 0;
	uWidth  = 0;
	uHeight = 0;

	ilGenImages(1, &uIlId);
	ilBindImage(uIlId);

	if (ilLoadImage(strFilename.c_str()))
	{
		if(ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE))
		{
			uWidth  = (UINT)ilGetInteger(IL_IMAGE_WIDTH);
			uHeight = (UINT)ilGetInteger(IL_IMAGE_HEIGHT);

			glGenTextures(1, &uId);
			glBindTexture(GL_TEXTURE_2D, uId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, uWidth, uHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, (UINT*)ilGetData());
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glBindTexture(GL_TEXTURE_2D, NULL);
		}
	}

	ilDeleteImages(1, &uIlId);
}

void CTexture::loadTex(const std::string& strFilename)
{
	UINT uIlId;
	uId = 0;
	uWidth = 0;
	uHeight = 0;

	ilGenImages(1, &uIlId);
	ilBindImage(uIlId);

	if (ilLoadImage(strFilename.c_str()))
	{
		if (ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE))
		{
			uWidth = (UINT)ilGetInteger(IL_IMAGE_WIDTH);
			uHeight = (UINT)ilGetInteger(IL_IMAGE_HEIGHT);

			glGenTextures(1, &uId);
			glBindTexture(GL_TEXTURE_2D, uId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, uWidth, uHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, (UINT*)ilGetData());
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glBindTexture(GL_TEXTURE_2D, NULL);
		}
	}

	ilDeleteImages(1, &uIlId);
}
CTexture::~CTexture() throw()
{
	if(uId != 0)
		glDeleteTextures(1, &uId);
}