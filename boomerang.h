#pragma once
#include "item.h"
class boomerang :
	public item
{
private:
	float _fireX, _fireY;
	float _speed;
	float _angle;

	bool _isReturn;

public:
	boomerang() {};
	~boomerang() {};

	virtual HRESULT init(float x, float y, float z);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc, float x, float y);

	void useItem(float x, float y, float angle);
	void itemMove(float x, float y, float angle);
	void controlFrame();
};
