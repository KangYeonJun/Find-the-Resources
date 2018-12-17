#include "DXUT.h"
#include "CTitle.h"
#include "CButton.h"

CTitle::CTitle() : dwSoundTime(0)
{
}


CTitle::~CTitle()
{
	Destroy();
}

void CTitle::Init()
{
	m_button = new CButton(IMAGE->FindImage("STARTBUTTON"), D3DXVECTOR3(128, 630, 0), D3DXVECTOR3(200, 100, 0), []() { SCENE->ChangeScene("S_INGAME"); });
	m_button->Init();
	m_ButtonList.push_back(m_button);
}

void CTitle::Update()
{
	for (auto iter : m_ButtonList)
	{
		iter->Update();
	}
}

void CTitle::Render()
{
	IMAGE->Render(IMAGE->FindImage("Title"), D3DXVECTOR3(WINSIZEX / 2, WINSIZEY / 2, 0));

	for (auto iter : m_ButtonList)
	{
		iter->Render();
	}
}

void CTitle::Destroy()
{

}