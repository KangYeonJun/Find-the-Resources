#pragma once

class CMainGame
{
private:

public:
	void Init();
	void Update();
	void Render();
	void Destroy();
	void Lost();
	void Reset();

public:
	CMainGame();
	virtual ~CMainGame();
};

