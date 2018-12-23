#include "DXUT.h"
#include "CEnemyManager.h"
#include "CEnemy.h"

CEnemyManager::CEnemyManager()
{
}

CEnemyManager::~CEnemyManager()
{
}

void CEnemyManager::Horizontal()
{
	CEnemy *enemy = new CEnemy;
	enemy->Init();
	vEne.push_back(enemy);
}

void CEnemyManager::Update()
{
	if (INPUTMANAGER->DOWN_KEY('R'))
	{
		Horizontal();
	}

	for (auto iter : vEne)
	{
		iter->Update();
	}
}

void CEnemyManager::Render()
{
	for (auto iter : vEne)
	{
		iter->Render();
	}
}

void CEnemyManager::Destroy()
{
	for (iter = vEne.begin(); iter != vEne.end();)
	{
		if ((*iter)->GetDie())
		{
			iter = vEne.erase(iter);
		}
		else
			iter++;
	}
}