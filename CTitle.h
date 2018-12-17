#pragma once
#include "CScene.h"

class CObj;
class CTitle :
	public CScene
{
private:
	DWORD dwSoundTime;
	
	CObj *m_button;
	list<CObj*> m_ButtonList;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

public:
	CTitle();
	virtual ~CTitle();
};

