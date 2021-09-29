#include "stdafx.h"
#include "stage0.h"
#include "Player.h"

HRESULT stage0::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("stage0", "img/stage/stage0.bmp", MAPWIDTH * TILEX, MAPHEIGHT * TILEY, false, RGB(0, 0, 0));
	_background_front = IMAGEMANAGER->addImage("stage0_front", "img/stage/stage0_front.bmp", 1024, 160, false, RGB(0, 0, 0));
	_tileground = IMAGEMANAGER->addImage("stage0_tile", "img/stage/stage0_tile.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);

	TILEMANAGER->initMap(_tileground, RGB(57, 40, 41));
	//	TILEMANAGER->initMap(_background, RGB(72, 152, 72));

	COLLISIONMANAGER->init(this);
	//SOUNDMANAGER->play("beginning");
	return S_OK;
}

void stage0::release()
{
	//SOUNDMANAGER->stop("beginning");
}

void stage0::update()
{
	if (CAMERAMANAGER->getFade() >= 0)
		_player->update();
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	TILEMANAGER->update();

	changeScene();
}

void stage0::render()
{
	TILEMANAGER->render(getMemDC(), Z0);
	_background->render(getMemDC(), 0, 0);
	_player->render();
	_background_front->render(getMemDC(), 0, 1120);
}

void stage0::changeScene()
{
	float x = _player->getX();
	float y = _player->getY();

	if (y >= 1082) {
		CAMERAMANAGER->setFade(FADEOUT);
		_player->move(DOWN, 2);

		if (CAMERAMANAGER->getAlpha() == 255) {
			//x, y ¼³Á¤
			_player->setX(3104);
			_player->setY(3100);
			SCENEMANAGER->changeScene("stage1");
		}
	}
}
