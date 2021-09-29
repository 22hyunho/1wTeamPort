#include "stdafx.h"
#include "Slash.h"
#include "Player.h"

HRESULT Slash::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("slash_front", "img/link/attack.bmp", 1160, 584, 8, 4, true, RGB(255, 0, 255), true);

	_direct = _player->getDirect();

	_img->setFrameX(0);

	if (_direct == DOWN)
	{
		EFFECTMANAGER->setSlash(_player->getX(), _player->getY() + 64);
		_img->setFrameY(0);
	}
	else if (_direct == UP)
	{
		EFFECTMANAGER->setSlash(_player->getX(), _player->getY() - 64);
		_img->setFrameY(1);
	}
	else if (_direct == RIGHT)
	{
		EFFECTMANAGER->setSlash(_player->getX() + 64, _player->getY());
		_img->setFrameY(2);
	}
	else
	{
		EFFECTMANAGER->setSlash(_player->getX() - 64, _player->getY());
		_img->setFrameY(3);
	}

	return S_OK;
}

void Slash::release()
{
}

void Slash::update()
{
	controlKey();
	controlFrame();
	if (_player->getInvincible())	controlAlpha();
	else							_alphaValue = 255;
}

void Slash::render(HDC hdc)
{
	if (PRINTMANAGER->isDebug()) {
		HBRUSH brush = CreateSolidBrush(RGB(50, 50, 50));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN OldPen = (HPEN)SelectObject(hdc, pen);
		EFFECTMANAGER->getSlash()->render(hdc);
		SelectObject(hdc, OldPen);
		DeleteObject(pen);
		SelectObject(hdc, OldBrush);
		DeleteObject(brush);
	}

	if (_direct == DOWN)		_img->frameAlphaRender(hdc, _player->getBody().left - 28, _player->getBody().top - 24, _alphaValue);
	else if (_direct == UP)		_img->frameAlphaRender(hdc, _player->getBody().left - 52, _player->getBody().top - 67, _alphaValue);
	else if (_direct == RIGHT)	_img->frameAlphaRender(hdc, _player->getBody().left, _player->getBody().top - 39, _alphaValue);
	else						_img->frameAlphaRender(hdc, _player->getBody().left - 75, _player->getBody().top - 39, _alphaValue);
}

void Slash::updateDirect(int direct)
{
}

void Slash::updateRect()
{
}

void Slash::controlKey()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_SLASH))
	{
		this->init(_player);
	}
}

void Slash::controlFrame()
{
	_count++;
	if (_count % 2 == 0) {
		if (_img->getFrameX() >= _img->getMaxFrameX()) {

			if (KEYMANAGER->isStayKeyDown(KEY_SLASH))
			{
				STATEMANAGER->changeState(CHARGING);
			}
			else STATEMANAGER->changeState(IDLE);
			_count = 0;
		}
		else _img->setFrameX(_img->getFrameX() + 1);
	}
}

void Slash::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}
