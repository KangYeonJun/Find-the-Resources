#include "DXUT.h"
#include "CBullet.h"

CBullet::CBullet()
{
	
}

CBullet::~CBullet()
{
}

void CBullet::Init(int px, int py)
{
	m_fAnim.SetFrame(0, 3, 125);

	rc = { 0, 0, 40, 50 };

	m_iX = px;
	m_iY = py;

	isDie = false;
}

void CBullet::Update()
{
	m_fAnim.Frame();

	rc = { m_iX - (40 / 2), m_iY - (50 / 2), m_iX + 32 - (40 / 2), m_iY + 32 - (50 / 2) };

	m_iX += 15;
}

void CBullet::Render()
{
	IMAGE->Render(IMAGE->FindImage("BULLET", m_fAnim.m_iCurFrame), D3DXVECTOR3(m_iX, m_iY, 0));
}

void CBullet::Destroy()
{
	
}