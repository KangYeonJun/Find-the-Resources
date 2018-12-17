#pragma once
#include "CObj.h"

class CTexture;
class CButton :
	public CObj
{
private:
	CTexture * m_pTex;
	RECT m_CollRect;
	function<void()> m_Func;
	int iCurFrame;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
public:
	CButton();
	CButton(CTexture* pTexture, const D3DXVECTOR3& vPos, const D3DXVECTOR3& vSize, function<void()> _Func);
	virtual ~CButton();
};

