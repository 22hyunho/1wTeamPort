#include "stdafx.h"
#include "itemManager.h"

HRESULT itemManager::init()
{
	return S_OK;
}

void itemManager::release()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end();)
	{
		if ((*_viItem) != NULL)
		{
			(*_viItem)->release();
			SAFE_DELETE((*_viItem));
			_viItem = _vItem.erase(_viItem);
		}

		else ++_viItem;
	}

	_vItem.clear();
}

void itemManager::update()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end();)
	{
		(*_viItem)->update();

		if (COLLISIONMANAGER->collisionItem((*_viItem)))
		{
			if((*_viItem)->getType() > ITEM_END)
		}
	}
}

void itemManager::render()
{
}

void itemManager::removeItem(int arrNum)
{
}
