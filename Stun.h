#pragma once
#include "State.h"
class Stun :
	public State
{
private:

public:
	Stun() {};
	~Stun() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return STUN; }

	void controlKey();
	void controlFrame();
	void controlAlpha();
};

