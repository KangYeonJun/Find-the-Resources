#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <functional>
#include <random>
#include <thread>

using namespace std;

#include "Define.h"
#include "Constant.h"
#include "Struct.h"
#include "Macro.h"

#include "CSceneManager.h"
#include "CImageManager.h"
#include "CInputManager.h"
#include "CEnemyManager.h"
#include "CBulletManager.h"

#include "CCamera.h"
#include "CPlayer.h"
#include "CEnemy.h"

#include "CCollision.h"

//콘솔창 띄우기
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")