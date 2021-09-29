#pragma once
#include "gameNode.h"
#include "item.h"

class Player : public gameNode
{
private:
	//��ü
	float _x, _y, _z;
	int _direct;
	RECT _body;

	//����
	int _hp;
	int _mp;
	float _speed;

	int _moneyCount;
	int _bombCount;
	int _arrowCount;

	//����
	bool _updown;
	bool _invincible;
	int _iCount;
	float _destX, _destY;

	//����Ʈ
	float _angle;
	PTILE _object;

public:
	Player() {};
	~Player() {};

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render();			//�׸��� �Լ�

	//���� ����
	void changeHP(float damage);
	void changeMP(float useskill);

	void changeMoney(int num);
	void changeBomb(int num);
	void changeArrow(int num);

	//����
	void move(int direct); //�÷��̾� �̵��Լ�
	void move(int direct, float speed);
	void invincibleTime();

	void changeZ();

	//================= ������ =================//
	void setX(float x) { _x = x; }
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }
	void setZ(float z) { _z = z; }
	float getZ() { return _z; }
	void setDirect(int direct) { _direct = direct; } //���� ������
	int getDirect() { return _direct; }				 //���� ������

	void setRect(float x, float y, int width, int height) { _body = RectMakeCenter(x, y, width, height); } //�÷��̾� �ٵ� ������
	RECT getBody() { return _body; }

	void setUpDown(bool updown) { _updown = updown; }
	bool getUpDown() { return _updown; }
	void setDestX(float x) { _destX = x; }
	void setDestY(float y) { _destY = y; }

	bool getInvincible() { return _invincible; }
	void invincibleOn() { _invincible = true; }

	void setObject(PTILE object) { _object = object; }
	PTILE getObject() { return _object; }
};