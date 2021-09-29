#pragma once
#include "State.h"
class UseItem :
	public State
{
private:
	float angle;

public:
	UseItem() {};
	~UseItem() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return USEITEM; }

	void controlFrame();
};

