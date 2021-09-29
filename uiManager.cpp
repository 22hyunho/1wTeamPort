#include "stdafx.h"
#include "uiManager.h"
#include "Player.h"
#include "item.h"

HRESULT uiManager::init(Player* player)
{
	//ÀÌ¹ÌÁö
	_gauge = IMAGEMANAGER->addImage("gauge", "img/ui/gauge.bmp", 64, 168, true, PINK);
	_gaugeBack = IMAGEMANAGER->addImage("gauge_back", "img/ui/gauge_back.bmp", 32, 128, true, PINK);
	_xitem = IMAGEMANAGER->addImage("xitem", "img/ui/xitem.bmp", 88, 88, true, PINK);
	_money = IMAGEMANAGER->addImage("money", "img/ui/money.bmp", 32, 32, true, PINK);
	_bomb = IMAGEMANAGER->addImage("bomb", "img/ui/bomb.bmp", 32, 32, true, PINK);
	_arrow = IMAGEMANAGER->addImage("arrow", "img/ui/arrow.bmp", 56, 32, true, PINK);
	_lifeText = IMAGEMANAGER->addImage("life_text", "img/ui/life_text.bmp", 176, 28, true, PINK);

	_life = IMAGEMANAGER->addImage("life", "img/ui/life2.bmp", 96, 28, true, PINK);
	_halfLife = IMAGEMANAGER->addImage("lifeHalf", "img/ui/life_half2.bmp", 96, 28, true, PINK);
	_zeroLife = IMAGEMANAGER->addImage("lifeZero", "img/ui/life_zero2.bmp", 96, 28, true, PINK);

	char key[128], str[128];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(key, "number%d", i);
		sprintf_s(str, "img/ui/%d.bmp", i);
		_number[i] = IMAGEMANAGER->addImage(key, str, 28, 28, true, RGB(255, 0, 255));
	}
	
	//½ºÅÈ
	_hp = 96;
	_mp = 128;
	_moneyCount = _bombCount = _arrowCount = 0;

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
}

void uiManager::render(HDC hdc)
{
	RECT rc = CAMERAMANAGER->getScreen();

	_xitem->render(hdc, rc.left + 147, rc.top + 79);
	_rc = RectMake(rc.left + 159, rc.top + 91, 64, 64);
	INVENTORYMANAGER->getEquipItem()->getImage()->render(hdc, _rc.left, _rc.top);

	//===================================µð¹ö±ë===================================
	if (PRINTMANAGER->isDebug()) {
		Rectangle(hdc, _rc);
		int _type = INVENTORYMANAGER->getEquipItem()->getType();

		char hp[128];
		char mp[128];
		char type[128];
		sprintf_s(hp, "HP : %d", _hp);
		sprintf_s(mp, "MP : %d", _mp);
		sprintf_s(type, "TYPE : %d", _type);
		TextOut(hdc, rc.left + 20, rc.top + 20, hp, strlen(hp));
		TextOut(hdc, rc.left + 20, rc.top + 40, mp, strlen(mp));
		TextOut(hdc, rc.left + 20, rc.top + 60, type, strlen(type));
	}
	//============================================================================

	_gaugeBack->render(hdc, rc.left + 79 + 16, rc.top + 71 + 20 + (128 - _mp), 0, 0, 32, _mp);
	_gauge->render(hdc, rc.left + 79, rc.top + 71);

	_money->render(hdc, rc.left + 287, rc.top + 59);
	_bomb->render(hdc, rc.left + 399, rc.top + 59);
	_arrow->render(hdc, rc.left + 484, rc.top + 59);

	_lifeText->render(hdc, rc.left + 711, rc.top + 59);
	_zeroLife->render(hdc, rc.left + 643, rc.top + 95);

	//====================================HP======================================
	if (_hp >= 96)
	{
		_halfLife->render(hdc, rc.left + 643, rc.top + 95);
		_life->render(hdc, rc.left + 643, rc.top + 95);
	}
	if (!(_hp % 32 == 0))
	{
		_halfLife->render(hdc, rc.left + 643, rc.top + 95, 0, 0, _hp + 16, 28);
		_life->render(hdc, rc.left + 643, rc.top + 95, 0, 0, _hp - 16, 28);
	}
	if (_hp % 32 == 0)_life->render(hdc, rc.left + 643, rc.top + 95, 0, 0, _hp, 28);
	//============================================================================

	//money
	_number[_moneyCount / 100]->render(hdc, rc.left + 260, rc.top + 95);
	_number[_moneyCount % 100 / 10]->render(hdc, rc.left + 291, rc.top + 95);
	_number[_moneyCount % 10]->render(hdc, rc.left + 323, rc.top + 95);

	//bomb
	_number[_bombCount % 100 / 10]->render(hdc, rc.left + 387, rc.top + 95);
	_number[_bombCount % 10]->render(hdc, rc.left + 419, rc.top + 95);

	//arrow
	_number[_arrowCount % 100 / 10]->render(hdc, rc.left + 483, rc.top + 95);
	_number[_arrowCount % 10]->render(hdc, rc.left + 515, rc.top + 95);
}