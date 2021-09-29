#include "stdafx.h"
#include "E_CgAttack.h"

HRESULT E_CgAttack::init(float x, float y)
{
	_slashBox = RectMakeCenter(x, y, 192, 192);
	return S_OK;
}

void E_CgAttack::release()
{
}

void E_CgAttack::update()
{
}

void E_CgAttack::render(HDC hdc)
{
	Rectangle(hdc, _slashBox);
}
