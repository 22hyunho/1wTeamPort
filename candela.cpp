#include "stdafx.h"
#include "candela.h"

HRESULT candela::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("candela", "img/equip/candela2.bmp", 64, 64, true, RGB(255, 0, 255));
	_invX = 129;
	_invY = 125 + 94 * 2;
	_type = CANDELA;

	return S_OK;
}

void candela::release()
{
}

void candela::update()
{
}

void candela::render(HDC hdc, float x, float y)
{
	if (_isFire) _useImg->frameRender(hdc, _itemRC.left, _itemRC.top);
}

void candela::useItem(float x, float y, float angle)
{
	if (!_isFire)
	{
		_useImg = IMAGEMANAGER->addFrameImage("flame", "img/effect/candela_effect.bmp", 132, 64, 3, 1, true, RGB(255, 0, 255));
		_x = x;
		_y = y;
		_itemRC = RectMakeCenter(_x, _y, 44, 64);
		_isFire = true;
	}
}

void candela::itemMove(float x, float y, float angle)
{
}

void candela::controlFrame()
{
	if (_isFire)
	{
		_count++;

		if (_count >= 10)
		{
			if (_useImg->getFrameX() >= _useImg->getMaxFrameX())
			{
				_useImg->setFrameX(0);
				_isFire = false;
			}
			else
				_useImg->setFrameX(_useImg->getFrameX() + 1);

			_count = 0;
		}
	}
	else _count = 0;
}
