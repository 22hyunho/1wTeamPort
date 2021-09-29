#include "stdafx.h"
#include "E_Slash.h"

HRESULT E_Slash::init(float x, float y)
{
	_slashBox = RectMakeCenter(x, y, 64, 64);
	return S_OK;
}

void E_Slash::release()
{
}

void E_Slash::update()
{
}

void E_Slash::render(HDC hdc)
{
	Rectangle(hdc, _slashBox);
}
