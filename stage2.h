#pragma once
#include "Scene.h"
#include "enemyManager.h"

#define MAPWIDTH	100
#define MAPHEIGHT	56

class stage2 : public Scene
{
private:
	image* _background;

	RECT _current;
	RECT _div[1][2];
	//0 ~ 50, 0 ~ 56
	//50 ~ 100, 0 ~ 56

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
