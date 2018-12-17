#include "DXUT.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CLoading.h"
#include "CTitle.h"
#include "CInGame.h"


CSceneManager::CSceneManager() : m_CurScene(nullptr), m_NextScene(nullptr)
{
	AddScene("S_LOADING", new CLoading);
	AddScene("S_TITLE", new CTitle);
	AddScene("S_INGAME", new CInGame);

	ChangeScene("S_LOADING");
}


CSceneManager::~CSceneManager()
{
	Destroy();
}

void CSceneManager::ChangeScene(string str)
{
	auto iter = m_MapScene.find(str);

	if (iter != m_MapScene.end())
	{
		m_NextScene = iter->second;
	}
}
void CSceneManager::AddScene(string str, CScene* pScene)
{
	auto iter = m_MapScene.find(str);

	if (iter == m_MapScene.end())
	{
		m_MapScene.insert(make_pair(str, pScene));
	}
}
void CSceneManager::Update()
{
	if (m_NextScene)
	{
		if (m_CurScene)
			m_CurScene->Destroy();

		m_CurScene = m_NextScene;
		m_CurScene->Init();
		m_NextScene = nullptr;
	}

	m_CurScene->Update();
}
void CSceneManager::Render()
{
	m_CurScene->Render();
}
void CSceneManager::Destroy()
{
	for (auto iter : m_MapScene)
	{
		SAFE_DELETE(iter.second);
	}

	m_MapScene.clear();
}