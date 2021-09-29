#include "stdafx.h"
#include "scout.h"

HRESULT scout::init(POINT position)
{
	scout[0] = IMAGEMANAGER->addFrameImage("scoutMX", "img/enemy/scout move mix.bmp", 136, 380, 2, 4, true, RGB(255, 0, 255));
	scout[1] = IMAGEMANAGER->addFrameImage("scoutSMX", "img/enemy/scout shift mix.bmp", 272, 380, 4, 4, true, RGB(255, 0, 255));


	_x = position.x;
	_y = position.y;

	scoutI = scout[0];
	scoutI->setX(_x);
	scoutI->setY(_y);
	_state = SCOUT_MOVE;
	


	_next = RND->getFromIntTo(5, 8);
	_findway = RND->getInt(4);
	_direction = RND->getInt(4);
	_indexY = _direction;
	_indexH = _findway;
	_maxHP = _currentHP = 30;
	_z = 1;

	_rc = RectMakeCenter(_x, _y, 80, 112);

	_indexX = 0;
	return S_OK;
}

void scout::release()
{
}

void scout::update()
{
	if (_findway == 0 && _next <= 0)_state = SCOUT_SHIFT;
	if (_findway == 1 && _next <= 0)_state = SCOUT_SHIFT;
	if (_findway == 2 && _next <= 0)_state = SCOUT_SHIFT;
	if (_findway == 3 && _next <= 0)_state = SCOUT_SHIFT;
	if (_direction == 0 && _next > 0)_state = SCOUT_MOVE;
	if (_direction == 1 && _next > 0)_state = SCOUT_MOVE;
	if (_direction == 2 && _next > 0)_state = SCOUT_MOVE;
	if (_direction == 3 && _next > 0)_state = SCOUT_MOVE;
	_indexY = _direction;
	_indexH = _findway;

	_count++;
	_movecount++;
	if (_count >= 10)
	{
		if (_state == SCOUT_MOVE)
		{
			scout[0]->setFrameY(_indexY);
			scout[0]->setFrameX(_indexX);
			_count = 0;
			_indexX++;
			if (_indexX > scout[0]->getMaxFrameX())_indexX = 0;
		}
		if (_state == SCOUT_SHIFT)
		{
			scout[1]->setFrameY(_indexY);
			scout[1]->setFrameX(_indexH);
			_next--;
			_count = 0;
		}

	}

	if (_movecount >= 20 && _next > 0)
	{
		_movecount = 0;
		if (_direction == 0)_y += 16;
		if (_direction == 1)_y -= 16;
		if (_direction == 2)_x -= 16;
		if (_direction == 3)_x += 16;
		_next--;
	}

	if (_direction == 0 && _findway == 1)_findway = RND->getInt(4);
	if (_direction == 1 && _findway == 0)_findway = RND->getInt(4);
	if (_direction == 2 && _findway == 3)_findway = RND->getInt(4);
	if (_direction == 3 && _findway == 2)_findway = RND->getInt(4);
	if (_next < -5)
	{
		_next = RND->getFromIntTo(5, 8);
		_direction = _findway;
		_findway = RND->getInt(4);
	}
	
	_rc = RectMake(_x, _y, scoutI->getFrameWidth(), scoutI->getFrameHeight());
}

void scout::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);
	}
	draw();
}

void scout::draw()
{

	if (_state == SCOUT_MOVE)
	{
		scout[0]->frameRender(getMemDC(), _x, _y, _indexX, _indexY);
	}
	if (_state == SCOUT_SHIFT)
	{
		scout[1]->frameRender(getMemDC(), _x, _y, _indexH, _indexY);
	}
}

void scout::hitDamage(float damage)
{
	_currentHP -= damage;
}