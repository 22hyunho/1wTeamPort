#include "stdafx.h"
#include "Stun.h"
#include "Player.h"

HRESULT Stun::init(Player * player)
{
	_img = IMAGEMANAGER->addFrameImage("stun", "img/link/hit.bmp", 64, 384, 1, 4, true, RGB(255, 0, 255), true);

	_direct = _player->getDirect();
	_count = 0;
	_alphaValue = 255;

	_img->setFrameX(0);
	switch (_direct)
	{
	case DOWN:
		_img->setFrameY(1);
		break;

	case UP:
		_img->setFrameY(0);
		break;

	case RIGHT:
		_img->setFrameY(3);
		break;

	case LEFT:
		_img->setFrameY(2);
		break;
	}
	return S_OK;
}

void Stun::release()
{
}

void Stun::update()
{
	updateRect();
	controlAlpha();
}

void Stun::render(HDC hdc)
{
	_img->frameAlphaRender(hdc, _player->getBody().left, _player->getBody().top - 28, _alphaValue);
}

void Stun::updateDirect(int direct)
{
}

void Stun::updateRect()
{
	if (_player->getInvincible())	_count++;

	if (_count < 20)
	{
		switch (_direct)
		{
		case DOWN:
			_player->move(DOWN, 5.f);
			break;

		case UP:
			_player->move(UP, 5.f);
			break;

		case RIGHT:
			_player->move(RIGHT, 5.f);
			break;

		case LEFT:
			_player->move(LEFT, 5.f);
			break;
		}
	}
	else STATEMANAGER->changeState(IDLE);
}

void Stun::controlKey()
{
}

void Stun::controlFrame()
{
}

void Stun::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}
