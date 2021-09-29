#pragma once

enum ITEM
{
	BOOMERANG,
	MUSHROOM,
	CANDELA,
	HEART,
	RUPEE,
	ENDITEM
};

class item
{
protected:
	RECT _itemRC;
	image* _img;
	image* _useImg;
	float _x, _y, _z;
	float _invX, _invY;
	int _count;
	int _type;
	bool _isFire;

public:
	item() {};
	~item() {};

	virtual HRESULT init(float x, float y, float z) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc, float x, float y) = 0;

	virtual void useItem(float x, float y, float angle) = 0;
	virtual void itemMove(float x, float y, float angle) = 0;
	virtual void controlFrame() = 0;

	float getX() { return _x; }
	float getY() { return _y; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	float getInvX() { return _invX; }
	float getInvY() { return _invY; }

	virtual int getType() { return _type; }

	image* getImage() { return _img; }
	RECT getRect() { return _itemRC; }

	bool getFire() { return _isFire; }
};