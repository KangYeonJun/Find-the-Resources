#pragma once
#include "CScene.h"

class CTexture;
class CLoading :
	public CScene
{
private:
	CTexture * m_pTex;
	FRAME m_fAnim;

public:
	CLoading();
	virtual ~CLoading();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};