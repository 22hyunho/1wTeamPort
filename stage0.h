#pragma once
#include "Scene.h"

#define MAPWIDTH	32
#define MAPHEIGHT	40

class stage0 : public Scene
{
private:
	image* _background;
	image* _background_front;
	image* _tileground;

public:
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeScene();
};

