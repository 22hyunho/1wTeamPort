#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class enemy;
class item;

class collisionManager : public singletonBase<collisionManager>
{
private:
	//플레이어
	Player* _player;
	Scene* _scene;

	int _state;

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Player* player);
	HRESULT init(Scene* scene);
	void release();

	//플레이어 충돌
	void collisionPlayer();
	void playerWithTile();
	void playerWithEnemy(enemy* Enemy);

	//플레이어 상호작용
	void interactPlayer();

	//에너미 충돌
	void collisionEnemy(enemy* Enemy);
	void enemyWithTile(enemy* Enemy);
	void enemyWithPlayer(enemy* Enemy);

	//아이템 충돌
	void collisionItem(item* Item);
	void itemWithPlayer(item* Item);
};
