#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{
	_fire = new fireball;
	_fire->init(0, 500);
	_circul = new circulator;
	_circul->init(0,7, 500);
	_vBoss.clear();
	_vEnemy.clear();
	return	S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
		//갱신
		COLLISIONMANAGER->collisionEnemy((*_viEnemy));
		//갱신
	}
	
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->update();
	}
	_fire->update();
	_circul->update();
	
	fire();
	circulfire();
}

void enemyManager::render(int z)
{
	RECT rc = CAMERAMANAGER->getScreen();

	
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		if((*_viEnemy)->getZ() < z)
			(*_viEnemy)->render();
	}
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		if ((*_viBoss)->getZ() < z)
			(*_viBoss)->render();
	}
	_fire->render();
	_circul->render();
}

void enemyManager::setEnemy(int ET, int i, int j)
{
	enemy* Enemy;

	switch (ET)
	{
	case _Escout://stage1 : 박쥐2 마리, 스카웃 3마리
		Enemy = new scout;
		break;
	case _Egreen:
		Enemy = new green;
		break;
	case _Eblue:
		Enemy = new blue;
		break;
	case _Emouse:
		Enemy = new mouse;
		break;
	case _Esnake:
		Enemy = new snake;
		break;
	default:
		return;
	}

	Enemy->init(PointMake(i, j));
	_vEnemy.push_back(Enemy);
}

void enemyManager::setBoss(int i, int j)
{
	boss* Boss = new boss;
	Boss->init(PointMake(i, j));
	_vBoss.push_back(Boss);
}

void enemyManager::removeEnemy(int arrNum)
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

void enemyManager::removeBoss(int arrNum)
{
	_vBoss.erase(_vBoss.begin() + arrNum);
}

void enemyManager::fire()
{
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		if ((*_viBoss)->getD()==0&&(*_viBoss)->getPattern()==0&&!(*_viBoss)->getLightning())
		{
				_fire->setIndexY(0);
			if ((*_viBoss)->getaC()>=17)
			{	
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left) / 2, rc.bottom,
					getAngle(fx + (rc.right - rc.left) / 2, rc.bottom, 
						_ptMouse.x+CAMERAMANAGER->getScreen().left,
						_ptMouse.y+CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
				
			}
		}
		if ((*_viBoss)->getD() == 1 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			_fire->setIndexY(1);
			if ((*_viBoss)->getaC() >= 17)
			{
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left) / 2, rc.top,
					getAngle(fx + (rc.right - rc.left) / 2, rc.top,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
			}
		}
		if ((*_viBoss)->getD() == 2 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			_fire->setIndexY(2);
			if ((*_viBoss)->getaC() >= 17)
			{
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx , fy+(rc.bottom-rc.top)/2,
					getAngle(fx, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
			}
		}
		if ((*_viBoss)->getD() == 3 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			_fire->setIndexY(3);
			if ((*_viBoss)->getaC() >= 17)
			{
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(rc.right, fy + (rc.bottom - rc.top) / 2,
					getAngle(rc.right, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
			}
		}
		if ((*_viBoss)->getD() == 4 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			_fire->setIndexY(4);
			if ((*_viBoss)->getaC() >= 17)
			{
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx, rc.bottom,
					getAngle(fx, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
			}
		}
		if ((*_viBoss)->getD() == 5 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			_fire->setIndexY(5);
			if ((*_viBoss)->getaC() >= 17)
			{
				
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left), rc.bottom,
					getAngle(fx + (rc.right - rc.left), rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				continue;
			}
		}

		_fire->setIndexY(6);
	}
}

void enemyManager::circulfire()
{
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		if ((*_viBoss)->getD() == 0 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left) / 2, rc.bottom,
					getAngle(fx + (rc.right - rc.left) / 2, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 1 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left) / 2, rc.top,
					getAngle(fx + (rc.right - rc.left) / 2, rc.top,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 2 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx, fy + (rc.bottom - rc.top) / 2,
					getAngle(fx, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 3 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{
			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(rc.right, fy + (rc.bottom - rc.top) / 2,
					getAngle(rc.right, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 4 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{
			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx, rc.bottom,
					getAngle(fx, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 5 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left), rc.bottom,
					getAngle(fx + (rc.right - rc.left), rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
	}
}

//void enemyManager::spread()
//{
//}
