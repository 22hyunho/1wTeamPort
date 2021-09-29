#pragma once
#include "Effect.h"
class E_CgAttack :
	public Effect
{
public:
	E_CgAttack() {};
	~E_CgAttack() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

