#include "stdafx.h"
#include "boomerang.h"

HRESULT boomerang::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("boomerang", "img/equip/boomerang.bmp", 64, 64, true, RGB(255, 0, 255));
	_invX = 129 + 95 * 2;
	_invY = 125;
	_type = BOOMERANG;
	return S_OK;
}

void boomerang::release()
{

}

void boomerang::update()
{
}

void boomerang::render(HDC hdc, float x, float y)
{
	if (PRINTMANAGER->isDebug()) {
		Rectangle(hdc, _itemRC);
	}
	if (_isFire) _useImg->frameRender(hdc, _itemRC.left, _itemRC.top);
}

void boomerang::useItem(float x, float y, float angle)
{
	if (!_isFire)
	{
		_useImg = IMAGEMANAGER->addFrameImage("flyingBoomerang", "img/effect/boomerang_effect.bmp", 160, 40, 4, 1, true, RGB(255, 0, 255));
		_x = _fireX = x;
		_y = _fireY = y;
		_speed = 7.f;
		_itemRC = RectMakeCenter(_x, _y, 40, 40);
		_angle = angle;
		_isFire = true;
		_isReturn = false;
	}
}

void boomerang::itemMove(float x, float y, float angle)
{
	if (_isFire)
	{
		if (getDistance(_fireX, _fireY, _x, _y) >= 320) _isReturn = true;
		if (_isReturn && getDistance(x, y, _x, _y) <= 10)
		{
			_isFire = false;
			_isReturn = false;
		}

		if (!_isReturn)
		{
			_x += cosf(_angle) * _speed;
			_y += -sinf(_angle) * _speed;
		}
		else
		{
			_x += cosf(getAngle(_x, _y, x, y)) * _speed;
			_y += -sinf(getAngle(_x, _y, x, y)) * _speed;
		}
		_itemRC = RectMakeCenter(_x, _y, 40, 40);
	}

	else _itemRC = RectMakeCenter(_x, _y, 0, 0);
}

void boomerang::controlFrame()
{
	if (_isFire)
	{
		_count++;

		if (_count >= 6)
		{
			if (_useImg->getFrameX() >= _useImg->getMaxFrameX())
				_useImg->setFrameX(0);
			else
				_useImg->setFrameX(_useImg->getFrameX() + 1);

			_count = 0;
		}
	}
	else _count = 0;
}
