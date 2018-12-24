#pragma once

class CBullet
{
private:
	FRAME m_fAnim;

	int m_iX, m_iY;
	bool isDie;
	RECT rc;

public:
	CBullet();
	virtual ~CBullet();

	virtual void Init(int px, int py);
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	inline RECT GetRect() { return rc; };
	inline bool GetDie() { return isDie; };
	inline void SetDie(bool _check) { isDie = _check; };
};