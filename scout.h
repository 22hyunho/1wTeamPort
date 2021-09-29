#pragma once
#include "enemy.h"

enum scoutS
{
	SCOUT_MOVE,
	SCOUT_SHIFT,
	SCOUTEND
};
class scout:public enemy
{
private:

	scoutS _state;				//스테이트 이넘 선언

	image* scout[3];				//각 이미지에 따른 선언
	image* scoutI;

public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual void hitDamage(float damage);
};

