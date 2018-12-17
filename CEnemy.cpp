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
	rc = { 0, 0, 128, 128 };

	m_iX = 1000;
	m_iY = rand() % 640;
}

void CEnemy::Update()
{
	rc = { m_iX - 64, m_iY - 64, m_iX + 128 - 64, m_iY + 128 - 64 };

	//m_iX -= 5;
}

void CEnemy::Render()
{
	IMAGE->Render(IMAGE->FindImage("RECT"), D3DXVECTOR3(m_iX, m_iY, 0));
}

void CEnemy::Destroy()
{

}