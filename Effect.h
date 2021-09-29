#pragma once
class Effect
{
protected:
	RECT _slashBox;


public:
	Effect() {};
	~Effect() {};

	virtual HRESULT init(float x, float y) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;

	RECT getAttackBox() { return _slashBox; }
};

