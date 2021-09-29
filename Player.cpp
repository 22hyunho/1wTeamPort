#include "stdafx.h"
#include "Player.h"
#include "State.h"

HRESULT Player::init()
{
	//몸체
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_z = 1;
	_direct = 0;
	_body = RectMakeCenter(_x, _y, 64, 64);

	//스탯
	_hp = 96;
	_mp = 128;
	_speed = 5.f;
	_moneyCount = _bombCount = _arrowCount = 0;

	//상태
	_updown = false;
	_invincible = false;
	_iCount = 0;
	_destX = 0;
	_destY = 0;

	//이펙트
	STATEMANAGER->init(this);
	INVENTORYMANAGER->init();

	return S_OK;
}

void Player::release()
{
	STATEMANAGER->release();
	STATEMANAGER->releaseSingleton();
}

void Player::update()
{
	//테스트용 코드============================
	if (KEYMANAGER->isOnceKeyDown('1'))	changeMoney(-50);
	if (KEYMANAGER->isOnceKeyDown('2'))	changeMoney(50);

	if (KEYMANAGER->isOnceKeyDown('3'))	changeBomb(-5);
	if (KEYMANAGER->isOnceKeyDown('4'))	changeBomb(5);

	if (KEYMANAGER->isOnceKeyDown('5'))	changeArrow(-5);
	if (KEYMANAGER->isOnceKeyDown('6'))	changeArrow(5);

	//////////////////////////////////////////

	if (KEYMANAGER->isOnceKeyDown('7'))	changeHP(16);
	if (KEYMANAGER->isOnceKeyDown('8'))	changeHP(-16);
	if (KEYMANAGER->isOnceKeyDown('9'))	changeMP(4);  //CANDELA 32번 사용가능
	if (KEYMANAGER->isOnceKeyDown('0'))	changeMP(-4);
	//========================================
	if (_invincible) invincibleTime();

	if (_updown) {
		changeZ();
	}
	else {
		STATEMANAGER->update();
		_body = RectMakeCenter(_x, _y, 64, 64);
		COLLISIONMANAGER->collisionPlayer();
		_body = RectMakeCenter(_x, _y, 64, 64);
	}

	if (INVENTORYMANAGER->getEquipItem() != nullptr)
	{
		INVENTORYMANAGER->getEquipItem()->itemMove(_x, _y, _angle);
		INVENTORYMANAGER->getEquipItem()->controlFrame();
	}

}

void Player::render()
{
	if (PRINTMANAGER->isDebug()) {
		Rectangle(getMemDC(), _body);

		char str[128];
		sprintf_s(str, "x : %f", _x);
		TextOut(getMemDC(), _x - 50, _y - 120, str, strlen(str));
		sprintf_s(str, "y : %f", _y);
		TextOut(getMemDC(), _x - 50, _y - 100, str, strlen(str));
		sprintf_s(str, "z : %f", _z);
		TextOut(getMemDC(), _x - 50, _y - 80, str, strlen(str));
	}

	STATEMANAGER->render(getMemDC());

	if (INVENTORYMANAGER->getEquipItem() != nullptr)
	{
		INVENTORYMANAGER->getEquipItem()->render(getMemDC(), 50, 50);
	}
}

void Player::changeHP(float damage)
{
	_hp -= damage;

	if (_hp < 0) _hp = 0;
	if (_hp > 96) _hp = 96;

	UIMANAGER->setHP(_hp);
}

void Player::changeMP(float useSkill)
{
	_mp -= useSkill;

	if (_mp < 0) _mp = 0;
	if (_mp > 128) _mp = 128;

	UIMANAGER->setMP(_mp);
}

void Player::changeMoney(int num)
{
	_moneyCount += num;

	if (_moneyCount > 999) _moneyCount = 999;
	else if (_moneyCount < 0) _moneyCount = 0;

	UIMANAGER->setMoney(_moneyCount);
}

void Player::changeBomb(int num)
{
	_bombCount += num;

	if (_bombCount > 99) _bombCount = 99;
	else if (_bombCount < 0) _bombCount = 0;

	UIMANAGER->setBomb(_bombCount);
}

void Player::changeArrow(int num)
{
	_arrowCount += num;

	if (_arrowCount > 99) _arrowCount = 99;
	else if (_arrowCount < 0) _arrowCount = 0;

	UIMANAGER->setArrow(_arrowCount);
}

void Player::move(int direct)
{
	switch (direct)
	{
	case RIGHT:
		_x += _speed;
		break;
	case LEFT:
		_x -= _speed;
		break;
	case UP:
		_y -= _speed;
		break;
	case DOWN:
		_y += _speed;
		break;
	default:
		break;
	}
}

void Player::move(int direct, float speed)
{
	switch (direct)
	{
	case RIGHT:
		_x += speed;
		break;
	case LEFT:
		_x -= speed;
		break;
	case UP:
		_y -= speed;
		break;
	case DOWN:
		_y += speed;
		break;
	default:
		break;
	}
}

void Player::invincibleTime()
{
	_iCount++;
	if (_iCount > 60)
	{
		_invincible = false;
		_iCount = 0;
	}
}

void Player::changeZ()
{

	switch (_direct) {
	case UP:
		move(UP, 1);
		if (_y + 32 <= _destY) {
			_updown = false;
			_z = 4 - _z;
		}
		break;
	case DOWN:
		move(DOWN, 1);
		if (_y - 32 >= _destY) {
			_updown = false;
		}
		break;

	default:
		_updown = false;
		break;
	}
}
