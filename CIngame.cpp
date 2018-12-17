#include "DXUT.h"
#include "CInGame.h"
#include "CEnemy.h"
#include "CPlayer.h"

CInGame::CInGame() : dwSoundTime(0)
{
}

CInGame::~CInGame()
{
	Destroy();
}

void CInGame::Init()
{
	PLAYER->Init();
}
void CInGame::Update()
{
	PLAYER->Update();
	ENEMY->Update();
	COLLISION->Update();
}
void CInGame::Render()
{
	PLAYER->Render();
	ENEMY->Render();
}
void CInGame::Destroy()
{

}