#pragma once

class CScene;
class CSceneManager : public CSingleton<CSceneManager>
{
private:
	map<string, CScene*> m_MapScene;
	CScene * m_CurScene;
	CScene* m_NextScene;
public:
	void ChangeScene(string str);
	void AddScene(string str, CScene* pScene);
	void Update();
	void Render();
	void Destroy();
public:
	CSceneManager();
	virtual ~CSceneManager();
};

#define SCENE CSceneManager::GetInstance()