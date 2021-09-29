#include "stdafx.h"
#include "UseItem.h"
#include "Player.h"

HRESULT UseItem::init(Player * player)
{
	_img = IMAGEMANAGER->addFrameImage("throwBoomerang", "img/link/throwBoomerang.bmp", 216, 368, 2, 4, true, RGB(255, 0, 255));

	_count = 0;
	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);


	switch (_direct) {
	case UP:
		angle = PI / 2;
		break;
	case DOWN:
		angle = 3 * PI / 2;
		break;
	case LEFT:
		angle = PI;
		break;
	case RIGHT:
		angle = 0;
		break;
	}


	return S_OK;
}

void UseItem::release()
{
}

void UseItem::update()
{
	controlFrame();
}

void UseItem::render(HDC hdc)
{
	if (_direct == UP || _direct == RIGHT)	_img->frameRender(hdc, _player->getBody().left - 30, _player->getBody().top - 29);
	else									_img->frameRender(hdc, _player->getBody().left - 10, _player->getBody().top - 29);
}

void UseItem::updateDirect(int direct)
{
}

void UseItem::updateRect()
{
}

void UseItem::controlFrame()
{
	_count++;
	if (_count >= 7)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			STATEMANAGER->changeState(IDLE);

		else
		{
			_img->setFrameX(_img->getFrameX() + 1);
			INVENTORYMANAGER->getEquipItem()->useItem(_player->getX(), _player->getY(), angle);
		}

		_count = 0;
	}
}
