#pragma once
#include "gameNode.h"
#include "boss.h"
#include <vector>

struct tagFire
{
	image* _fireImage;		//총알 이미지 
	RECT _rc;				//총알 렉트
	float _x, _y;				//총알 좌표(실시간)
	float _angle;			//총알 각도
	float _radius;			//총알 반지름
	float _speed;			//총알 스피드
	float _dmg;
	float _fireX, _fireY;		//총알 발사시 처음 좌표(발사된 좌표)
	bool _isFire;
	int _count;				//총알 프레임카운트용
};
struct tagCircul
{
	image* _circulImage;		//총알 이미지 
	RECT _rc;				//총알 렉트
	float _x, _y;				//총알 좌표(실시간)
	float _angle;			//총알 각도
	float _radius;			//총알 반지름
	float _speed;			//총알 스피드
	float _dmg;
	float _fireX, _fireY;		//총알 발사시 처음 좌표(발사된 좌표)
	bool _isFire;
	int _count;				//총알 프레임카운트용
};
struct tagSpread
{
	image* _spreadImage;		//총알 이미지 
	RECT _rc;				//총알 렉트
	float _x, _y;				//총알 좌표(실시간)
	float _angle;			//총알 각도
	float _radius;			//총알 반지름
	float _speed;			//총알 스피드
	float _dmg;
	float _fireX, _fireY;		//총알 발사시 처음 좌표(발사된 좌표)
	bool _isFire;
	int _count;				//총알 프레임카운트용
	int indexY;
};
class fireball : public gameNode
{
private:
	vector<tagFire>				 _vFire;
	vector<tagFire>::iterator	 _viFire;

	float _range;
	int _fireMax;
	int _indexY;
	boss* _boss;
public:
	fireball() {};
	~fireball() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();

	void setIndexY(int IndexY) { _indexY = IndexY; }
	int getIndexY() { return _indexY; }
	//총알을 지워달라고 소통하는 함수
	void removeBullet(int arrNum);



	vector<tagFire> getVFire() { return _vFire; }
	vector<tagFire>::iterator getViFire() { return _viFire; }

};

class circulator : public gameNode
{
private:
	vector<tagCircul>				 _vCircul;
	vector<tagCircul>::iterator		_viCircul;

	vector<tagSpread>				 _vSpread;
	vector<tagSpread>::iterator		_viSpread;

	float _range;
	int _fireMax;
	int _index=0;
	int _spreadMax;
	int _indexs = 0;
	float innerX;
	float innerY;
	
	boss* _boss;
	
public:
	circulator() {};
	~circulator() {};

	HRESULT init(int bulletMax,int spreadMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);
	void spreadfire(float x, float y, float angle, float speed, int indexY);

	void move();


	//총알을 지워달라고 소통하는 함수
	void removeBullet(int arrNum);
	void removeSpread(int arrNum);



	vector<tagCircul> getVCir() { return _vCircul; }
	vector<tagCircul>::iterator getViCir() { return _viCircul; }
	vector<tagSpread> getVSpread() { return _vSpread; }
	vector<tagSpread>::iterator getViSpread() { return _viSpread; }

};

//class thunder :public gameNode
//{
//private:
//	
//
//	float _range;
//	int _fireMax;
//	int _indexY;
//	boss* _boss;
//public:
//	thunder() {};
//	~thunder() {};
//
//	HRESULT init(int bulletMax, float range);
//	void release();
//	void update();
//	void render();
//
//	void fire(float x, float y, float angle, float speed);
//
//	void setIndexY(int IndexY) { _indexY = IndexY; }
//	int getIndexY() { return _indexY; }
//	//총알을 지워달라고 소통하는 함수
//	void removeBullet(int arrNum);
//
//
//
//	
//};

class magic
{
};

