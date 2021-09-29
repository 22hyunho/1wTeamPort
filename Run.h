#pragma once
#include "State.h"
class Run : public State
{
private:

public:
	Run() {};
	~Run() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return RUN; }

	void controlKey();
	void controlFrame();
	void controlAlpha();
};

