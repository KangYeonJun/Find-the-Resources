#include "DXUT.h"
#include "CImageManager.h"
#include "CSingleTexture.h"
#include "CMultiTexture.h"

CImageManager::CImageManager()
{
	D3DXCreateSprite(g_device, &m_pSprite);

	D3DXFONT_DESC m_FontInfo;
	m_FontInfo.Width = 10;
	m_FontInfo.Height = 20;
	m_FontInfo.Weight = FW_HEAVY;
	m_FontInfo.CharSet = HANGUL_CHARSET;

	lstrcpy(m_FontInfo.FaceName, L"HY°ß°íµñ");
	D3DXCreateFontIndirect(g_device, &m_FontInfo, &m_pFont);
}


CImageManager::~CImageManager()
{
	for (auto iter : m_MapTexture)
	{
		SAFE_DELETE(iter.second);
	}

	m_MapTexture.clear();

	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pFont);
}

void CImageManager::AddImage(const string& Key, const TCHAR* path, int iCnt)
{
	auto iter = m_MapTexture.find(Key);

	if (iter == m_MapTexture.end())
	{
		CTexture* pTexture;

		if (iCnt == 0)
			pTexture = new CSingleTexture;

		else
			pTexture = new CMultiTexture;

		m_MapTexture.insert(make_pair(Key, pTexture->AddImage(path, iCnt)));
	}
}
CTexture* CImageManager::FindImage(const string& Key, int iCnt)
{
	auto iter = m_MapTexture.find(Key);

	if (iter != m_MapTexture.end())
	{
		return iter->second->FindImage(iCnt);
	}

	else
		return nullptr;
}
void CImageManager::Render(CTexture* pTexture, const D3DXVECTOR3& m_Info,
	float fRot, D3DCOLOR m_Color)
{
	D3DXMATRIXA16 mat;
	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexture->m_Info.Width / 2, pTexture->m_Info.Height / 2, 0);
	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(fRot), &D3DXVECTOR2(m_Info.x, m_Info.y));
	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTexture, nullptr, &vCenter, nullptr, m_Color);
}

void CImageManager::ScaleRender(CTexture* pTexture, const D3DXVECTOR3& m_Info,
	float fScale, D3DCOLOR m_Color)
{
	D3DXMATRIXA16 mat;
	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexture->m_Info.Width / 2, pTexture->m_Info.Height / 2, 0);
	D3DXMatrixAffineTransformation2D(&mat, fScale, nullptr, 0.f, &D3DXVECTOR2(m_Info.x, m_Info.y));
	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTexture, nullptr, &vCenter, nullptr, m_Color);
}

void CImageManager::CenterRender(CTexture* pTexture, const D3DXVECTOR3& m_Info,
	const D3DXVECTOR3& vCenter, float fRot)
{
	D3DXMATRIXA16 mat;
	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(fRot), &D3DXVECTOR2(m_Info.x, m_Info.y));
	m_pSprite->SetTransform(&mat);
	m_pSprite->Draw(pTexture->m_pTexture, nullptr, &vCenter, nullptr, D3DCOLOR_XRGB(255, 255, 255));
}

void CImageManager::Lost()
{
	m_pSprite->OnLostDevice();
}
void CImageManager::Reset()
{
	m_pSprite->OnResetDevice();
}
void CImageManager::Render_Begin(bool bInterface)
{
	if (bInterface)
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	else
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}
void CImageManager::Render_End()
{
	m_pSprite->End();
}

void CImageManager::RenderText(const D3DXVECTOR3& vPos, const TCHAR* str)
{
	RECT rcFont = { 0 };

	D3DXMATRIX mat;
	D3DXMatrixTranslation(&mat, vPos.x, vPos.y, vPos.z);

	m_pSprite->SetTransform(&mat);

	m_pFont->DrawTextW(m_pSprite,
		str, lstrlen(str), &rcFont, DT_NOCLIP | DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
}