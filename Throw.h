#pragma once
#include "State.h"

class Throw : public State
{
private:
	int _index;

public:

	Throw() {};
	~Throw() {};

	virtual HRESULT init(Player* player);
	virtual void release();
		virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return THROW; }

	void controlKey();
	void controlFrame();
};

