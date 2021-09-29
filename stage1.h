#pragma once
#include "Scene.h"
#include "enemyManager.h"

#define MAPWIDTH	128
#define MAPHEIGHT	128

class stage1 : public Scene
{
private:
	image* _background;

	RECT _current;
	RECT _div[2][2];
	//0 ~ 128, 0 ~ 64
	//0 ~ 128, 64 ~ 128

	enemyManager* _em;

	int _indexY;
	int _indexX;
	int _direct;
	bool _change;

public:
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeScene();

	void setEnemy();

	void setDivRect();
	void updateDivRect();

	int outofRect();
};
