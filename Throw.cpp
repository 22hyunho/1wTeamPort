#include "stdafx.h"
#include "Throw.h"
#include "Player.h"

HRESULT Throw::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("throw", "img/link/throw.bmp", 128, 384, 2, 4, true, RGB(255, 0, 255));

	_count = 0;
	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);

	return S_OK;
}

void Throw::release()
{
}

void Throw::update()
{
	controlFrame();
}

void Throw::render(HDC hdc)
{
	_img->frameRender(hdc, _player->getBody().left, _player->getBody().top - 29);
}

void Throw::updateDirect(int direct)
{
}

void Throw::updateRect()
{
}

void Throw::controlKey()
{
}

void Throw::controlFrame()
{
	_count++;
	if (_count >= 5)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			STATEMANAGER->changeState(IDLE);
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
