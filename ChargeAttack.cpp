#include "stdafx.h"
#include "ChargeAttack.h"
#include "Player.h"

HRESULT ChargeAttack::init(Player* player)
{
	_img = IMAGEMANAGER->addFrameImage("cAttack", "img/link/chargeAttack.bmp", 2160, 768, 12, 4, true, RGB(255, 0, 255), true);

	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);

	EFFECTMANAGER->setChargeAttack(_player->getX(), _player->getY());
	return S_OK;
}

void ChargeAttack::release()
{
}

void ChargeAttack::update()
{
	controlFrame();
	if (_player->getInvincible())	controlAlpha();
	else							_alphaValue = 255;
}

void ChargeAttack::render(HDC hdc)
{
	if (PRINTMANAGER->isDebug())
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN OldPen = (HPEN)SelectObject(hdc, pen);
		EFFECTMANAGER->getCgAttack()->render(hdc);
		SelectObject(hdc, OldPen);
		DeleteObject(pen);
		SelectObject(hdc, OldBrush);
		DeleteObject(brush);
	}
	if (_direct == DOWN)			_img->frameAlphaRender(hdc, _player->getBody().left - 57, _player->getBody().top - 92, _alphaValue);
	else if (_direct == UP)			_img->frameAlphaRender(hdc, _player->getBody().left - 56, _player->getBody().top - 55, _alphaValue);
	else if (_direct == RIGHT)		_img->frameAlphaRender(hdc, _player->getBody().left - 68, _player->getBody().top - 75, _alphaValue);
	else							_img->frameAlphaRender(hdc, _player->getBody().left - 47, _player->getBody().top - 73, _alphaValue);
}

void ChargeAttack::updateDirect(int direct)
{
}

void ChargeAttack::updateRect()
{
}

void ChargeAttack::controlKey()
{
}

void ChargeAttack::controlFrame()
{
	_count++;

	if (_count >= 3)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			STATEMANAGER->changeState(IDLE);
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}

void ChargeAttack::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}
