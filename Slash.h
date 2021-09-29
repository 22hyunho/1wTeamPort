#pragma once
#include "State.h"

class Slash :
	public State
{
private:

public:
	Slash() {};
	~Slash() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return SLASH; }

	void controlKey();
	void controlFrame();
	void controlAlpha();
};