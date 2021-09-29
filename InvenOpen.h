#pragma once
#include "State.h"
class InvenOpen :
	public State
{
private:

public:
	InvenOpen() {};
	~InvenOpen() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return INVENOPEN; }

	void controlKey();
	void controlFrame();
};

