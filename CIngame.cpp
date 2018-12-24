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
	IMAGE->Render(IMAGE->FindImage("INGAME_BACKGROUND"), D3DXVECTOR3(WINSIZEX / 2, WINSIZEY / 2, 0));

	PLAYER->Render();
	ENEMY->Render();
}
void CInGame::Destroy()
{

}