#pragma once
#include "image.h"

#define RENDERCOUNT		0.05
#define RENDERCOUNT2	RENDERCOUNT * 2

#define PINK RGB(255, 0, 255)

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", 20000, 20000);

enum DIRECT {
	DOWN,
	UP,
	RIGHT,
	LEFT,
	ENDDIRECT
};

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT 마소 전용 반환형식인데
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//초기화 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 함수
	virtual void render();			//그리기 함수

	//백버퍼 접근자
	//void setBackBufferSize(float width, float height){ _backBuffer->setwidth}
	image* getBackBuffer() { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};