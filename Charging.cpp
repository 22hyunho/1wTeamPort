#include "stdafx.h"
#include "Charging.h"
#include "Player.h"

HRESULT Charging::init(Player * player)
{
	_img = IMAGEMANAGER->addFrameImage("charging", "img/link/charging.bmp", 576, 480, 6, 4, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("complete", "img/link/completeCharge.bmp", 576, 480, 6, 4, true, RGB(255, 0, 255), true);
	_star = IMAGEMANAGER->addFrameImage("effect", "img/link/chargeEffect.bmp", 396, 88, 9, 2, true, RGB(255, 0, 255));

	_isComplete = false;
	_isMove = false;

	_direct = _player->getDirect();

	_img->setFrameX(0);
	_star->setFrameX(0);
	if (_direct == DOWN)
	{
		_img->setFrameY(0);
		_star->setFrameY(0);
	}
	else if (_direct == UP)
	{
		_img->setFrameY(1);
		_star->setFrameY(0);
	}
	else if (_direct == RIGHT)
	{
		_img->setFrameY(2);
		_star->setFrameY(1);
	}
	else
	{
		_img->setFrameY(3);
		_star->setFrameY(1);
	}


	return S_OK;
}

void Charging::release()
{
}

void Charging::update()
{
	charge();

	controlKey();
	controlFrame();
	if (_player->getInvincible())	controlAlpha();
	else							_alphaValue = 255;

	effectFrame();
}

void Charging::render(HDC hdc)
{
	if (_direct == DOWN)
	{
		_img->frameAlphaRender(hdc, _player->getBody().left - 22, _player->getBody().top - 25, _alphaValue);
		_star->frameRender(hdc, (_player->getBody().left + _player->getBody().right) / 2 - 15, _player->getBody().bottom);
	}
	else if (_direct == UP)
	{
		_img->frameAlphaRender(hdc, _player->getBody().left - 10, _player->getBody().top - 57, _alphaValue);
		_star->frameRender(hdc, (_player->getBody().left + _player->getBody().right) / 2 - 25, _player->getBody().top - 60);
	}
	else if (_direct == RIGHT)
	{
		_img->frameAlphaRender(hdc, _player->getBody().left, _player->getBody().top - 43, _alphaValue);
		_star->frameRender(hdc, (_player->getBody().left + _player->getBody().right) / 2 + 35, _player->getBody().top + 10);
	}
	else
	{
		_img->frameAlphaRender(hdc, _player->getBody().left - 32, _player->getBody().top - 43, _alphaValue);
		_star->frameRender(hdc, (_player->getBody().left + _player->getBody().right) / 2 - 80, _player->getBody().top + 10);
	}

	if (PRINTMANAGER->isDebug())
	{
		char str[128];
		sprintf_s(str, "iCount : %d", _cCount);
		TextOut(hdc, _player->getX() + 50, _player->getBody().top - 50, str, strlen(str));
		sprintf_s(str, "direct : %d", _direct);
		TextOut(hdc, _player->getX() + 50, _player->getBody().top - 70, str, strlen(str));
		sprintf_s(str, "frameX : %d", _img->getFrameX());
		TextOut(hdc, _player->getX() + 50, _player->getBody().top - 90, str, strlen(str));
	}
}

void Charging::updateDirect(int direct)
{
}

void Charging::updateRect()
{
}

void Charging::controlKey()
{
	if (KEYMANAGER->isOnceKeyUp(KEY_SLASH))
	{
		_cCount = 0;
		if (!_isComplete)	STATEMANAGER->changeState(IDLE);
		else				STATEMANAGER->changeState(CHARGEATTACK);
		_isComplete = false;
	}

	if (KEYMANAGER->isStayKeyDown(KEY_DOWN))
	{
		_player->move(DOWN);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_DOWN))
	{
		_img->setFrameX(0);
		_isMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(KEY_UP))
	{
		_player->move(UP);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_UP))
	{
		_img->setFrameX(0);
		_isMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))
	{
		_player->move(RIGHT);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_RIGHT))
	{
		_img->setFrameX(0);
		_isMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(KEY_LEFT))
	{
		_player->move(LEFT);
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(KEY_LEFT))
	{
		_img->setFrameX(0);
		_isMove = false;
	}
}

void Charging::controlFrame()
{
	if (_isMove) {
		_count++;
		if (_count >= 5)
		{
			if (_img->getFrameX() >= _img->getMaxFrameX())
				_img->setFrameX(0);
			else
				_img->setFrameX(_img->getFrameX() + 1);

			_count = 0;
		}
	}
}

void Charging::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}

void Charging::effectFrame()
{
	_eCount++;
	if (_eCount % 5 == 0)
	{
		if (_star->getFrameX() >= _star->getMaxFrameX())
			_star->setFrameX(0);
		else
			_star->setFrameX(_star->getFrameX() + 1);

		_eCount = 0;
	}
}

void Charging::charge()
{
	if (_cCount < 80)
	{
		_cCount++;
		if (_cCount >= 80)
		{
			_isComplete = true;
			_img->setFrameX(0);
		}
	}

	if (_isComplete)
	{
		_img = IMAGEMANAGER->findImage("complete");
		_img->setFrameY(_direct);
	}
}