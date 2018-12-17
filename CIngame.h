#pragma once
#include "CScene.h"
class CInGame :
	public CScene
{
private:
	DWORD dwSoundTime;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

public:
	CInGame();
	virtual ~CInGame();
};

