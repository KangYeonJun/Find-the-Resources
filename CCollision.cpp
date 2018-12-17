#include "DXUT.h"
#include "CCollision.h"
#include "CEnemy.h"
#include "CBullet.h"


CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}

void CCollision::Update()
{
	for (auto Enemy : ENEMY->vEne)
	{
		for (auto Bullet : BULLETMANAGER->vBullet)
		{
			if (IsCollision(Bullet->GetRect(), Enemy->GetRect()))
			{
				printf("true\n");
			}
		}
	}
}

bool CCollision::IsCollision(RECT rc1, RECT rc2)
{
	RECT temp;

	// 충돌이 좀 이상함
	if (IntersectRect(&temp, &rc1, &rc2))
	{
		return true;
	}

	/*rc1.right = rc1.left + 128;
	rc1.bottom = rc1.top + 128;

	if ((rc1.left < rc2.right && rc1.right > rc2.left) && (rc1.top < rc2.bottom && rc1.bottom > rc2.top))
	{
		return true;
	}*/

	return false;
}
