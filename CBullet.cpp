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
	m_iX = px;
	m_iY = py;
}

void CBullet::Update()
{
	rc = { m_iX - 16, m_iY - 16, m_iX + 32 - 16, m_iY + 32 - 16 };

	m_iX += 15;
}

void CBullet::Render()
{
	IMAGE->Render(IMAGE->FindImage("BULLET"), D3DXVECTOR3(m_iX, m_iY, 0));
}

void CBullet::Destroy()
{
	
}

