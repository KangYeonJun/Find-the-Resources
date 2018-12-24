#pragma once
	
class CPlayer : public CSingleton<CPlayer>
{
private:
	CTexture *m_player;
	FRAME m_fAnim;
	RECT rc;
	int m_x, m_y;

public:
	CPlayer();
	virtual ~CPlayer();

	void Init();
	void Update();
	void Render();
	void Destroy();
};

#define PLAYER CPlayer::GetInstance()