#pragma once
#include "CTexture.h"
class CSingleTexture :
	public CTexture
{
public:
	virtual CTexture* AddImage(const TCHAR* path, int iCnt = 0);
	virtual CTexture* FindImage(int iCnt = 0);
public:
	CSingleTexture();
	virtual ~CSingleTexture();
};

