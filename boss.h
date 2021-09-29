#pragma once
#include "gameNode.h"

enum agahnim
{
	ATTACK,
	BOSS_MOVE,
	BOSSEND
};
class boss :public gameNode
{
private:

	agahnim _state;				//스테이트 이넘 선언

	RECT _rc;					//캐릭터 렉트
	RECT _censor;				//센서 렉트
	image* boss[3];				//각 이미지에 따른 선언
	image* bossI;


	int _count;					//스테이트 끌어오기 카운트
	int _indexX;					//프레임 순서 인덱스
	int _indexY;					//프레임 위아래 인덱스
	int _movecount;				//너무 바로바로 움직이면 안되니까
	int _direction;				//방향
	int _pattern;				//공격패턴
	int _aCount;					//어택 카운트
	int _mCount;					//무브 카운트
	int _lCount;					//필살기 카운트

	float _maxHP, _currentHP;		//체력, 현재체력
	float _x,_y, _z;				//X,Y,Z값
	float _cx, _cy;				//센서X, 센서Y값
	float _bodyDMG;				//몸박 데미지
	float _midW, _midH;			//기준렉트의 가로세로 중앙

	bool _lightning;				//필살기 가능상태
	bool _aPossible;				//공격이 가능한 상태인가
	bool _mPossible;				//이동이 가능한 상태인가

public:
	HRESULT init();
	HRESULT init(POINT position);
	void release();
	void update();
	void render();
	void draw();
	void hitDamage(float damage);


	float getHP() { return _currentHP; }
	RECT getRect() { return _rc; }
	float getbodYDMG() { return _bodyDMG; }
	int getaC() { return _aCount; }
	int getmC() { return _mCount; }
	int getindexX() { return _indexX; }
	float getmidW() { return _midW; }
	float getmidH() { return _midH; }
	int getD() { return _direction; }
	bool getLightning() { return _lightning; }
	image* getI() { return bossI; }
	int getPattern(){ return _pattern; }

	float getZ() { return _z; }
};
