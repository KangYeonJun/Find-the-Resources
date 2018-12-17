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
	m_fAnim.SetFrame(0, 3, 125);

	m_x = 100;
	m_y = 100;

	m_rc2 = { 0, 0, 128, 128 };

	
}

void CPlayer::Update()
{
	m_fAnim.Frame();

	m_rc2 = { m_x, m_y, m_x + 128, m_y + 128 };
	

	//이동
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

	//충돌
	

	if (INPUTMANAGER->DOWN_KEY(' ')) {
		BULLETMANAGER->Fire(m_x, m_y);
	}
	BULLETMANAGER->Update();
}

void CPlayer::Render()
{
	IMAGE->Render(IMAGE->FindImage("RECT"), D3DXVECTOR3(m_x, m_y, 0));
	

	IMAGE->Render(IMAGE->FindImage("MARIO", m_fAnim.m_iCurFrame), D3DXVECTOR3(m_x, m_y, 0));
	
	BULLETMANAGER->Render();
}

void CPlayer::Destroy()
{

}