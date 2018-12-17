#pragma once

class CInputManager : public CSingleton<CInputManager>
{
public:
	char m_CurKeyState[256];
	char m_OldKeyState[256];
public:
	void KeyUpdate();
	POINT GetpMousePos();
	D3DXVECTOR3 GetvScreenMousePos();

public:
	inline bool DOWN_KEY(int vk) { return m_CurKeyState[vk] == 1 && m_OldKeyState[vk] == 0 ? true : false; }
	inline bool UP_KEY(int vk) { return m_CurKeyState[vk] == 0 && m_OldKeyState[vk] == 1 ? true : false; }
	inline bool PUSH_KEY(int vk) { return m_CurKeyState[vk] == 1 && m_OldKeyState[vk] == 1 ? true : false; }
public:
	CInputManager();
	virtual ~CInputManager();
};

#define INPUTMANAGER CInputManager::GetInstance()
