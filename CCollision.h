#pragma once
class CCollision : public CSingleton<CCollision>
{
private:


public:
	CCollision();
	virtual ~CCollision();

	virtual void Update();

	bool IsCollision(RECT rc1, RECT rc2);
};

#define COLLISION CCollision::GetInstance()