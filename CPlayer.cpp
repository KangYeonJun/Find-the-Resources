#include "DXUT.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Destroy();
}

void CPlayer::Init()
{
	m_fAnim.SetFrame(0, 2, 166);

	m_x = 100;
	m_y = 100;

	rc = { 0, 0, 70, 150 };

	
}

void CPlayer::Update()
{
	m_fAnim.Frame();

	rc = { m_x, m_y, m_x + 70, m_y + 150 };
	

	//ÀÌµ¿
	if (INPUTMANAGER->PUSH_KEY('W')) {
		m_y -= 10;
	}

	if (INPUTMANAGER->PUSH_KEY('A')) {
		m_x -= 10;
	} 

	if (INPUTMANAGER->PUSH_KEY('S')) {
		m_y += 10;
	}

	if (INPUTMANAGER->PUSH_KEY('D')) {
		m_x += 10;
	}

	if (INPUTMANAGER->DOWN_KEY(' ')) {
		BULLET->Fire(m_x, m_y);
	}
	BULLET->Update();
}

void CPlayer::Render()
{
	IMAGE->Render(IMAGE->FindImage("PLAYER", m_fAnim.m_iCurFrame), D3DXVECTOR3(m_x, m_y, 0));
	
	BULLET->Render();
}

void CPlayer::Destroy()
{

}