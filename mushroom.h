#pragma once
#include "item.h"
class mushroom :
	public item
{
private:

public:
	mushroom() {};
	~mushroom() {};

	virtual HRESULT init(float x, float y, float z);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc, float x, float y);

	void useItem(float x, float y, float angle);
	void itemMove(float x, float y, float angle);
	void controlFrame();
};
