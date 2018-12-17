#include "DXUT.h"
#include "CSingleTexture.h"


CSingleTexture::CSingleTexture()
{
}


CSingleTexture::~CSingleTexture()
{
}

CTexture* CSingleTexture::AddImage(const TCHAR* path, int iCnt)
{
	D3DXGetImageInfoFromFile(path, &m_Info);
	D3DXCreateTextureFromFileEx(g_device, path, m_Info.Width, m_Info.Height, m_Info.MipLevels, 0,
		m_Info.Format, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_ARGB(10, 10, 10, 10), &m_Info,
		NULL, &m_pTexture);

	return this;
}
CTexture* CSingleTexture::FindImage(int iCnt)
{

	return this;
}
