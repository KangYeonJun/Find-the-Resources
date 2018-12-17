#pragma once

class CEnemy
{
private:
	int m_iX, m_iY;
	RECT rc;

public:
	CEnemy();
	virtual ~CEnemy();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	void Horizontal();

	inline RECT GetRect() { return rc; };
};

