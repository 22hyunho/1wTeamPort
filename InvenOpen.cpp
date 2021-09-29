#include "stdafx.h"
#include "InvenOpen.h"

HRESULT InvenOpen::init(Player * player)
{
	return S_OK;
}

void InvenOpen::release()
{
}

void InvenOpen::update()
{
	controlKey();
}

void InvenOpen::render(HDC hdc)
{
	char str[128];
	sprintf_s(str, "index : %d", INVENTORYMANAGER->getIndex());
	TextOut(hdc, 10, 10, str, strlen(str));
}

void InvenOpen::updateDirect(int direct)
{
}

void InvenOpen::updateRect()
{
}

void InvenOpen::controlKey()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) INVENTORYMANAGER->plusIndex();
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) INVENTORYMANAGER->minusIndex();
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		INVENTORYMANAGER->close();
		STATEMANAGER->changeState(IDLE);
	}
}

void InvenOpen::controlFrame()
{
}
