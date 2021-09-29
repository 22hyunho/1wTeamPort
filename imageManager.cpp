#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init()
{
	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

image* imageManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//�ش� �̹����� ���࿡ ������ �׳� �� �̹����� ���
	if (img) return img;

	img = new image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, int width, int height, bool trans, COLORREF transColor, bool blend)
{

	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor, blend)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(int intKey, int width, int height)
{
	image* img = findImage(intKey);

	//�ش� �̹����� ���࿡ ������ �׳� �� �̹����� ���
	if (img) return img;

	img = new image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_tImageList.insert(make_pair(intKey, img));

	return img;
}

image * imageManager::addImage(int intKey, const char * fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(intKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_tImageList.insert(make_pair(intKey, img));

	return img;
}

image * imageManager::addImage(int intKey, const char * fileName, int width, int height, bool trans, COLORREF transColor, bool blend)
{
	image* img = findImage(intKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor, blend)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_tImageList.insert(make_pair(intKey, img));

	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor, bool blend)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;

	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor, blend)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::findImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//ã�Ҵ�!
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

image * imageManager::findImage(int intKey)
{
	tileImageIter key = _tImageList.find(intKey);

	//ã�Ҵ�!
	if (key != _tImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

BOOL imageManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteImage(int intKey)
{
	tileImageIter key = _tImageList.find(intKey);

	if (key != _tImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_tImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteAll()
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		//�������̳ʾȿ� �̹����� �ִٸ�
		if (iter->second != nullptr)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();



	tileImageIter titer = _tImageList.begin();

	for (; titer != _tImageList.end();)
	{
		//�������̳ʾȿ� �̹����� �ִٸ�
		if (titer->second != nullptr)
		{
			titer->second->release();
			SAFE_DELETE(titer->second);
			titer = _tImageList.erase(titer);
		}
		else ++titer;
	}

	_tImageList.clear();

	return false;
}