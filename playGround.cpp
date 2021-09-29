#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new Player;
	_player->init();

	TILEMANAGER->init(_player);
	SCENEMANAGER->init(_player);
	COLLISIONMANAGER->init(_player);
	UIMANAGER->init(_player);
	EFFECTMANAGER->init();
	INVENTORYMANAGER->init();
	SOUNDMANAGER->init();

	SCENEMANAGER->changeScene("title");

	_debug = false;

	return S_OK;
}

HRESULT playGround::init(const char * str)
{
	gameNode::init(true);

	_debug = false;

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

	INVENTORYMANAGER->release();
	INVENTORYMANAGER->releaseSingleton();

	TILEMANAGER->release();
	TILEMANAGER->releaseSingleton();

	UIMANAGER->release();
	UIMANAGER->releaseSingleton();

	COLLISIONMANAGER->release();
	COLLISIONMANAGER->releaseSingleton();

	SCENEMANAGER->release();
	SCENEMANAGER->releaseSingleton();

	EFFECTMANAGER->release();
	EFFECTMANAGER->releaseSingleton();

	INVENTORYMANAGER->release();
	INVENTORYMANAGER->releaseSingleton();

	SOUNDMANAGER->release();
	SOUNDMANAGER->releaseSingleton();
}


void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		_debug = !_debug;
		PRINTMANAGER->setDebug(_debug);
	}

	INVENTORYMANAGER->update();

	UIMANAGER->update();
	SCENEMANAGER->update();
	//CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
}


void playGround::render()
{
	if (STREAMMANAGER->getPosition("title") < STREAMMANAGER->getLenthEnd("title"))
		return;

	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================제발 이 사이에 좀 그립시다==========================

	//글자 배경색 모드
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	//투명 브러쉬
	HBRUSH myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);

	HPEN myPen = (HPEN)CreatePen(1, 2, RGB(255, 0, 0));
	SelectObject(getMemDC(), myPen);

	//_player->render();
	SCENEMANAGER->render();
	UIMANAGER->render(getMemDC());

	if (INVENTORYMANAGER->isOpen()) INVENTORYMANAGER->render(getMemDC());



	SelectObject(getMemDC(), oldBrush);
	DeleteObject(myPen);
	DeleteObject(myBrush);

	//==================================================s
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC());
}