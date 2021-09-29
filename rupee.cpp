#include "stdafx.h"
#include "rupee.h"

HRESULT rupee::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addFrameImage("rupee", "img/item/rupee.bmp", 128, 56, 4, 1, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_itemRC = RectMakeCenter(_x, _y, 32, 32);
	_type = RUPEE;

	_count = 0;
	_img->setFrameX(0);

	return S_OK;
}

void rupee::release()
{
}

void rupee::update()
{
}

void rupee::render(HDC hdc, float x, float y)
{
	RECT rc = CAMERAMANAGER->getScreen();
	_img->frameRender(hdc, rc.left + 300, rc.top + 500);
}

void rupee::useItem(float x, float y, float angle)
{
}

void rupee::itemMove(float x, float y, float angle)
{
}

void rupee::controlFrame()
{
	_count++;
	if (_count > 4)
	{
		if (_img->getFrameX() < _img->getMaxFrameX())
		{
			_img->setFrameX(_img->getFrameX() + 1);
		}
		else
		{
			_img->setFrameX(0);
			_count = 0;
		}
	}
}
