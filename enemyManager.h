#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "boss.h"
#include "green.h"
#include "blue.h"
#include "snake.h"
#include "scout.h"
#include "mouse.h"
#include <vector>
#include "magic.h"

enum enemyType
{
	_Escout,
	_Egreen,
	_Eblue,
	_Emouse,
	_Esnake,
	_Eboss,
	_EEND
};

class enemyManager : public gameNode
{
private:

	typedef vector<enemy*>					vEnemy;
	typedef vector<enemy*>::iterator		viEnemy;

	typedef vector<boss*>					vEBoss;
	typedef vector<boss*>::iterator		    viEBoss;

private:

	
	vEnemy _vEnemy;
	viEnemy _viEnemy;


	vEBoss _vBoss;
	viEBoss _viBoss;

	fireball* _fire;
	circulator* _circul;
	//spread* _spread;

	RECT prc;

	int r;
	int index;
	float x2;
	float y2;

public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int z);

	void setEnemy(int ET, int i, int j);
	void setBoss(int i, int j);

	void removeEnemy(int arrNum);
	void removeBoss(int arrNum);
	
	void fire();
	void circulfire();


	vector<boss*> getVBoss() { return _vBoss; }
	vector<boss*>::iterator getVIBoss() { return _viBoss; }

	vector<enemy*> getVEnemy() { return _vEnemy; }
	vector<enemy*>::iterator getVIEnemy() { return _viEnemy; }
};

