#include "stdafx.h"
#include "inventoryManager.h"
#include "candela.h"
#include "boomerang.h"
#include "mushroom.h"
#include "Player.h"

HRESULT inventoryManager::init()
{
	_bgImg = IMAGEMANAGER->addImage("bg", "img/equip/all.bmp", 1024, 896, true, RGB(255, 0, 255));
	_selImg = IMAGEMANAGER->addFrameImage("select", "img/equip/select.bmp", 208, 104, 2, 1, true, RGB(255, 0, 255));

	_selItemRc = RectMake(800, 100, 64, 64);

	_count = 0;
	_index = 0;

	_invOpen = false;

	RECT rc = CAMERAMANAGER->getScreen();

	_a = rc.left + 160;
	_b = rc.top + 156;

	
	item* _boomerang = new boomerang;
	_boomerang->init(0, 0, 0);
	_vItem.push_back(_boomerang);

	item* _mushroom = new mushroom;
	_mushroom->init(0, 0, 0);
	_vItem.push_back(_mushroom);

	item* _candela = new candela;
	_candela->init(0, 0, 0);
	_vItem.push_back(_candela);
	

	if (_vItem.size() > 0)
	{
		_selItemRc = RectMake(_vItem[_index]->getX(), _vItem[_index]->getY(), 104, 104);
		_equipItem = _vItem[_index];
	}
	return S_OK;
}

void inventoryManager::release()
{
}

void inventoryManager::update()
{
	RECT rc = CAMERAMANAGER->getScreen();
	if (_vItem.size() > 0)_selItemRc = RectMakeCenter(rc.left + _vItem[_index]->getInvX() + 31, rc.top + _vItem[_index]->getInvY() + 29, 104, 104);
	controlFrame();
}

void inventoryManager::render(HDC hdc)
{
	RECT rc = CAMERAMANAGER->getScreen();
	_bgImg->render(hdc, rc.left, rc.top);
	//_bagImg->render(getMemDC(), _bagRC.left, _bagRC.top);

	//Rectangle(getMemDC(), _selItemRc);

	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->getImage()->render(hdc, rc.left + (*_viItem)->getInvX(), rc.top + (*_viItem)->getInvY());
	}

	if (_vItem.size() > 0)
	{
		_vItem[_index]->getImage()->render(hdc, rc.left + 800, rc.top + 100);
		_selImg->frameRender(hdc, _selItemRc.left, _selItemRc.top);
	}

}

void inventoryManager::controlKey()
{
}

void inventoryManager::controlFrame()
{
	_count++;

	if (_count >= 10)
	{
		if (_selImg->getFrameX() >= _selImg->getMaxFrameX())
			_selImg->setFrameX(0);
		else
			_selImg->setFrameX(_selImg->getFrameX() + 1);

		_count = 0;
	}
}

void inventoryManager::addItem(item * itemName)
{
	_vItem.push_back(itemName);
}

void inventoryManager::plusIndex()
{
	if (_vItem.size() > 0)
	{
		_index = (_index + 1) % _vItem.size();
		_equipItem = _vItem[_index];
	}
}

void inventoryManager::minusIndex()
{
	if (_vItem.size() > 0)
	{
		_index = (_index - 1 + _vItem.size()) % _vItem.size();
		_equipItem = _vItem[_index];
	}
}
