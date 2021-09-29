#pragma once
#include "singletonBase.h"
#include "tileInfo.h"
#include <vector>
#include <algorithm>

#define MARGIN	10

class Player;

class tileManager : public singletonBase<tileManager>
{
private:
	typedef vector<PTILE>			tileList;
	typedef vector<PTILE>::iterator	tileIter;

private:
	Player* _player;

	image*		_background;
	COLORREF	_backColor;

	tileList	_mapGTile;
	tileList	_mapBTile;

	tileList	_renderGTile;
	tileIter	_GTileIter;
	tileList	_renderBTile;
	tileIter	_BTileIter;

	int _width;

public:
	tileManager() {};
	~tileManager() {};

	HRESULT init(Player* player);
	HRESULT initMap(image* img, COLORREF rgb);
	void release();
	void update();
	void render(HDC hdc, int z);

	//사용하는 타일 이미지 등록
	void addTileImages();

	//맵(Scene)시작할 때 전체 맵 생성
	void createTile(float x, float y);
	void updateTile();

	PTILE makeTile(float x, float y, int ID, int z = 0);
	static bool compare(PTILE a, PTILE b);

	image* getBack() { return _background; }
	tileList* getGTile() { return &_mapGTile; }
	tileList* getBTile() { return &_mapBTile; }
};