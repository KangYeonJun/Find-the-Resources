#include "DXUT.h"
#include "CBulletManager.h"
#include "CBullet.h"


CBulletManager::CBulletManager()
{
}

CBulletManager::~CBulletManager()
{
}

void CBulletManager::Fire(int px, int py)
{
	CBullet *bullet = new CBullet;
	bullet->Init(px, py);
	vBullet.push_back(bullet);
}

void CBulletManager::Update()
{
	for (auto iter : vBullet)
	{
		iter->Update();
	}
}

void CBulletManager::Render()
{
	for (auto iter : vBullet)
	{
		iter->Render();
	}
}

void CBulletManager::Destroy()
{
	for (iter = vBullet.begin(); iter != vBullet.end();)
	{
		if ((*iter)->GetDie())
		{
			iter = vBullet.erase(iter);
		}
		else
			iter++;
	}

	printf("%d\n", vBullet.size());
}
