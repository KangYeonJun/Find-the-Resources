#pragma once
#include "CObj.h"

class CBullet
{
private:
	int m_iX, m_iY;
	

public:
	RECT rc = { 0, 0, 32, 32 };

	CBullet();
	virtual ~CBullet();

	virtual void Init(int px, int py);
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	inline RECT GetRect() { return rc; };
};