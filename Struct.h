#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vSize;
}INFO;

typedef struct tagTile
{
	D3DXVECTOR3 vPos;
	int iOption;
	bool bFind;
}TILE;

typedef struct tagFrame
{
	int m_iCurFrame, m_iFrameStart, m_iFrameEnd;
	DWORD dwFrameTime;
	DWORD m_fFrameDelay;

	void SetFrame(int _iStart, int _iEnd, float _Delay)
	{
		m_iCurFrame = m_iFrameStart = _iStart;
		m_iFrameEnd = _iEnd;
		m_fFrameDelay = _Delay;
		dwFrameTime = timeGetTime();
	}

	bool Frame()
	{
		if (dwFrameTime + m_fFrameDelay < timeGetTime())
		{
			dwFrameTime = timeGetTime();
			if (++m_iCurFrame > m_iFrameEnd)
			{
				m_iCurFrame = m_iFrameStart;
				dwFrameTime = timeGetTime();
				return true;
			}
		}

		return false;
	}
}FRAME;