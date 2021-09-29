#pragma once
#include "singletonBase.h"
#include "E_Slash.h"
#include "E_CgAttack.h"

class EffectManager : public singletonBase<EffectManager>
{
private:
	Effect* _slash;
	Effect* _cgAttack;

public:
	EffectManager() {};
	~EffectManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSlash(float x, float y);
	void setChargeAttack(float x, float y);

	Effect* getSlash() { return _slash; }
	Effect* getCgAttack() { return _cgAttack; }
};

