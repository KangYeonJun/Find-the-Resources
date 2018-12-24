#include "DXUT.h"
#include "CLoading.h"
#include "CTexture.h"

CLoading::CLoading()
{
	IMAGE->AddImage("INGAME_BACKGROUND", L"Image/ocean.png");
	IMAGE->AddImage("Title", L"Image/Title.png");
	IMAGE->AddImage("STARTBUTTON", L"Image/StartButton.png");

	IMAGE->AddImage("PLAYER", L"Image/Player(%d).png", 3);
	IMAGE->AddImage("BULLET", L"Image/Bullet(%d).png", 4);
	IMAGE->AddImage("Shark", L"Image/Shark(%d).png", 8);
	IMAGE->AddImage("RECT", L"Image/rect.png");
	
}


CLoading::~CLoading()
{
}

void CLoading::Init()
{
	
}
void CLoading::Update()
{
	SCENE->ChangeScene("S_TITLE");
}
void CLoading::Render()
{
	
}
void CLoading::Destroy()
{

}