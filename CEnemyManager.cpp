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
	for (auto it : vEne)
	{
		it->Render();
	}
}

void CEnemyManager::Destroy()
{
	vEne.pop_back();
}