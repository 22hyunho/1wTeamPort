#pragma once
#include "singletonBase.h"
#include <vector>
#include <string>

#define TEXTSIZE	40

class txtData : public singletonBase<txtData>
{
private:
	image* _textBackground;
	float _x, _y;
	RECT _body;

	vector<string>		_vText;
	image* _textImg;

	int _row;
	int _count;

public:
	txtData();
	~txtData();

	HRESULT init();
	HRESULT init(const char* fileName);
	void release();
	void update();
	void render(HDC hdc);

	//Save
	void txtSave(const char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);

	//Load
	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);
};