#pragma once
#include "State.h"

class Charging : public State
{
private:
	bool _isComplete;
	image* _star;
	int _cCount;
	int _eCount;

	bool _isMove;
public:
	Charging() {};
	~Charging() {};

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return CHARGING; }

	void controlKey();
	void controlFrame();
	void controlAlpha();
	void effectFrame();
	void charge();
};