#pragma once
	
class CPlayer : public CSingleton<CPlayer>
{
private:
	CTexture *m_player;
	FRAME m_fAnim;

private:
	int m_x, m_y;
	

public:
	CPlayer();
	virtual ~CPlayer();

	RECT m_rc2;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

#define PLAYER CPlayer::GetInstance()