#include "stdafx.h"
#include "Push.h"
#include "Player.h"

HRESULT Push::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("push", "img/link/push.bmp", 320, 384, 5, 4, true, RGB(255, 0, 255));

	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);
	return S_OK;
}

void Push::release()
{
}

void Push::update()
{
	controlKey();
	controlFrame();
}

void Push::render(HDC hdc)
{
	_img->frameRender(hdc, _player->getBody().left, _player->getBody().top - 30);
}

void Push::updateDirect(int direct)
{
}

void Push::updateRect()
{
}

void Push::controlKey()
{
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		STATEMANAGER->changeState(IDLE);
	}
}

void Push::controlFrame()
{
	_count++;

	if (_count >= 10)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_img->setFrameX(0);
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
