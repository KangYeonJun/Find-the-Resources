#pragma once

class CEnemy
{
private:
	FRAME m_fAnim;
	RECT rc;
	
	int m_iX, m_iY;
	bool isDie;

public:
	CEnemy();
	virtual ~CEnemy();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	void Horizontal();

	inline RECT GetRect() { return rc; };
	inline bool GetDie() { return isDie; };
	inline void SetDie(bool _check) { isDie = _check; };
};

