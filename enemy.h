#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:

	RECT _rc;					//각 이미지의 렉트
	RECT _sword;				//검범위 렉트

	int _state;					//스테이트 현재상태 불러오기
	int _next;					//다음 움직이는 횟수
	int _findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int _indexX;					//프레임 순서 인덱스
	int _indexY;					//프레임 위아래 인덱스
	int _indexH;					//머리 움직이기 전용 인덱스
	int _movecount;				//너무 바로바로 움직이면 안되니까
	int _direction;				//방향

	float _radius;
	float _maxHP, _currentHP;		//체력, 현재체력
	float _x, _y, _z;				//X,Y,Z값
	float _bodyDMG;				//몸박 데미지

	bool _way;					//길을 갈 수 있는가 없는가.

public:
	virtual HRESULT init(POINT position) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void hitDamage(float damage) = 0;

	float getHP() { return _currentHP; }

	RECT getRC() { return _rc; }
	RECT getSword() { return _sword; }

	void setRC(float x, float y, int width, int height) { _rc = RectMakeCenter(x, y, width, height); }

	float getBodyDMG() { return _bodyDMG; }
	int getN() { return _next; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	float getZ() { return _z; }
	void setZ(float z) { _z = z; }
	bool getWay() { return _way; }
	void setWay(bool Way) { _way=Way; }
};