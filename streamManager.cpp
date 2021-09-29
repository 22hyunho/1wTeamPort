#include "stdafx.h"
#include "streamManager.h"


streamManager::streamManager()
{
}


streamManager::~streamManager()
{
}

HRESULT streamManager::init(void)
{
	addVideo("title", "video/title.wmv");

	return S_OK;
}

void streamManager::release()
{
	findVideo("title")->deletVideo();
	_mapVideoList.erase("title");
}

video* streamManager::addVideo(string strKey, const char * fileName)
{
	video* _video = findVideo(strKey);
	if (_video) return _video;
	_video = new video;
	//_video->setVideo(fileName);
	if (FAILED(_video->setVideo(fileName)))
	{
		SAFE_DELETE(_video);

		return nullptr;
	}

	_mapVideoList.insert(make_pair(strKey, _video));

	return _video;

}

void streamManager::startVideo(string strKey)
{
	video* _video = findVideo(strKey);
	for (mapVideoIter iter = _mapVideoList.begin(); iter != _mapVideoList.end(); iter++)
	{
		if (_video != iter->second)
			iter->second->closeVideo();

	}
	_video->playVideo();
}

void streamManager::closeVideo(string strKey)
{
	video* _video = findVideo(strKey);
	_video->closeVideo();
	//_video->deletVideo();
}

void streamManager::playVideo(string strKey)
{
	video* _video = findVideo(strKey);
	_video->playVideo();

}





video * streamManager::findVideo(string strKey)
{
	mapVideoIter key = _mapVideoList.find(strKey);

	if (key != _mapVideoList.end())
	{
		return key->second;
	}

	return nullptr;
}


