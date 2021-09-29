#include "stdafx.h"
#include "magic.h"

HRESULT fireball::init( int bulletMax, float range)
{	
	_fireMax = bulletMax;
	_range = range;
	return S_OK;
}

void fireball::release()
{
}

void fireball::update()
{
	move();
}

void fireball::render()
{
	for (_viFire= _vFire.begin(); _viFire!= _vFire.end(); ++_viFire)
	{
		_viFire->_fireImage->frameRender(getMemDC(),
			_viFire->_rc.left,
			_viFire->_rc.top,
			_viFire->_fireImage->getFrameX(), _indexY);

		_viFire->_count++;

		if (_viFire->_count >= 20)
		{
			_viFire->_fireImage->setFrameX(_viFire->_fireImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viFire->_fireImage->getFrameX() >= _viFire->_fireImage->getMaxFrameX())
			{
				_viFire->_fireImage->setFrameX(0);
			}

			_viFire->_count = 0;
		}
		if (PRINTMANAGER->isDebug())
			Rectangle(getMemDC(), _viFire->_rc);
	}
	
}

void fireball::fire(float x, float y, float angle, float speed)
{
	if (_fireMax < _vFire.size()) return;

	tagFire fireball;
	ZeroMemory(&fireball, sizeof(tagFire));
	fireball._fireImage = IMAGEMANAGER->addFrameImage("fireball", "img/effect/fireball mix.bmp", 336, 448, 6, 8, true, PINK);
	fireball._speed = speed;
	fireball._radius = fireball._fireImage->getWidth() / 2;
	fireball._x = fireball._fireX = x;
	fireball._y = fireball._fireY = y;
	fireball._dmg = 15.0f;
	fireball._angle = angle;

	fireball._rc = RectMakeCenter(fireball._x, fireball._y,
		50,50);

	_vFire.push_back(fireball);
}

void fireball::move()
{
	for (_viFire = _vFire.begin(); _viFire != _vFire.end();)
	{
		_viFire->_x += cosf(_viFire->_angle) * _viFire->_speed;
		_viFire->_y += -sinf(_viFire->_angle) * _viFire->_speed;


		_viFire->_rc = RectMakeCenter(_viFire->_x, _viFire->_y,
			50,
			50);

		if (_range < getDistance(_viFire->_x, _viFire->_y, _viFire->_fireX, _viFire->_fireY))
		{
			_viFire = _vFire.erase(_viFire);
		}
		else ++_viFire;
	}
}

void fireball::removeBullet(int arrNum)
{
	_vFire.erase(_vFire.begin() + arrNum);
}

HRESULT circulator::init(int bulletMax,int spreadMax, float range)
{
	_fireMax = bulletMax;
	_spreadMax = spreadMax;
	_range = range;
	return S_OK;
}

void circulator::release()
{
}

void circulator::update()
{
	move();
}

void circulator::render()
{
	for (_viCircul = _vCircul.begin(); _viCircul != _vCircul.end(); ++_viCircul)
	{
		_viCircul->_circulImage->frameRender(getMemDC(),
			_viCircul->_rc.left,
			_viCircul->_rc.top,
			_index, 0);

		_viCircul->_count++;

		if (_viCircul->_count >= 20)
		{
			_viCircul->_circulImage->setFrameX(_index);

			//최대 프레임보다 커지면
			_index++;
			if (_index > _viCircul->_circulImage->getMaxFrameX())
			{
				_index = 0;
			}

			_viCircul->_count = 0;
		}
		if (PRINTMANAGER->isDebug())
			Rectangle(getMemDC(), _viCircul->_rc);
	}
	for (_viSpread = _vSpread.begin(); _viSpread != _vSpread.end(); ++_viSpread)
	{
		_viSpread->_spreadImage->frameRender(getMemDC(),
			_viSpread->_rc.left,
			_viSpread->_rc.top,
			_indexs, _viSpread->indexY);

		_viSpread->_count++;

		if (_viSpread->_count >= 20)
		{
			_viSpread->_spreadImage->setFrameX(_indexs);

			//최대 프레임보다 커지면
			_indexs++;
			if (_indexs > _viSpread->_spreadImage->getMaxFrameX())
			{
				_indexs = 0;
			}

			_viSpread->_count = 0;
		}
		if (PRINTMANAGER->isDebug())
			Rectangle(getMemDC(), _viSpread->_rc);
	}
}

void circulator::fire(float x, float y, float angle, float speed)
{
	if (_fireMax < _vCircul.size()) return;

	tagCircul circulator;
	ZeroMemory(&circulator, sizeof(tagCircul));
	circulator._circulImage = IMAGEMANAGER->addFrameImage("circulator", "img/effect/circulator.bmp", 104, 51, 2, 1, true, PINK);
	circulator._speed = speed;
	circulator._radius = circulator._circulImage->getWidth() / 2;
	circulator._x = circulator._fireX = x;
	circulator._y = circulator._fireY = y;
	circulator._dmg = 15.0f;
	circulator._angle = angle;

	circulator._rc = RectMakeCenter(circulator._x, circulator._y,
		52, 51);

	_vCircul.push_back(circulator);

}

void circulator::spreadfire(float x, float y, float angle, float speed,int indexY)
{
	if (_spreadMax < _vSpread.size()) return;

	tagSpread _spread;
	ZeroMemory(&_spread, sizeof(tagSpread));
	_spread._spreadImage = IMAGEMANAGER->addFrameImage("spread", "img/effect/spread all.bmp", 90, 240, 3, 8, true, PINK);
	_spread._speed = speed;
	_spread._radius = _spread._spreadImage->getWidth() / 2;
	_spread._x = _spread._fireX = x;
	_spread._y = _spread._fireY = y;
	_spread._dmg = 15.0f;
	_spread._angle = angle;
	_spread.indexY = indexY;

	_spread._rc = RectMakeCenter(_spread._x, _spread._y,
		20, 20);

	_vSpread.push_back(_spread);
}

void circulator::move()
{
	for (_viCircul = _vCircul.begin(); _viCircul != _vCircul.end();)
	{
		innerX = (_viCircul->_rc.right + _viCircul->_rc.left) / 2;
		innerY = (_viCircul->_rc.top + _viCircul->_rc.bottom) / 2;
		_viCircul->_x += cosf(_viCircul->_angle) * _viCircul->_speed;
		_viCircul->_y += -sinf(_viCircul->_angle) * _viCircul->_speed;


		_viCircul->_rc = RectMakeCenter(_viCircul->_x, _viCircul->_y,
			52,51);

		if (_range < getDistance(_viCircul->_x, _viCircul->_y, _viCircul->_fireX, _viCircul->_fireY))
		{
			spreadfire(innerX, innerY, PI*3/2, 4.0f, 0);
			spreadfire(innerX, innerY, PI/2, 4.0f, 1);
			spreadfire(innerX, innerY, PI, 4.0f,2);
			spreadfire(innerX, innerY, 0, 4.0f, 3);
			spreadfire(innerX, innerY, PI*5/4, 4.0f, 4);
			spreadfire(innerX, innerY, PI*7/4, 4.0f, 5);
			spreadfire(innerX, innerY, PI*3/4, 4.0f, 6);
			spreadfire(innerX, innerY, PI/4, 4.0f, 7);
			_viCircul = _vCircul.erase(_viCircul);
		}
		else ++_viCircul;
	}
	for (_viSpread = _vSpread.begin(); _viSpread != _vSpread.end();)
	{
		_viSpread->_x += cosf(_viSpread->_angle) * _viSpread->_speed;
		_viSpread->_y += -sinf(_viSpread->_angle) * _viSpread->_speed;


		_viSpread->_rc = RectMakeCenter(_viSpread->_x, _viSpread->_y,
			20, 20);

		if (_range < getDistance(_viSpread->_x, _viSpread->_y, _viSpread->_fireX, _viSpread->_fireY))
		{
			_viSpread = _vSpread.erase(_viSpread);
		}
		else ++_viSpread;
	}
}

void circulator::removeBullet(int arrNum)
{
	_vCircul.erase(_vCircul.begin() + arrNum);
}

void circulator::removeSpread(int arrNum)
{
	_vSpread.erase(_vSpread.begin() + arrNum);
}
