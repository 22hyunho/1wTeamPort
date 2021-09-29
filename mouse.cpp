#include "stdafx.h"
#include "mouse.h"

HRESULT mouse::init(POINT position)
{
	mouse[0] = IMAGEMANAGER->addFrameImage("mouseMX", "img/enemy/mouse move mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));
	mouse[1] = IMAGEMANAGER->addFrameImage("mouseIMX", "img/enemy/mouse idle mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));



	_x = position.x;
	_y = position.y;

	mouseI = mouse[0];
	mouseI->setX(_x);
	mouseI->setY(_y);
	_state = MOUSE_IDLE;
	

	_next = RND->getFromIntTo(7, 10);
	_findway = RND->getInt(4);
	_direction = RND->getInt(4);
	_indexY = _direction;
	_indexH = _findway;
	_maxHP = _currentHP = 30;
	_z = 1;
	_idle = _next + 2;
	_way = true;

	_rc = RectMake(_x, _y, mouseI->getFrameWidth(), mouseI->getFrameHeight());

	_indexX = 0;
	_indexH = 0;
	return S_OK;
}

void mouse::release()
{
}

void mouse::update()
{
	if (!_way)
	{
		if (_direction == 0)
		{
			_direction = 1;
			_next += 2;
			_way = true;
		}
		else if (_direction == 1)
		{
			_direction = 0;
			_next += 2;
			_way = true;
		}
		else if (_direction == 2)
		{
			_direction = 3;
			_next += 2;
			_way = true;
		}
		else if (_direction == 3)
		{
			_direction = 2;
			_next += 2;
			_way = true;
		}
	}

	if (_findway == 0 && (_next <= 0 || _next < _idle))_state = MOUSE_IDLE;
	if (_findway == 1 && (_next <= 0 || _next < _idle))_state = MOUSE_IDLE;
	if (_findway == 2 && (_next <= 0 || _next < _idle))_state = MOUSE_IDLE;
	if (_findway == 3 && (_next <= 0 || _next < _idle))_state = MOUSE_IDLE;
	if (_direction == 0 && _next > 0 && _next >= _idle)_state = MOUSE_MOVE;
	if (_direction == 1 && _next > 0 && _next >= _idle)_state = MOUSE_MOVE;
	if (_direction == 2 && _next > 0 && _next >= _idle)_state = MOUSE_MOVE;
	if (_direction == 3 && _next > 0 && _next >= _idle)_state = MOUSE_MOVE;
	_indexY = _direction;


	_count++;
	_movecount++;
	if (_count >= 10)
	{
		if (_state == MOUSE_MOVE)
		{
			mouse[0]->setFrameY(_indexY);
			mouse[0]->setFrameX(_indexX);
			_count = 0;
			_indexX++;
			if (_indexX > mouse[0]->getMaxFrameX())_indexX = 0;
		}
		if (_state == MOUSE_IDLE)
		{
			mouse[1]->setFrameY(_indexY);
			mouse[1]->setFrameX(_indexH);
			_idle--;
			_count = 0;
			_indexH++;
			if (_indexH > mouse[0]->getMaxFrameX())_indexH = 0;
		}
	}
	if (_movecount > 20 && _next > 0 && _next >= _idle)
	{
		_movecount = 0;
		if (_direction == 0)_y += 16;
		if (_direction == 1)_y -= 16;
		if (_direction == 2)_x -= 16;
		if (_direction == 3)_x += 16;
		_next--;
		_idle--;
	}
	if (_idle < -5)
	{
		_next = RND->getFromIntTo(3, 7);
		_direction = _findway;
		_findway = RND->getInt(4);
		_idle = _next + 2;
	}
	_rc = RectMake(_x, _y, mouseI->getFrameWidth(), mouseI->getFrameHeight());
}

void mouse::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);
	}
	draw();
}

void mouse::draw()
{
	if (_state == MOUSE_MOVE)
	{
		mouse[0]->frameRender(getMemDC(), _x, _y, _indexX, _indexY);
	}
	if (_state == MOUSE_IDLE)
	{
		mouse[1]->frameRender(getMemDC(), _x, _y, _indexH, _indexY);
	}
}

void mouse::hitDamage(float damage)
{
	_currentHP -= damage;
}