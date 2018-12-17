#include "DXUT.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Destroy();
}

void CMainGame::Init()
{
	CAMERA->Init(WINSIZEX, WINSIZEY, 0, D3DXVECTOR3(1.f, 1.f, 1.f));
}
void CMainGame::Update()
{
	INPUTMANAGER->KeyUpdate();
	CAMERA->Update();
	SCENE->Update();
}
void CMainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Render_Begin(false);
	SCENE->Render();
	IMAGE->Render_End();
}
void CMainGame::Destroy()
{
	CSceneManager::ReleaseInstance();
	CImageManager::ReleaseInstance();
	CInputManager::ReleaseInstance();
}
void CMainGame::Lost()
{
	IMAGE->Lost();
}
void CMainGame::Reset()
{
	IMAGE->Reset();
}
