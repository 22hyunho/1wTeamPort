#pragma once
#include "State.h"
class Push :
	public State
{
private:

public:
	Push() {};
	~Push() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return PUSH; }

	void controlKey();
	void controlFrame();
};

