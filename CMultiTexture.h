#pragma once
#include "CTexture.h"
class CMultiTexture :
	public CTexture
{
private:
	vector<CTexture*> m_vecTexture;
public:
	virtual CTexture* AddImage(const TCHAR* path, int iCnt = 0);
	virtual CTexture* FindImage(int iCnt = 0);
public:
	CMultiTexture();
	virtual ~CMultiTexture();
};

