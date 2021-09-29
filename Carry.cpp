#include "stdafx.h"
#include "Carry.h"
#include "Player.h"

HRESULT Carry::init(Player * player)
{
	State::init(player);
	_img = IMAGEMANAGER->addFrameImage("lift", "img/link/lift.bmp", 408, 368, 3, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("carry", "img/link/carry.bmp", 408, 368, 6, 4, true, RGB(255, 0, 255));

	_isCarry = false;
	_isMove = false;

	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);

	_object = IMAGEMANAGER->findImage(_player->getObject()->b);

	return S_OK;
}

void Carry::release()
{
	_player->setObject(nullptr);
}

void Carry::update()
{
	controlKey();
	controlFrame();
}

void Carry::render(HDC hdc)
{
	if (_img == IMAGEMANAGER->findImage("lift"))
	{
		if (_direct == DOWN)		_img->frameRender(hdc, _player->getBody().left - 36, _player->getBody().top - 27);
		else if (_direct == UP)		_img->frameRender(hdc, _player->getBody().left - 36, _player->getBody().top - 27);
		else if (_direct == RIGHT)	_img->frameRender(hdc, _player->getBody().left - 43, _player->getBody().top - 29);
		else						_img->frameRender(hdc, _player->getBody().left - 30, _player->getBody().top - 29);
	}
	else
	{
		if (_direct == DOWN)		_img->frameRender(hdc, _player->getBody().left - 2, _player->getBody().top - 27);
		else if (_direct == UP)		_img->frameRender(hdc, _player->getBody().left - 2, _player->getBody().top - 27);
		else if (_direct == RIGHT)	_img->frameRender(hdc, _player->getBody().left - 3, _player->getBody().top - 29);
		else						_img->frameRender(hdc, _player->getBody().left - 2, _player->getBody().top - 29);
	}

	if (_object && _isCarry) {
		_object->render(hdc, _player->getBody().left, _player->getBody().top - _object->getHeight());

		PTILE tile = _player->getObject();
		(*tile) = *TILEMANAGER->makeTile(tile->x * TILEX, tile->y *TILEY, NOTHING);
	}
}

void Carry::updateDirect(int direct)
{
	_img->setFrameY(direct);
}

void Carry::updateRect()
{
}

void Carry::controlKey()
{
	if (KEYMANAGER->isStayKeyDown(KEY_DOWN) && _isCarry) // isCarry 불값을 줘서 들어올리는 모션일때는 못움직이게 설정
	{
		_player->move(DOWN);
		updateDirect(DOWN);			//들고있는 상태에서 방향을 바꾸면 그 방향을 바라보도록 y프레임 설정
		_player->setDirect(DOWN);	//들고나서 방향을 바꾸면 그 방향으로 던질 수 있도록 플레이어 direct 설정
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_DOWN) && _isCarry)
	{
		_img->setFrameX(0);
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP) && _isCarry)
	{
		_player->move(UP);
		updateDirect(UP);
		_player->setDirect(UP);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_UP) && _isCarry)
	{
		_img->setFrameX(0);
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT) && _isCarry)
	{
		_player->move(RIGHT);
		updateDirect(RIGHT);
		_player->setDirect(RIGHT);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_RIGHT) && _isCarry)
	{
		_img->setFrameX(0);
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_LEFT) && _isCarry)
	{
		_player->move(LEFT);
		updateDirect(LEFT);
		_player->setDirect(LEFT);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_LEFT) && _isCarry)
	{
		_img->setFrameX(0);
		_isMove = false;
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_CARRY) && _isCarry)
	{
		STATEMANAGER->changeState(THROW);
	}
}

void Carry::controlFrame()
{
	if (!_isCarry) // 이미지를 들고있는중과 들고난 후로 나누었기 때문에 bool값으로 관리해줌
	{
		_count++;
		if (_count % 15 == 0)
		{
			if (_img->getFrameX() >= _img->getMaxFrameX())
			{
				_isCarry = true;
				_img = IMAGEMANAGER->findImage("carry");

				_img->setFrameX(0);
				_img->setFrameY(_direct);
			}
			else
				_img->setFrameX(_img->getFrameX() + 1);

			_count = 0;
		}
	}
	else
	{
		if (_isMove)
		{
			_count++;
			if (_count >= 6)
			{
				if (_img->getFrameX() >= _img->getMaxFrameX())
					_img->setFrameX(0);
				else
					_img->setFrameX(_img->getFrameX() + 1);

				_count = 0;
			}
		}
	}
}
