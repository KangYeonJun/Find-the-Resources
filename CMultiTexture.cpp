#include "DXUT.h"
#include "CMultiTexture.h"
#include "CSingleTexture.h"

CMultiTexture::CMultiTexture()
{
}


CMultiTexture::~CMultiTexture()
{
	for (auto iter : m_vecTexture)
	{
		SAFE_DELETE(iter);
	}

	m_vecTexture.clear();
}

CTexture* CMultiTexture::AddImage(const TCHAR* path, int iCnt)
{
	TCHAR sz[128] = L"";

	for (int i = 1; i <= iCnt; i++)
	{
		wsprintf(sz, path, i);

		CTexture* pTexture = new CSingleTexture;
		pTexture->AddImage(sz);
		m_vecTexture.push_back(pTexture);
	}

	return this;
}
CTexture* CMultiTexture::FindImage(int iCnt)
{
	if (iCnt == -1)
		return this;

	else
		return m_vecTexture[iCnt];
}