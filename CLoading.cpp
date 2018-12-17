#include "DXUT.h"
#include "CLoading.h"
#include "CTexture.h"

CLoading::CLoading()
{
	IMAGE->AddImage("Title", L"Image/Title.png");
	IMAGE->AddImage("STARTBUTTON", L"Image/StartButton.png");

	IMAGE->AddImage("MARIO", L"Image/Mario(%d).png", 4);
	IMAGE->AddImage("BULLET", L"Image/Bullet.png");
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