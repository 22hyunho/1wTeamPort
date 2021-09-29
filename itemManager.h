#pragma once
#include "singletonBase.h"
#include "item.h"

class itemManager : public singletonBase<itemManager>
{
private:
	typedef vector<item*> itemList;
	typedef vector<item*>::iterator itemListIter;

private:
	itemList _vItem;
	itemListIter _viItem;

public:
	itemManager() {};
	~itemManager() {};

	HRESULT init();
	void release();
	void update();
	void render();

	void removeItem(int arrNum);

	itemList getvItem() { return _vItem; }
	itemListIter getviItem() { return _viItem; }
};

