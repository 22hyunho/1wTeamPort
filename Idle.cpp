#include "stdafx.h"
#include "Idle.h"
#include "Player.h"

HRESULT Idle::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("idle", "img/link/shield_idle.bmp", 76, 368, 1, 4, true, RGB(255, 0, 255), true);

	_count = 0;
	_direct = _player->getDirect();
	_alphaValue = 255;

	_img->setFrameY(_direct);

	_img->setFrameX(0);
	return S_OK;
}

void Idle::release()
{
}

void Idle::update()
{
	controlKey();
	if (_player->getInvincible())	controlAlpha();
	else							_alphaValue = 255;
}

void Idle::render(HDC hdc)
{
	_img->frameAlphaRender(hdc, _player->getBody().left - 8, _player->getBody().top - 28, _alphaValue);
}

void Idle::updateDirect(int direct)
{
}

void Idle::updateRect()
{

}

void Idle::controlKey()
{
	/**** 이동 ***/
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))
	{
		_player->setDirect(RIGHT);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_LEFT))
	{
		_player->setDirect(LEFT);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP))
	{
		_player->setDirect(UP);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_DOWN))
	{
		_player->setDirect(DOWN);
		STATEMANAGER->changeState(RUN);
	}

	//인벤토리 오픈
	if (KEYMANAGER->isOnceKeyDown(KEY_INVEN))
	{
		INVENTORYMANAGER->open();
		STATEMANAGER->changeState(INVENOPEN);
	}

	//공격
	if (KEYMANAGER->isOnceKeyDown(KEY_SLASH))
	{
		STATEMANAGER->changeState(SLASH);
	}

	//물건잡기, 상자열기
	if (KEYMANAGER->isOnceKeyDown(KEY_CARRY))
	{
		COLLISIONMANAGER->interactPlayer();
		if (_player->getObject())
			STATEMANAGER->changeState(CARRY);
	}

	//밀기 테스트
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		STATEMANAGER->changeState(PUSH);
	}

	//장착 아이템 사용
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		int x = 0;
		int y = 0;
		switch (_direct) {
		case UP:
			y = -64;
			break;
		case DOWN:
			y = 64;
			break;
		case LEFT:
			x = -64;
			break;
		case RIGHT:
			x = 64;
			break;
		}

		if (INVENTORYMANAGER->getEquipItem()->getType() == BOOMERANG && !INVENTORYMANAGER->getEquipItem()->getFire())
			STATEMANAGER->changeState(USEITEM);
		if (INVENTORYMANAGER->getEquipItem()->getType() == CANDELA)
		{
			INVENTORYMANAGER->getEquipItem()->useItem(_player->getX() + x, _player->getY() + y, 0);
			_player->changeMP(8.f);
		}
	}
}

void Idle::controlFrame()
{
}

void Idle::controlAlpha()
{
	_alphaCount++;
	if (_alphaCount % 5 == 0)
	{
		_alphaValue = _alphaValue == 0 ? 170 : 0;
		_alphaCount = 0;
	}
}
