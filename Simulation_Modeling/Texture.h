#pragma once

/*
Contains texture data
*/
class CTexture
{
public:
	UINT uId; // Texture number in openGL

	UINT uWidth, uHeight; // Texture's size in pixels

	CTexture();
	CTexture(const std::string& strFilename);
	void loadTex(const std::string& strFilename);
	virtual ~CTexture() throw();
};