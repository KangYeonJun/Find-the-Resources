#pragma once

class CTexture;
class CImageManager : public CSingleton<CImageManager>
{
private:
	map<string, CTexture*> m_MapTexture;
	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT m_pFont;
public:
	void AddImage(const string& Key, const TCHAR* path, int iCnt = 0);
	CTexture* FindImage(const string& Key, int iCnt = 0);
	void Render(CTexture* pTexture, const D3DXVECTOR3& m_Info,
		float fRot = 0.f, D3DCOLOR m_Color = D3DCOLOR_XRGB(255, 255, 255));
	void ScaleRender(CTexture* pTexture, const D3DXVECTOR3& m_Info,
		float fScale = 1.f, D3DCOLOR m_Color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(CTexture* pTexture, const D3DXVECTOR3& m_Info,
		const D3DXVECTOR3& vCenter, float fRot = 0.f);
	void RenderText(const D3DXVECTOR3& vPos, const TCHAR* str);
	void Lost();
	void Reset();
	void Render_Begin(bool bInterface);
	void Render_End();
public:
	CImageManager();
	virtual ~CImageManager();
};

#define IMAGE CImageManager::GetInstance()