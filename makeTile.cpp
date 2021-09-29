#include "tileManager.h"

PTILE makeBush(float x, float y, int ID);
PTILE makeTree(float x, float y, int ID);
PTILE makeStone(float x, float y, int ID);
PTILE makeHouse(float x, float y, int ID);
PTILE makeCliff(float x, float y, int ID);
PTILE makeRoad(float x, float y, int ID);

/*********** dungeon ***********/
PTILE makeWall(float x, float y, int ID, int z);
PTILE makeDTile(float x, float y, int ID, int z);
PTILE makePath(float x, float y, int ID, int z);
PTILE makeObject(float x, float y, int ID, int z);
PTILE makeWall2(float x, float y, int ID, int z);

PTILE makeExtraTile(float x, float y, int ID, int z);


PTILE tileManager::makeTile(float x, float y, int ID, int z)
{
	PTILE tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0, TILEX, TILEY, nullptr);

	if (ID == NOTHING || ID > COLLISION) return tile;

	else if (HOLE <= ID && ID <= COLLISION)
		tile = makeExtraTile(x, y, ID, z);

	//========= bush =========//
	else if (BUSH <= ID && ID <= BOARD)
		tile = makeBush(x, y, ID);

	//========= tree =========//
	else if (TREEUP1 <= ID && ID <= TREEDOWNINTER)
		tile = makeTree(x, y, ID);

	//========= stone =========//
	else if (STONE <= ID && ID <= ST5NE)
		tile = makeStone(x, y, ID);

	//========= house =========//
	else if ((HOUSE1 <= ID && ID <= HOUSE7) ||
		(CHURCH1 <= ID && ID <= CHURCH9))
		tile = makeHouse(x, y, ID);

	//========= cliff =========//
	else if (CLIFF1 <= ID && ID <= CLIFFIN6)
		tile = makeCliff(x, y, ID);

	//========= road =========//
	//========= fence =========//
	else if (ROAD1 <= ID && ID <= FENCE3)
		tile = makeRoad(x, y, ID);




	/*********** dungeon ***********/
	//========= wall =========//
	else if (HANDRAIL1 <= ID && ID <= WALL8)
		tile = makeWall(x, y, ID, z);

	//========= tile =========//
	else if (BORDER1 <= ID && ID <= BOTTOMTILE2F)
		tile = makeDTile(x, y, ID, z);

	//========= path =========//
	else if (DOORRIGHT1 <= ID && ID <= DOWNSTAIR4)
		tile = makePath(x, y, ID, z);

	//========= object =========//
	else if (BOX <= ID && ID <= STATUE)
		tile = makeObject(x, y, ID, z);

	//========= wall2 =========//
	else if (WALL2OUT1 <= ID && ID <= WALL2IN12)
		tile = makeWall2(x, y, ID, z);


	return tile;
}

PTILE makeBush(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case BUSH:
		tile = new TILE(IMPASSABLE, THROWABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;
	case BUSHOFF:
	case WEED:
	case RUG:
	case GRASSTILE:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case BOARD:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeTree(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case TREEUP1:
	case TREEUP2:
	case TREEUP3:
	case TREEUP4:
	case TREEUP5:
	case TREEUPINTER:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case TREEDOWN1:
	case TREEDOWN2:
	case TREEDOWN3:
	case TREEDOWN4:
	case TREEDOWN5:
	case TREEDOWN6:
	case TREEDOWNINTER:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case TREETILE1:
	case TREETILE2:
	case TREETILE3:
	case TREETILE4:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeStone(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case STONE:
	case STONEB:
		tile = new TILE(IMPASSABLE, THROWABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case BIGSTONE:
	case BIGSTONEB:
	case ST5NE:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeHouse(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case HOUSE1:
	case HOUSE2:
	case HOUSE3:
	case HOUSE4:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case HOUSE5:
	case HOUSE6:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case HOUSE7:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case CHURCH1:
	case CHURCH2:
	case CHURCH3:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case CHURCH4:
	case CHURCH5:
	case CHURCH6:
	case CHURCH7:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case CHURCH8:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case CHURCH9:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeCliff(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case CLIFF1:
	case CLIFF2:
	case CLIFF3:
	case CLIFF4:
	case CLIFF5:
	case CLIFF6:
	case CLIFF7:
	case CLIFF8:
	case CLIFF9:
	case CLIFF10:
	case CLIFF11:
	case CLIFF12:
	case CLIFF13:
	case CLIFF14:
	case CLIFF15:
	case CLIFF16:
	case CLIFF17:
	case CLIFF18:
	case CLIFF19:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case CLIFFTILE1:
	case CLIFFTILE2:
	case CLIFFTILE3:
	case CLIFFTILE4:
	case CLIFFTILE5:
	case CLIFFTILE6:
	case CLIFFTILE7:
	case CLIFFTILE8:
	case CLIFFTILE9:
	case CLIFFTILE10:
	case CLIFFTILE11:
	case CLIFFTILE12:
	case CLIFFTILE13:
	case CLIFFTILE14:
	case CLIFFTILE15:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case CLIFFIN1:
	case CLIFFIN2:
	case CLIFFIN3:
	case CLIFFIN4:
	case CLIFFIN5:
	case CLIFFIN6:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeRoad(float x, float y, int ID)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case ROAD1:
	case ROAD2:
	case ROAD3:
	case ROAD4:
	case ROAD5:
	case ROAD6:
	case ROAD7:
	case ROAD8:
	case ROAD9:
	case ROAD10:
	case ROAD11:
	case ROAD12:
	case ROAD13:
	case ROAD14:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case FENCE1:
	case FENCE2:
	case FENCE3:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeWall(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case HANDRAIL1:
	case HANDRAIL2:
	case HANDRAIL3:

	case WALLIN1:
	case WALLIN2:
	case WALLIN3:
	case WALLIN4:
	case WALLIN5:
	case WALLIN6:
	case WALLIN7:
	case WALLIN8:
	case WALLIN9:
	case WALLIN10:
	case WALLIN11:
	case WALLIN12:
	case WALLIN13:
	case WALLIN14:
	case WALLIN15:
	case WALLIN16:
	case WALLIN17:
	case WALLIN18:
	case WALLIN19:
	case WALLIN20:

	case WALLOUT1:
	case WALLOUT2:
	case WALLOUT3:
	case WALLOUT4:
	case WALLOUT5:
	case WALLOUT6:
	case WALLOUT7:
	case WALLOUT8:
	case WALLOUT9:
	case WALLOUT10:
	case WALLOUT11:
	case WALLOUT12:
	case WALLOUT13:
	case WALLOUT14:
	case WALLOUT15:
	case WALLOUT16:
	case WALLOUT17:
	case WALLOUT18:
	case WALLOUT19:
	case WALLOUT20:

	case WALL1:
	case WALL2:
	case WALL3:
	case WALL4:
	case WALL5:
	case WALL6:
	case WALL7:
	case WALL8:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeDTile(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case BORDER1:
	case BORDER2:
	case BORDER3:
	case BORDER4:
	case BORDER5:
	case BORDER6:
	case BORDER7:
	case BORDER8:
	case BOTTOMTILE:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case BORDER2F1:
	case BORDER2F2:
	case BORDER2F3:
	case BORDER2F4:
	case BORDER2F5:
	case BORDER2F6:
	case BORDER2F7:
	case BORDER2F8:
	case BOTTOMTILE2F:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case ROOFTILE:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z4,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makePath(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case DOORRIGHT1:
	case DOORLEFT1:
	case DOORDOWN2F1:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z + Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case DOORRIGHT2:
	case DOORLEFT2:
	case DOORDOWN2F2:
	case DOORRIGHT3:
	case DOORLEFT3:
	case DOORDOWN2F3:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case DOORRIGHT4:
	case DOORLEFT4:
	case DOORDOWN2F4:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case LADDER1:
	case LADDER3:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case LADDER2:
		tile = new TILE(UPDOWN, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case DOWNSTAIR1:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z + Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case DOWNSTAIR2:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;
	case DOWNSTAIR3:
	case DOWNSTAIR4:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeObject(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case BOX:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case CANDLE1:
	case CANDLE2:
	case CANDLE3:
	case CANDLE4:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case JAR:
		tile = new TILE(IMPASSABLE, THROWABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;
	case JARBOTTOM:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;

	case PILLAR1:
	case PILLAR2:
	case PILLAR3:
	case STATUE:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;


	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}

PTILE makeWall2(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case WALL2OUT1:
	case WALL2OUT2:
	case WALL2OUT3:
	case WALL2OUT4:
	case WALL2OUT5:
	case WALL2OUT6:
	case WALL2OUT7:
	case WALL2OUT8:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, z + Z2,
			img->getWidth(), img->getHeight(), img);
		break;

	case WALL2IN1:
	case WALL2IN2:
	case WALL2IN3:
	case WALL2IN4:
	case WALL2IN5:
	case WALL2IN6:
	case WALL2IN7:
	case WALL2IN8:
	case WALL2IN9:
	case WALL2IN10:
	case WALL2IN11:
	case WALL2IN12:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, z,
			img->getWidth(), img->getHeight(), img);
		break;


	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;


}

PTILE makeExtraTile(float x, float y, int ID, int z)
{
	PTILE tile;
	image* img;

	img = IMAGEMANAGER->findImage(ID);

	switch (ID) {
	case HOLE:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case BOTTOM:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;

	case COLLISION:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, Z0,
			img->getWidth(), img->getHeight(), img);
		break;


	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, Z0,
			TILEX, TILEY, nullptr);
		break;
	}

	return tile;
}
