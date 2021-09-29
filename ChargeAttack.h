#pragma once
#include "State.h"

class ChargeAttack : public State
{
private:

public:
	ChargeAttack() {};
	~ChargeAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return CHARGEATTACK; }

	void controlKey();
	void controlFrame();
	void controlAlpha();

};