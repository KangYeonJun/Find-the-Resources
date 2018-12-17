#include "DXUT.h"
#include "CButton.h"
#include "CTexture.h"

CButton::CButton()
{
}

CButton::CButton(CTexture* pTexture, const D3DXVECTOR3& vPos, const D3DXVECTOR3& vSize, function<void()> _Func) : iCurFrame(0)
{
	m_pTex = pTexture;
	m_tInfo.vPos = vPos;
	m_tInfo.vSize = vSize;
	m_Func = _Func;
}

CButton::~CButton()
{
}

void CButton::Init()
{
	m_CollRect = { LONG(m_tInfo.vPos.x - m_tInfo.vSize.x / 2), LONG(m_tInfo.vPos.y - m_tInfo.vSize.y / 2),
		LONG(m_tInfo.vPos.x + m_tInfo.vSize.x / 2), LONG(m_tInfo.vPos.y + m_tInfo.vSize.y / 2) };
}
void CButton::Update()
{
	if (PtInRect(&m_CollRect, INPUTMANAGER->GetpMousePos()))
	{
		iCurFrame = 1;

		if (INPUTMANAGER->DOWN_KEY(VK_LBUTTON))
		{
			m_Func();
		}
	}

	else
		iCurFrame = 0;
}
void CButton::Render()
{
	IMAGE->Render(m_pTex->FindImage(iCurFrame), m_tInfo.vPos);
}
void CButton::Destroy()
{

}