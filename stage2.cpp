#include "stdafx.h"
#include "stage2.h"
#include "Player.h"

HRESULT stage2::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("stage2", "img/stage/stage2.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);

	_div[0][0] = RectMake(0, 0, 50 * TILEX, 56 * TILEY);
	_div[0][1] = RectMake(50 * TILEX, 0, 50 * TILEX, 56 * TILEY);
	//_div[1][0] = RectMake(0, 64 * TILEY, 64 * TILEX, 64 * TILEY);
	//_div[1][1] = RectMake(64 * TILEX, 64 * TILEY, 64 * TILEX, 64 * TILEY);

	setDivRect();
	TILEMANAGER->initMap(_background, RGB(0, 0, 0));

	COLLISIONMANAGER->init(this);

	_direct = ENDDIRECT;
	_change = false;
	_em = new enemyManager;
	_em->init();

	setEnemy();

	//곡 재생
	SOUNDMANAGER->play("dungeon");

	return S_OK;
}

void stage2::release()
{
	SOUNDMANAGER->stop("dungeon");
}

void stage2::update()
{
	_em->update();

	if (_change) {
		updateDivRect();
	}
	else {
		if (CAMERAMANAGER->getFade() >= 0)
			_player->update();
		_direct = outofRect();
	}

	CAMERAMANAGER->updateScreen2(_player->getX(), _player->getY(), _current);
	TILEMANAGER->update();

	changeScene();
}

void stage2::render()
{
	//Z순서 맞춰주기 필요(던전에서는)
	for (int i = Z0; i <= Z4; i += 2) {
		_em->render(i);
		if (_player->getZ() == i - 1)
			_player->render();
		TILEMANAGER->render(getMemDC(), i);
	}
}

void stage2::changeScene()
{
	float x = _player->getX();
	float y = _player->getY();

	if ((768 <= x && x <= 832) &&
		1665 < y) {
		CAMERAMANAGER->setFade(FADEOUT);
		_player->move(DOWN, 2);

		if (CAMERAMANAGER->getAlpha() == 255) {
			//x, y 설정
			_player->setX(545);
			_player->setY(265);
			_player->setZ(1);
			SCENEMANAGER->changeScene("stage1");
		}
	}
}

void stage2::setEnemy()
{
	_em->setBoss(2460, 900);
}

void stage2::setDivRect()
{
	_indexY = 0;
	if (_player->getX() <= 50 * TILEX)
		_indexX = 0;
	else
		_indexX = 1;

	_current = _div[_indexY][_indexX];
}

void stage2::updateDivRect()
{
	switch (_direct) {
	case LEFT:
		_current.left -= TILEX;
		_current.right -= TILEX;
		if (_current.left <= _div[_indexY][_indexX].left) {
			_current = _div[_indexY][_indexX];
			_change = false;
			_player->setX(_current.right - 10 * TILEX);
			CAMERAMANAGER->setRatioX(0.5);
		}
		break;
	case RIGHT:
		_current.left += TILEX;
		_current.right += TILEX;
		if (_current.left >= _div[_indexY][_indexX].left) {
			_current = _div[_indexY][_indexX];
			_change = false;
			_player->setX(_current.left + 10 * TILEX);
			CAMERAMANAGER->setRatioX(0.5);
		}
		break;

	default:
		break;
	}
}

int stage2::outofRect()
{
	float x = _player->getX();
	float y = _player->getY();

	//if (y < _current.top) {
	//	_change = true;
	//	_indexY--;
	//	CAMERAMANAGER->setRatioY(0);
	//	return UP;
	//}
	//else if (y > _current.bottom) {
	//	_change = true;
	//	_indexY++;
	//	CAMERAMANAGER->setRatioY(1);
	//	return DOWN;
	//}

	if ((x < _current.left + 10 * TILEX) &&
		(384 <= y && y <= 448)) {
		_change = true;
		_indexX--;
		_player->setX(_current.left);
		CAMERAMANAGER->setRatioX(0);
		return LEFT;
	}
	else if ((x > _current.right - 10 * TILEX) &&
		(384 <= y && y <= 448)) {
		_change = true;
		_indexX++;
		_player->setX(_current.right);
		CAMERAMANAGER->setRatioX(1);
		return RIGHT;
	}

	return ENDDIRECT;
}
