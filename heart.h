#pragma once
#include "item.h"

class heart : public item
{
private:

public:
	heart() {};
	~heart() {};

	virtual HRESULT init(float x, float y, float z = 0);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc, float x, float y);

	void useItem(float x, float y, float angle);
	void itemMove(float x, float y, float angle);
	void controlFrame();
};