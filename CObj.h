#pragma once
class CObj
{
protected:
	INFO m_tInfo;
	int iCurFrame;

public:
	inline void SetFrame(int _Check) { iCurFrame = _Check; }
	inline void SetPos(D3DXVECTOR3 _Pos) { m_tInfo.vPos = _Pos; }
public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Destroy()	PURE;
public:
	CObj();
	virtual ~CObj();
};

