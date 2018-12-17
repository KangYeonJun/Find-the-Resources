#pragma once

class CEnemy;
class CEnemyManager : public CSingleton<CEnemyManager>
{
public:
	vector<CEnemy*> vEne;

public:
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

public:
	CEnemyManager();
	virtual ~CEnemyManager();

	void Horizontal();
};

#define ENEMY CEnemyManager::GetInstance()