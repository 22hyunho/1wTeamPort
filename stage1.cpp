#include "stdafx.h"
#include "stage1.h"
#include "Player.h"

HRESULT stage1::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("stage1", "img/stage/stage1.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);

	_div[0][0] = RectMake(0, 0, 64 * TILEX, 64 * TILEY);
	_div[0][1] = RectMake(64 * TILEX, 0, 64 * TILEX, 64 * TILEY);
	_div[1][0] = RectMake(0, 64 * TILEY, 64 * TILEX, 64 * TILEY);
	_div[1][1] = RectMake(64 * TILEX, 64 * TILEY, 64 * TILEX, 64 * TILEY);

	setDivRect();
	TILEMANAGER->initMap(_background, RGB(72, 152, 72));

	COLLISIONMANAGER->init(this);

	_direct = ENDDIRECT;
	_change = false;
	_em = new enemyManager;
	_em->init();

	setEnemy();

	//곡 재생
	
	SOUNDMANAGER->play("beginning");
	return S_OK;
}

void stage1::release()
{
	SOUNDMANAGER->stop("beginning");
}

void stage1::update()
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

void stage1::render()
{
	//Z순서 맞춰주기 필요(던전에서는)
	for (int i = Z0; i <= Z2; i += 2) {
		_em->render(i);
		if (_player->getZ() == i - 1)
			_player->render();
		TILEMANAGER->render(getMemDC(), i);
	}
}

void stage1::changeScene()
{
	float x = _player->getX();
	float y = _player->getY();

	if ((3072 <= x && x <= 3136) &&
		(2750 < y && y < 3100)) {
		CAMERAMANAGER->setFade(FADEOUT);
		_player->move(UP, 2);

		if (CAMERAMANAGER->getAlpha() == 255) {
			//x, y 설정
			_player->setX(WINSIZEX / 2);
			_player->setY(1000);
			SCENEMANAGER->changeScene("stage0");
		}
	}

	if ((3712 <= x && x <= 3776) &&
		y < 350) {
		CAMERAMANAGER->setFade(FADEOUT);
		//_player->move(UP, 2);

		if (CAMERAMANAGER->getAlpha() == 255) {
			//x, y 설정
			_player->setX(2465);
			_player->setY(1375);
			SCENEMANAGER->changeScene("stage2");
		}
	}

	else if ((513 <= x && x <= 577) &&
		y < 265) {
		CAMERAMANAGER->setFade(FADEOUT);
		_player->move(UP, 2);

		if (CAMERAMANAGER->getAlpha() == 255) {
			//x, y 설정
			_player->setX(800);
			_player->setY(1665);
			_player->setZ(3);
			SCENEMANAGER->changeScene("stage2");
		}
	}
}

void stage1::setEnemy()
{
	_em->setEnemy(_Egreen, 2700, 3000);
	_em->setEnemy(_Eblue, 2700, 3000);
	_em->setEnemy(_Emouse, 2700, 3000);
	_em->setEnemy(_Esnake, 2700, 3000);
	//_em->setBoss(3000, 3000);
}

void stage1::setDivRect()
{
	if (_player->getY() <= 64 * TILEY)
		_indexY = 0;
	else
		_indexY = 1;

	if (_player->getX() <= 64 * TILEX)
		_indexX = 0;
	else
		_indexX = 1;

	_current = _div[_indexY][_indexX];
}

void stage1::updateDivRect()
{
	switch (_direct) {
	case UP:
		_current.top -= TILEY;
		_current.bottom -= TILEY;

		if (_current.top <= _div[_indexY][_indexX].top) {
			_current = _div[_indexY][_indexX];
			_change = false;
			CAMERAMANAGER->setRatioY(0.5);
		}
		break;
	case DOWN:
		_current.top += TILEY;
		_current.bottom += TILEY;

		if (_current.top >= _div[_indexY][_indexX].top) {
			_current = _div[_indexY][_indexX];
			_change = false;
			CAMERAMANAGER->setRatioY(0.5);
		}
		break;
	case LEFT:
		_current.left -= TILEX;
		_current.right -= TILEX;
		if (_current.left <= _div[_indexY][_indexX].left) {
			_current = _div[_indexY][_indexX];
			_change = false;
			CAMERAMANAGER->setRatioX(0.5);
		}
		break;
	case RIGHT:
		_current.left += TILEX;
		_current.right += TILEX;
		if (_current.left >= _div[_indexY][_indexX].left) {
			_current = _div[_indexY][_indexX];
			_change = false;
			CAMERAMANAGER->setRatioX(0.5);
		}
		break;

	default:
		break;
	}
}

int stage1::outofRect()
{
	float x = _player->getX();
	float y = _player->getY();

	if (y < _current.top) {
		_change = true;
		_indexY--;
		CAMERAMANAGER->setRatioY(0);
		return UP;
	}
	else if (y > _current.bottom) {
		_change = true;
		_indexY++;
		CAMERAMANAGER->setRatioY(1);
		return DOWN;
	}

	if (x < _current.left) {
		_change = true;
		_indexX--;
		CAMERAMANAGER->setRatioX(0);
		return LEFT;
	}
	else if (x > _current.right) {
		_change = true;
		_indexX++;
		CAMERAMANAGER->setRatioX(1);
		return RIGHT;
	}

	return ENDDIRECT;
}
