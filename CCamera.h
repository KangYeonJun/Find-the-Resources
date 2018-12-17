#pragma once
class CCamera : public CSingleton<CCamera>
{
private:
	D3DXMATRIX OrthoMat;
	D3DXMATRIX IdentityMat;
	D3DXMATRIX ViewMat;
	int CameraX, CameraY;
	float width, height;
	D3DXVECTOR3 vOldPos;
	D3DXVECTOR3 vScale;
	D3DXVECTOR3 Following;
	float fAngle, fTargetScale;
	bool bMove;
	bool bShake;
	DWORD dwShakeTime;
	float fShakeDelay;
public:
	void Move(int _x, int _y);
	void Init(int _Width, int _Height, float _fAngle, D3DXVECTOR3 _vScale);
	void Update();
	void SetTransform();
public:
	bool CheckScreen(D3DXVECTOR3 vPos, D3DXVECTOR3 vSize);
	void ShakeCamera(float Delay);
	inline void SetTargetScale(float _Scale) { fTargetScale = _Scale; }
	inline void Follow(D3DXVECTOR3 vPos) { Following = vPos; bMove = true; vOldPos = D3DXVECTOR3(CameraX, CameraY, 0); }
	inline void SetScale(float _Scale) { fTargetScale = _Scale; vScale = D3DXVECTOR3(_Scale, _Scale, 0); }
	inline void SetPos(D3DXVECTOR2 vPos) {
		CameraX = vPos.x; CameraY = vPos.y;
	}
	inline float GetScale() { return vScale.x; }
	inline bool GetMove() { return bMove; }
	inline D3DXVECTOR2 GetScroll() { D3DXVECTOR2 vScroll = D3DXVECTOR2(CameraX - WINSIZEX / 2, CameraY - WINSIZEY / 2); return vScroll; }
public:
	CCamera();
	virtual ~CCamera();
};

#define CAMERA CCamera::GetInstance()
