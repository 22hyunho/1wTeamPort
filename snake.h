#pragma once
#include "enemy.h"

enum snakeS
{
	SNAKE_MOVE,
	SNAKEEND
};

class snake: public enemy
{
private:

	snakeS _state;				//스테이트 이넘 선언

	image* snake[2];				//각 이미지에 따른 선언
	image* snakeI;

public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual void hitDamage(float damage);
};

