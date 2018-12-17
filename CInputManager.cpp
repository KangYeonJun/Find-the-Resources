#include "DXUT.h"
#include "CInputManager.h"

CInputManager::CInputManager()
{
}

CInputManager::~CInputManager()
{
}

void CInputManager::KeyUpdate()
{
	memcpy(m_OldKeyState, m_CurKeyState, 256);

	for (int i = 0; i < 256; i++)
	{
		if (HIBYTE(GetAsyncKeyState(i)))
			m_CurKeyState[i] = 1;

		else
			m_CurKeyState[i] = 0;
	}
}
POINT CInputManager::GetpMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return pt;
}
D3DXVECTOR3 CInputManager::GetvScreenMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	D3DXVECTOR3 vMousePos = D3DXVECTOR3((float)pt.x, (float)pt.y, 0);

	return vMousePos;
}