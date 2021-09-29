#pragma once
#include "singletonBase.h"

class uiManager : public singletonBase<uiManager>
{
private:
	image* _gauge;
	image* _gaugeBack;
	image* _xitem;
	image* _money;
	image* _bomb;
	image* _arrow;

	image* _lifeText;
	image* _life;
	image* _halfLife;
	image* _zeroLife;

	RECT _rc;

	image* _number[10];

	int _hp;
	int _mp;
	int _moneyCount;
	int _bombCount;
	int _arrowCount;

public:
	uiManager() {};
	~uiManager() {};

	HRESULT init(Player* player);
	void release();
	void update();
	void render(HDC hdc);

	void setHP(int hp) { _hp = hp; }
	void setMP(float mp) { _mp = mp; }

	void setMoney(int money) { _moneyCount = money; }
	void setBomb(int bomb) { _bombCount = bomb; }
	void setArrow(int arrow) { _arrowCount = arrow; }
};