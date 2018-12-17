#pragma once
class CTexture
{
public:
	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXIMAGE_INFO m_Info;
public:
	virtual CTexture* AddImage(const TCHAR* path, int iCnt = 0)		PURE;
	virtual CTexture* FindImage(int iCnt = 0)						PURE;
public:
	CTexture();
	virtual ~CTexture();
};

