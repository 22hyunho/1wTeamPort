#include "stdafx.h"
#include "collisionManager.h"
#include "Player.h"
#include "enemy.h"
#include "Scene.h"

HRESULT collisionManager::init(Player* player)
{
	_player = player;

	return S_OK;
}

HRESULT collisionManager::init(Scene* scene)
{
	_scene = scene;

	return S_OK;
}

void collisionManager::release()
{
}

void collisionManager::collisionPlayer()
{
	playerWithTile();
}

void collisionManager::playerWithTile()
{
	float x = _player->getX();
	float y = _player->getY();

	int initY = y / TILEY - MARGIN;
	int endY = y / TILEY + 1;
	int initX = x / TILEX - MARGIN;
	int endX = x / TILEX + 1;

	//예외처리
	if (initY < 0)
		initY = 0;
	if (initX < 0)
		initX = 0;

	int width = TILEMANAGER->getBack()->getWidth();

	RECT tmp;
	PTILE tile;

	int i, j;

	for (i = initY, j = initX; i <= endY; j++) {
		int index = i * width + j;
		tile = TILEMANAGER->getBTile()->at(index);

		if (IntersectRect(&tmp, &tile->body, &_player->getBody())) {
			if (tile->r == PASSABLE) continue;

			float width = tmp.right - tmp.left;
			float height = tmp.bottom - tmp.top;
			float x = (tile->body.right + tile->body.left) / 2;
			float y = (tile->body.bottom + tile->body.top) / 2;

			//좌우 충돌
			if (height > width) {
				//좌
				if (_player->getX() < x) {
					_player->setX(_player->getX() - width);
				}
				//우
				else {
					_player->setX(_player->getX() + width);
				}
			}
			//상하 충돌
			else if (width > height) {
				//아래
				if (_player->getY() > y) {
					if (tile->r == UPDOWN) {
						_player->setUpDown(true);
						_player->setDestY(tile->body.top);
						break;
					}
					_player->setY(_player->getY() + height);
				}
				//위
				else {
					if (tile->r == UPDOWN) {
						_player->setUpDown(true);
						_player->setDestY(tile->body.bottom);
						_player->setZ(4 - _player->getZ());
						break;
					}
					_player->setY(_player->getY() - height);
				}
			}

			_player->setRect(_player->getX(), _player->getY(), 64, 64);

		}

		if (j >= endX) {
			i++;
			j = initX - 1;
		}
	}


	for (i = initY, j = initX; i <= endY; j++) {
		int index = i * width + j;
		tile = TILEMANAGER->getGTile()->at(index);

		if (IntersectRect(&tmp, &tile->body, &_player->getBody())) {
			if (tile->r == PASSABLE) continue;

			float width = tmp.right - tmp.left;
			float height = tmp.bottom - tmp.top;
			float x = (tile->body.right + tile->body.left) / 2;
			float y = (tile->body.bottom + tile->body.top) / 2;

			//좌우 충돌
			if (height > width) {
				//좌
				if (_player->getX() < x) {
					_player->setX(_player->getX() - width);
				}
				//우
				else {
					_player->setX(_player->getX() + width);
				}
			}
			//상하 충돌
			else if (width > height) {
				//아래
				if (_player->getY() > y) {
					if (tile->r == UPDOWN) {
						_player->setUpDown(true);
						_player->setDestY(tile->body.top);
						break;
					}
					_player->setY(_player->getY() + height);
				}
				//위
				else {
					if (tile->r == UPDOWN) {
						_player->setUpDown(true);
						_player->setDestY(tile->body.bottom);
						_player->setZ(4 - _player->getZ());
						break;
					}
					_player->setY(_player->getY() - height);
				}
			}

			_player->setRect(_player->getX(), _player->getY(), 64, 64);
		}


		if (j >= endX) {
			i++;
			j = initX - 1;
		}
	}
}

void collisionManager::playerWithEnemy(enemy * Enemy)
{
	//RECT tmp;
	//RECT slash = EFFECTMANAGER->getSlash()->getAttackBox();
	//if (IntersectRect(&tmp, &slash, &Enemy->getRC())) {
	//	Enemy->hitDamage(15);
	//}
}

void collisionManager::interactPlayer()
{
	int direct = _player->getDirect();

	int x = _player->getX();
	int y = _player->getY();

	int width = TILEMANAGER->getBack()->getWidth();

	int initY, endY;
	int initX, endX;
	PTILE tile;

	switch (direct) {
	case UP:
		initX = x / TILEX - 1;
		endX = x / TILEX;
		initY = (y - 1) / TILEY - 2;
		endY = y / TILEY;
		break;

	case DOWN:
		initX = x / TILEX - 1;
		endX = x / TILEX;
		initY = y / TILEY;
		endY = y / TILEY + 1;
		break;

	case LEFT:
		initX = (x - 1) / TILEX - 2;
		endX = x / TILEX;
		initY = y / TILEY - 1;
		endY = y / TILEY;
		break;

	case RIGHT:
		initX = x / TILEX;
		endX = x / TILEX + 1;
		initY = y / TILEY - 1;
		endY = y / TILEY;
		break;
	}

	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			int index = i * width + j;
			tile = (*TILEMANAGER->getBTile())[index];
			if (tile->g == THROWABLE) {
				_player->setObject(tile);
				//(*TILEMANAGER->getBTile())[index] = TILEMANAGER->makeTile(j * TILEX, i *TILEY, NOTHING);
				break;
			}
		}
	}

	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			int index = i * width + j;
			tile = (*TILEMANAGER->getGTile())[index];
			if (tile->g == THROWABLE) {
				_player->setObject(tile);
				//(*tile) = *TILEMANAGER->makeTile(j * TILEX, i *TILEY, NOTHING);
				break;
			}
		}
	}
}

void collisionManager::collisionEnemy(enemy * Enemy)
{
	enemyWithTile(Enemy);
	enemyWithPlayer(Enemy);
}

void collisionManager::enemyWithTile(enemy * Enemy)
{
	float x = Enemy->getX();
	float y = Enemy->getY();

	int initY = y / TILEY - MARGIN;
	int endY = y / TILEY + 1;
	int initX = x / TILEX - MARGIN;
	int endX = x / TILEX + 1;

	//예외처리
	if (initY < 0)
		initY = 0;
	if (initX < 0)
		initX = 0;

	int width = TILEMANAGER->getBack()->getWidth();

	RECT tmp;
	PTILE tile;

	for (int i = initY; i <= endY; i++) {

		for (int j = initX; j <= endX; j++) {
			int index = i * width + j;
			tile = TILEMANAGER->getBTile()->at(index);

			if (IntersectRect(&tmp, &tile->body, &Enemy->getRC())) {
				if (tile->r == PASSABLE) continue;

				float width = tmp.right - tmp.left;
				float height = tmp.bottom - tmp.top;
				float x = (tile->body.right + tile->body.left) / 2;
				float y = (tile->body.bottom + tile->body.top) / 2;

				//좌우 충돌
				if (height > width) {
					//좌
					if (Enemy->getX() < x)
						Enemy->setX(Enemy->getX() - width);
					//우
					else
						Enemy->setX(Enemy->getX() + width);
				}
				//상하 충돌
				else if (width > height) {
					//아래
					if (Enemy->getY() > y)
						Enemy->setY(Enemy->getY() + height);
					//위
					else
						Enemy->setY(Enemy->getY() - height);
				}
				Enemy->setWay(false);
				//Enemy->setRect(Enemy->getX(), Enemy->getY(), 64, 64);
			}
		}
	}


	for (int i = initY; i <= endY; i++) {

		for (int j = initX; j <= endX; j++) {

			int index = i * width + j;
			tile = TILEMANAGER->getGTile()->at(index);

			if (IntersectRect(&tmp, &tile->body, &Enemy->getRC())) {
				if (tile->r == PASSABLE) continue;

				float width = tmp.right - tmp.left;
				float height = tmp.bottom - tmp.top;
				float x = (tile->body.right + tile->body.left) / 2;
				float y = (tile->body.bottom + tile->body.top) / 2;

				//좌우 충돌
				if (height > width) {
					//좌
					if (Enemy->getX() < x)
						Enemy->setX(Enemy->getX() - width);
					//우
					else
						Enemy->setX(Enemy->getX() + width);
				}
				//상하 충돌
				else if (width > height) {
					//아래
					if (Enemy->getY() > y)
						Enemy->setY(Enemy->getY() + height);
					//위
					else
						Enemy->setY(Enemy->getY() - height);
				}
				Enemy->setWay(false);
				//Enemy->setRect(Enemy->getX(), Enemy->getY(), 64, 64);
			}
		}
	}
}

void collisionManager::enemyWithPlayer(enemy * Enemy)
{
	if (!_player->getInvincible())
	{
		RECT tmp;
		if (IntersectRect(&tmp, &_player->getBody(), &Enemy->getRC())) {
			float width = tmp.right - tmp.left;
			float height = tmp.bottom - tmp.top;
			float x = (Enemy->getRC().right + Enemy->getRC().left) / 2;
			float y = (Enemy->getRC().bottom + Enemy->getRC().top) / 2;

			//좌우 충돌
			if (height > width) {
				//좌
				if (_player->getX() < x)
				{
					_player->setDirect(LEFT);
					STATEMANAGER->changeState(STUN);
				}
				//우
				else
				{
					_player->setDirect(RIGHT);
					STATEMANAGER->changeState(STUN);
				}
			}
			//상하 충돌
			else if (width > height) {
				//아래
				if (_player->getY() > y)
				{
					_player->setDirect(DOWN);
					STATEMANAGER->changeState(STUN);
				}
				//위
				else
				{
					_player->setDirect(UP);
					STATEMANAGER->changeState(STUN);
				}
			}

			_player->changeHP(16);
			_player->invincibleOn();
		}
		if (IntersectRect(&tmp, &_player->getBody(), &Enemy->getSword())) {
			float width = tmp.right - tmp.left;
			float height = tmp.bottom - tmp.top;
			float x = (Enemy->getSword().right + Enemy->getSword().left) / 2;
			float y = (Enemy->getSword().bottom + Enemy->getSword().top) / 2;

			//좌우 충돌
			if (height > width) {
				//좌
				if (_player->getX() < x)
				{
					_player->setDirect(LEFT);
					STATEMANAGER->changeState(STUN);
				}
				//우
				else
				{
					_player->setDirect(RIGHT);
					STATEMANAGER->changeState(STUN);
				}
			}
			//상하 충돌
			else if (width > height) {
				//아래
				if (_player->getY() > y)
				{
					_player->setDirect(DOWN);
					STATEMANAGER->changeState(STUN);
				}
				//위
				else
				{
					_player->setDirect(UP);
					STATEMANAGER->changeState(STUN);
				}
			}

			_player->changeHP(16);
			_player->invincibleOn();
		}
	}
}

void collisionManager::collisionItem(item * Item)
{
	itemWithPlayer(Item);
}

void collisionManager::itemWithPlayer(item * Item)
{
}
