#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include "Resource.h"
#include "macroFunc.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "utils.h"
#include "cameraManager.h"
#include "timeManager.h"
#include "sceneManager.h"
#include "stateManager.h"
#include "printManager.h"
#include "collisionManager.h"
#include "uiManager.h"
#include "EffectManager.h"
#include "inventoryManager.h"
#include "tileManager.h"
#include "txtData.h"
#include "streamManager.h"
#include "soundManager.h"

using namespace std;
using namespace MACRO_FUNC;

//==================================
// ## 매크로 처리 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("THE LEGEND OF ZELDA : A LINK TO THE PAST"))
#define WINSTARTX 50	//윈도우 창 시작좌표 (left)
#define WINSTARTY 50	//윈도우 창 시작좌표 (top)
#define WINSIZEX 1024	//윈도우 가로크기
#define WINSIZEY 896	//윈도우 세로크기
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define STATEMANAGER stateManager::getSingleton()
#define PRINTMANAGER printManager::getSingleton()
#define COLLISIONMANAGER collisionManager::getSingleton()
//#define ITEMMANAGER itemManager::getSingleton()
#define UIMANAGER uiManager::getSingleton()
#define EFFECTMANAGER EffectManager::getSingleton()
#define INVENTORYMANAGER inventoryManager::getSingleton()
#define TILEMANAGER tileManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define STREAMMANAGER streamManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()

#define SAFE_DELETE(p) { if(p) { delete(p); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); (p) = nullptr; } }
#define SAFE_RELEASE(p) { if(p) { (p)->release(); (p) = NULL; } }

//==================================
// ## extern ##
//==================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;