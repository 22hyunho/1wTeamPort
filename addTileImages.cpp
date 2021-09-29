#include "stdafx.h"
#include "timeManager.h"

void addBush();
void addTree();
void addStone();
void addHouse();
void addCliff();
void addRoad();
/*********** dungeon ***********/
void addWall();
void addTile();
void addPath();
void addObject();
void addWall2();



void tileManager::addTileImages()
{
	addBush();
	addTree();
	addStone();
	addHouse();
	addCliff();
	addRoad();

	/*********** dungeon ***********/
	addWall();
	addTile();
	addPath();
	addObject();
	addWall2();



	IMAGEMANAGER->addImage(HOLE, "img/tile/bush/hole.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(COLLISION, "img/tile/collisionTile.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
}





void addBush()
{
	IMAGEMANAGER->addImage(BUSH, "img/tile/bush/bush.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BUSHOFF, "img/tile/bush/bush_off.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(WEED, "img/tile/bush/weed.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(RUG, "img/tile/bush/rug.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(GRASSTILE, "img/tile/bush/grassTILE.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BOARD, "img/tile/bush/board.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
}

void addTree()
{
	IMAGEMANAGER->addImage(TREEUP1, "img/tile/tree/treeUP1.bmp", TILEX * 6, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEUP2, "img/tile/tree/treeUP2.bmp", TILEX * 4, TILEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEUP3, "img/tile/tree/treeUP3.bmp", TILEX * 4, TILEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEUP4, "img/tile/tree/treeUP4.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEUP5, "img/tile/tree/treeUP5.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(TREEDOWN1, "img/tile/tree/treeDOWN1.bmp", TILEX * 4, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWN2, "img/tile/tree/treeDOWN2.bmp", TILEX * 4, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWN3, "img/tile/tree/treeDOWN3.bmp", TILEX * 4, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWN4, "img/tile/tree/treeDOWN4.bmp", TILEX * 3, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWN5, "img/tile/tree/treeDOWN5.bmp", TILEX * 3, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWN6, "img/tile/tree/treeDOWN6.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(TREETILE1, "img/tile/tree/treeTILE1.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREETILE2, "img/tile/tree/treeTILE2.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREETILE3, "img/tile/tree/treeTILE3.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREETILE4, "img/tile/tree/treeTILE4.bmp", TILEX, TILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(TREEUPINTER, "img/tile/tree/treeUPInter.bmp", TILEX * 2, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(TREEDOWNINTER, "img/tile/tree/treeDOWNInter.bmp", TILEX * 2, TILEY * 3, true, RGB(255, 0, 255));
}

void addStone()
{
	IMAGEMANAGER->addImage(STONE, "img/tile/stone/stone.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(STONEB, "img/tile/stone/stoneBlack.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(BIGSTONE, "img/tile/stone/bigStone.bmp", TILEX * 4, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BIGSTONEB, "img/tile/stone/bigStoneBlack.bmp", TILEX * 4, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(ST5NE, "img/tile/stone/st5ne.bmp", TILEX * 4, TILEY * 4, true, RGB(255, 0, 255));
}

void addHouse()
{
	IMAGEMANAGER->addImage(HOUSE1, "img/tile/house/house1.bmp", TILEX * 6, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE2, "img/tile/house/house2.bmp", TILEX * 6, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE3, "img/tile/house/house3.bmp", TILEX * 6, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE4, "img/tile/house/house4.bmp", TILEX * 6, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE5, "img/tile/house/house5.bmp", TILEX * 5, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE6, "img/tile/house/house6.bmp", TILEX * 5, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HOUSE7, "img/tile/house/house7.bmp", TILEX * 4, TILEY * 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(CHURCH1, "img/tile/house/church1.bmp", TILEX * 6, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH2, "img/tile/house/church2.bmp", TILEX * 4, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH3, "img/tile/house/church3.bmp", TILEX * 6, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH4, "img/tile/house/church4.bmp", TILEX * 4, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH5, "img/tile/house/church5.bmp", TILEX * 2, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH6, "img/tile/house/church6.bmp", TILEX * 2, TILEY * 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH7, "img/tile/house/church7.bmp", TILEX * 4, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH8, "img/tile/house/church8.bmp", TILEX * 4, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CHURCH9, "img/tile/house/church9.bmp", TILEX * 4, TILEY * 4, true, RGB(255, 0, 255));
}

void addCliff()
{
	IMAGEMANAGER->addImage(CLIFF1, "img/tile/cliff/cliff1.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF2, "img/tile/cliff/cliff2.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF3, "img/tile/cliff/cliff3.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF4, "img/tile/cliff/cliff4.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF5, "img/tile/cliff/cliff5.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF6, "img/tile/cliff/cliff6.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF7, "img/tile/cliff/cliff7.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF8, "img/tile/cliff/cliff8.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF9, "img/tile/cliff/cliff9.bmp", TILEX * 3, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF10, "img/tile/cliff/cliff10.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF11, "img/tile/cliff/cliff11.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF12, "img/tile/cliff/cliff12.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF13, "img/tile/cliff/cliff13.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF14, "img/tile/cliff/cliff14.bmp", TILEX * 3, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF15, "img/tile/cliff/cliff15.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF16, "img/tile/cliff/cliff16.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF17, "img/tile/cliff/cliff17.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF18, "img/tile/cliff/cliff18.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFF19, "img/tile/cliff/cliff19.bmp", TILEX * 2, TILEY * 5, true, RGB(255, 0, 255));

	char str[128];
	for (int i = 1, j = CLIFFTILE1; j <= CLIFFTILE15; i++, j++) {
		if (j != CLIFFTILE3) {
			sprintf_s(str, "img/tile/cliff/cliffTILE%d.bmp", i);
			IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
		}
		else {
			sprintf_s(str, "img/tile/cliff/cliffTILE%d.bmp", i);
			IMAGEMANAGER->addImage(j, str, TILEX * 2, TILEY, true, RGB(255, 0, 255));
		}
	}

	IMAGEMANAGER->addImage(CLIFFIN1, "img/tile/cliff/cliffIn1.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFFIN2, "img/tile/cliff/cliffIn2.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFFIN3, "img/tile/cliff/cliffIn3.bmp", TILEX, TILEY * 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFFIN4, "img/tile/cliff/cliffIn4.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFFIN5, "img/tile/cliff/cliffIn5.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CLIFFIN6, "img/tile/cliff/cliffIn6.bmp", TILEX, TILEY * 5, true, RGB(255, 0, 255));

}

void addRoad()
{
	char str[128];

	//road
	for (int i = 1, j = ROAD1; j <= ROAD14; i++, j++) {
		sprintf_s(str, "img/tile/ground/road%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	//fence
	IMAGEMANAGER->addImage(FENCE1, "img/tile/ground/fence1.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(FENCE2, "img/tile/ground/fence2.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(FENCE3, "img/tile/ground/fence3.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(BOTTOM, "img/tile/ground/bottom.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
}

void addWall()
{
	IMAGEMANAGER->addImage(HANDRAIL1, "img/tile/dungeon/wall/handrail1.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HANDRAIL2, "img/tile/dungeon/wall/handrail2.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(HANDRAIL3, "img/tile/dungeon/wall/handrail3.bmp", TILEX, TILEY, true, RGB(255, 0, 255));

	char str[128];
	for (int i = 1, j = WALLIN1; j <= WALLIN20; i++, j++) {
		sprintf_s(str, "img/tile/dungeon/wall/wall_in%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = WALLOUT1; j <= WALLOUT20; i++, j++) {
		sprintf_s(str, "img/tile/dungeon/wall/wall_out%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = WALL1; j <= WALL8; i++, j++) {
		sprintf_s(str, "img/tile/dungeon/wall/wall%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
}

void addTile()
{
	IMAGEMANAGER->addImage(BORDER1, "img/tile/dungeon/tile/border1.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2, "img/tile/dungeon/tile/border2.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER3, "img/tile/dungeon/tile/border3.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER4, "img/tile/dungeon/tile/border4.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER5, "img/tile/dungeon/tile/border5.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER6, "img/tile/dungeon/tile/border6.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER7, "img/tile/dungeon/tile/border7.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER8, "img/tile/dungeon/tile/border8.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(BORDER2F1, "img/tile/dungeon/tile/border2F1.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F2, "img/tile/dungeon/tile/border2F2.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F3, "img/tile/dungeon/tile/border2F3.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F4, "img/tile/dungeon/tile/border2F4.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F5, "img/tile/dungeon/tile/border2F5.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F6, "img/tile/dungeon/tile/border2F6.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F7, "img/tile/dungeon/tile/border2F7.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BORDER2F8, "img/tile/dungeon/tile/border2F8.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(BOTTOMTILE, "img/tile/dungeon/tile/bottomTILE.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BOTTOMTILE2F, "img/tile/dungeon/tile/bottomTILE2F.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(ROOFTILE, "img/tile/dungeon/tile/roofTILE.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
}

void addPath()
{
	IMAGEMANAGER->addImage(DOORRIGHT1, "img/tile/dungeon/path/doorRIGHT1.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORRIGHT2, "img/tile/dungeon/path/doorRIGHT2.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORRIGHT3, "img/tile/dungeon/path/doorRIGHT3.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORRIGHT4, "img/tile/dungeon/path/doorRIGHT4.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORLEFT1, "img/tile/dungeon/path/doorLEFT1.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORLEFT2, "img/tile/dungeon/path/doorLEFT2.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORLEFT3, "img/tile/dungeon/path/doorLEFT3.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORLEFT4, "img/tile/dungeon/path/doorLEFT4.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(DOORDOWN2F1, "img/tile/dungeon/path/doorDOWN2F1.bmp", TILEX * 4, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORDOWN2F2, "img/tile/dungeon/path/doorDOWN2F2.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORDOWN2F3, "img/tile/dungeon/path/doorDOWN2F3.bmp", TILEX, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOORDOWN2F4, "img/tile/dungeon/path/doorDOWN2F4.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(LADDER1, "img/tile/dungeon/path/ladder1.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(LADDER2, "img/tile/dungeon/path/ladder2.bmp", TILEX * 2, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(LADDER3, "img/tile/dungeon/path/ladder3.bmp", TILEX, TILEY * 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(DOWNSTAIR1, "img/tile/dungeon/path/downStair1.bmp", TILEX * 4, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOWNSTAIR2, "img/tile/dungeon/path/downStair2.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOWNSTAIR3, "img/tile/dungeon/path/downStair3.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(DOWNSTAIR4, "img/tile/dungeon/path/downStair4.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
}

void addObject()
{
	IMAGEMANAGER->addImage(BOX, "img/tile/dungeon/object/box.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(CANDLE1, "img/tile/dungeon/object/candle1.bmp", TILEX * 2, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CANDLE2, "img/tile/dungeon/object/candle2.bmp", TILEX * 4, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CANDLE3, "img/tile/dungeon/object/candle3.bmp", TILEX * 2, TILEY * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(CANDLE4, "img/tile/dungeon/object/candle4.bmp", TILEX * 4, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(JAR, "img/tile/dungeon/object/jar.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(JARBOTTOM, "img/tile/dungeon/object/jar_bottom.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(PILLAR1, "img/tile/dungeon/object/pillar1.bmp", TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(PILLAR2, "img/tile/dungeon/object/pillar2.bmp", TILEX * 2, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(PILLAR3, "img/tile/dungeon/object/pillar3.bmp", TILEX * 2, TILEY * 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(STATUE, "img/tile/dungeon/object/statue.bmp", TILEX * 2, TILEY * 3, true, RGB(255, 0, 255));
}

void addWall2()
{
	char str[128];
	for (int i = 1, j = WALL2OUT1; j <= WALL2OUT8; i++, j++) {
		sprintf_s(str, "img/tile/dungeon/wall/wall2_out%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX * 2, TILEY * 2, true, RGB(255, 0, 255));
	}

	for (int i = 1, j = WALL2IN1; j <= WALL2IN12; i++, j++) {
		sprintf_s(str, "img/tile/dungeon/wall/wall2_in%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
}
