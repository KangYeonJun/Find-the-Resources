#include "DXUT.h"
#include "CTexture.h"


CTexture::CTexture() : m_pTexture(nullptr)
{
}


CTexture::~CTexture()
{
	SAFE_RELEASE(m_pTexture);
}
