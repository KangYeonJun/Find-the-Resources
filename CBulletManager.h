#pragma once

class CBullet;
class CBulletManager : public CSingleton<CBulletManager>
{
public:
	vector<CBullet*> vBullet;

public:
	CBulletManager();
	virtual ~CBulletManager();

	void Fire(int px, int py);
	void Update();
	void Render();
	void Destroy();
	
};

#define BULLETMANAGER CBulletManager::GetInstance()