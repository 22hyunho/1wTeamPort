#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	//first - string
	//second - image*
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;

	typedef map<int, image*>				tileImageList;
	typedef map<int, image*>::iterator		tileImageIter;

private:
	mapImageList _mImageList;
	tileImageList _tImageList;

public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	image* addImage(string strKey, int width, int height);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor, bool blend);

	image* addImage(int intKey, int width, int height);
	image* addImage(int intKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(int intKey, const char* fileName, int width, int height, bool trans, COLORREF transColor, bool blend);

	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor, bool blend);

	image* findImage(string strKey);
	image* findImage(int intKey);

	BOOL deleteImage(string strKey);
	BOOL deleteImage(int intKey);

	BOOL deleteAll();
};