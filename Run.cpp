#include "stdafx.h"
#include "Run.h"
#include "Player.h"

HRESULT Run::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("run", "img/link/run.bmp", 576, 384, 8, 4, true, RGB(255, 0, 255), true);

	_count = 0;
	_direct = _player->getDirect();
	_alphaValue = 255;

	_img->setFrameY(_direct);

	_img->setFrameX(0);
	return S_OK;
}

void Run::release()
{
}

void Run::update()
{
	controlKey();
	if (_player->getInvincible())	controlAlpha();
	else							_alphaValue = 255;
}

void Run::render(HDC hdc)
{
	controlFrame();
	_player->setRect(_player->getX(), _player->getY(), 64, 64);
	_img->frameAlphaRender(hdc, _player->getBody().left - 3, _player->getBody().top - 33, _alphaValue);
}

void Run::updateDirect(int direct)
{
}

void Run::updateRect()
{
}

void Run::controlKey()
{
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))
	{
		updateDirect(RIGHT);
		_player->move(RIGHT);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_LEFT))
	{
		updateDirect(LEFT);
		_player->move(LEFT);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP))
	{
		updateDirect(UP);
		_player->move(UP);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_DOWN))
	{
		updateDirect(DOWN);
		_player->move(DOWN);
	}


	if (KEYMANAGER->isOnceKeyUp(KEY_RIGHT)) 	STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_LEFT))		STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_UP))		STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_DOWN))		STATEMANAGER->changeState(IDLE);


	if (KEYMANAGER->isOnceKeyDown(KEY_SLASH))
	{
		STATEMANAGER->changeState(SLASH);
	}
}

void Run::controlFrame()
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

void Run::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}