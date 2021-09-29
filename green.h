#pragma once
#include "enemy.h"


enum greenG
{
	GREEN_MOVE,
	GREEN_SEARCH,
	GREEN_FALL,
	GREEN_HIT,
	GREENEND
};

class green : public enemy
{
private:
	greenG _state;				//스테이트 이넘 선언


	image* green[3];				//각 이미지에 따른 선언
	image* greenI;
public:

	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

	virtual void hitDamage(float damage);

};

