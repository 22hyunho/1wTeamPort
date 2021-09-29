#pragma once
#include "singletonBase.h"
#include "State.h"

class item;
class Player;

class inventoryManager : public singletonBase<inventoryManager>
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator itemIter;

private:
	itemList _vItem;
	itemIter _viItem;

	image* _bgImg;

	item* _equipItem;

	int _a, _b;

	RECT _selItemRc;
	image* _selImg;
	float _count;
	int _index;
	bool _invOpen;

public:
	inventoryManager() {};
	~inventoryManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void addItem(item* item);

	void plusIndex();
	void minusIndex();

	void controlKey();
	void controlFrame();

	item* getEquipItem() { return _equipItem; }
	int getIndex() { return _index; }

	void open() { _invOpen = true; }
	void close() { _invOpen = false; }
	bool isOpen() { return _invOpen; }
};
