#pragma once
#include "Effect.h"
class E_Slash :
	public Effect
{
public:
	E_Slash() {};
	~E_Slash() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

