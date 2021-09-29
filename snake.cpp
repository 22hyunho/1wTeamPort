#include "stdafx.h"
#include "snake.h"

HRESULT snake::init(POINT position)
{
	snake[0] = IMAGEMANAGER->addFrameImage("snakeMX", "img/enemy/snake move mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));
	//snake[1] = IMAGEMANAGER->findImage("scoutSMX");

	_x = position.x;
	_y = position.y;

	snakeI = snake[0];
	snakeI->setX(_x);
	snakeI->setY(_y);
	_state = SNAKE_MOVE;
	

	_next = RND->getFromIntTo(2, 5);
	_findway = RND->getInt(4);
	_direction = RND->getInt(4);
	_indexY = _direction;
	_maxHP = _currentHP = 30;
	_z = 1;
	_way = true;

	_rc = RectMake(snakeI->getX(), snakeI->getY(), snakeI->getFrameWidth(), snakeI->getFrameHeight());

	_indexX = 0;
	return S_OK;
}

void snake::release()
{
}

void snake::update()
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
	_indexY = _direction;

	_count++;
	_movecount++;
	if (_movecount >= 20 && _next > 0)
	{

		
		_movecount = 0;
		if (_direction == 0)_y += 16;
		if (_direction == 1)_y -= 16;
		if (_direction == 2)_x -= 16;
		if (_direction == 3)_x += 16;
		_next--;
	}
	if (_count >= 4)
	{
		if (_state == SNAKE_MOVE)
		{
			snake[0]->setFrameY(_indexY);
			snake[0]->setFrameX(_indexX);
			_count = 0;
			_indexX++;
			if (_indexX > snake[0]->getMaxFrameX())_indexX = 0;
		}

	}


	if (_next == 0)
	{
		_next = RND->getFromIntTo(3, 7);
		_findway = RND->getInt(4);
		_direction = _findway;
	}
	
	_rc = RectMake(_x, _y, snakeI->getFrameWidth(), snakeI->getFrameHeight());
}

void snake::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);
	}
	draw();

}

void snake::draw()
{
	if (_state == SNAKE_MOVE)
	{
		snake[0]->frameRender(getMemDC(), _x, _y, _indexX, _indexY);
	}
	//if (_state == BOTTOM_SHIFT || _state == TOP_SHIFT || _state == LEFT_SHIFT || _state == RIGHT_SHIFT)
	//{
	//	scout[1]->frameRender(getMemDC(), scoutI->getX(), scoutI->getY(), indexH, indexY);
	//}
}

void snake::hitDamage(float damage)
{
	_currentHP -= damage;
}