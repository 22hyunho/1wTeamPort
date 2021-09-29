#include "stdafx.h"
#include "mushroom.h"

HRESULT mushroom::init(float x, float y, float z)
{
	_img = IMAGEMANAGER->addImage("mushroom", "img/equip/mushroom.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_invX = 129 + 96 * 4;
	_invY = 125;
	_itemRC = RectMakeCenter(_x, _y, 64, 64);
	_type = MUSHROOM;
	return S_OK;
}

void mushroom::release()
{
}

void mushroom::update()
{
}

void mushroom::render(HDC hdc, float x, float y)
{
	//_useImg->render(hdc, x, y);
}

void mushroom::useItem(float x, float y, float angle)
{
}

void mushroom::itemMove(float x, float y, float angle)
{
}

void mushroom::controlFrame()
{
}
