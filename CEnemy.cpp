#include "DXUT.h"
#include "CEnemy.h"
#include "CBullet.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

void CEnemy::Horizontal()
{
	
}

void CEnemy::Init()
{
	m_fAnim.SetFrame(0, 7, 100);

	rc = { 0, 0, 128, 128 };

	m_iX = 1300;
	m_iY = rand() % 640;

	isDie = false;
}

void CEnemy::Update()
{
	m_fAnim.Frame();

	rc = { m_iX - 64, m_iY - 64, m_iX + 128 - 64, m_iY + 128 - 64 };

	m_iX -= 5;
}

void CEnemy::Render()
{
	IMAGE->Render(IMAGE->FindImage("Shark", m_fAnim.m_iCurFrame), D3DXVECTOR3(m_iX, m_iY, 0));
}

void CEnemy::Destroy()
{

}