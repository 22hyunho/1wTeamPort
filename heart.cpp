#include "stdafx.h"
#include "heart.h"

HRESULT heart::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("heart", "img/item/heart.bmp", 32, 32, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_itemRC = RectMakeCenter(_x, _y, 32, 32);
	_type = HEART;

	return S_OK;
}

void heart::release()
{
}

void heart::update()
{
}

void heart::render(HDC hdc, float x, float y)
{
	_img->render(hdc, x, y);
}

void heart::useItem(float x, float y, float angle)
{
}

void heart::itemMove(float x, float y, float angle)
{
}

void heart::controlFrame()
{
}
