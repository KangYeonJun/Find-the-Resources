#include "DXUT.h"
#include "CCamera.h"


CCamera::CCamera() : bShake(false)
{
}


CCamera::~CCamera()
{
}

void CCamera::Init(int _Width, int _Height, float _fAngle, D3DXVECTOR3 _vScale)
{
	width = _Width;
	height = _Height;
	fAngle = _fAngle;
	vScale = _vScale;

	CameraX = WINSIZEX / 2;
	CameraY = WINSIZEY / 2;

	bMove = false;
	Following = D3DXVECTOR3(WINSIZEX / 2, WINSIZEY / 2, 0);

	fTargetScale = _vScale.x;

	D3DXMatrixOrthoLH(&OrthoMat, width, -height, 0, 1);
	D3DXMatrixIdentity(&IdentityMat);
}
void CCamera::Update()
{
	float fDifferent = fabsf(fTargetScale - vScale.x);

	if (fDifferent < 0.03f)
	{
		vScale = D3DXVECTOR3(fTargetScale, fTargetScale, 0);
	}

	else
	{
		float fScale = vScale.x;

		if (fTargetScale < vScale.x)
		{
			fScale -= 1 * DELTA;
		}

		else
		{
			fScale += 1 * DELTA;
		}

		vScale = D3DXVECTOR3(fScale, fScale, 0);
	}

	if (bShake)
	{
		if (dwShakeTime + fShakeDelay > GetTickCount())
		{
			if (dwShakeTime + 50 < GetTickCount())
			{
				random_device _Rand;
				uniform_int_distribution<__int64> distRand(-30, 30);

				CameraX = vOldPos.x + distRand(_Rand);
				CameraY = vOldPos.y + distRand(_Rand);
			}
		}

		else
		{
			bShake = false;
			CameraX = vOldPos.x;
			CameraY = vOldPos.y;
		}
	}

	else if (bMove)
	{
		D3DXVECTOR3 MyPos = D3DXVECTOR3(CameraX, CameraY, 0);
		D3DXVECTOR3 vDir = Following - MyPos;
		float fDistance = D3DXVec3Length(&vDir);

		if (fDistance > 20.f)
		{
			vOldPos = vOldPos + (Following - vOldPos) * 0.03f;
			CameraX = vOldPos.x;
			CameraY = vOldPos.y;
		}

		else
		{
			CameraX = Following.x;
			CameraY = Following.y;
			bMove = false;
		}
	}

	this->ViewMat = D3DXMATRIX(
		vScale.x * cos(fAngle), vScale.x * sin(fAngle), 0, 0,
		-vScale.y * sin(fAngle), vScale.y * cosf(fAngle), 0, 0,
		0, 0, vScale.z, 0,
		-CameraX * vScale.x * cos(fAngle) + CameraY * vScale.y * sin(fAngle),
		-CameraX * vScale.y * sin(fAngle) - CameraY * vScale.y * cos(fAngle), 0, 1);
}
void CCamera::SetTransform()
{
	g_device->SetTransform(D3DTS_PROJECTION, &OrthoMat);
	g_device->SetTransform(D3DTS_WORLD, &IdentityMat);
	g_device->SetTransform(D3DTS_VIEW, &ViewMat);
}

void CCamera::Move(int _x, int _y)
{
	CameraX += _x * DELTA;
	CameraY += _y * DELTA;
}

void CCamera::ShakeCamera(float Delay)
{
	bShake = true;
	fShakeDelay = Delay;
	vOldPos = D3DXVECTOR3(CameraX, CameraY, 0);
	dwShakeTime = GetTickCount();
}

bool CCamera::CheckScreen(D3DXVECTOR3 vPos, D3DXVECTOR3 vSize)
{
	if (vPos.x + vSize.x / 2 > CameraX - WINSIZEX / 2 ||
		vPos.x - vSize.x / 2 < CameraX + WINSIZEX / 2 ||
		vPos.y + vSize.y / 2 > CameraY - WINSIZEY / 2 ||
		vPos.y - vSize.y / 2 < CameraY + WINSIZEY / 2)
	{
		return true;
	}

	return false;
}