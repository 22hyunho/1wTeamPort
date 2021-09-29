#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{
}

HRESULT txtData::init()
{
	//_textBackground= IMAGEMANAGER->addImage()
	//x, y, body 설정

	return S_OK;
}

HRESULT txtData::init(const char * fileName)
{
	_vText = txtLoad(fileName);

	if (_textImg) {
		_textImg->release();
		SAFE_DELETE(_textImg);
	}

	_textImg = new image;
	_textImg->init("img/dialog/text.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_row = 0;
	_count = 0;

	return S_OK;
}

void txtData::release()
{
}

void txtData::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		_count = 0;

	if (_count < 3){
		_count++;
		_row++;
	}
}

void txtData::render(HDC hdc)
{
	if (_row >= _vText.size()) return;

	HDC txtDC = _textImg->getMemDC();
	SetBkMode(txtDC, TRANSPARENT);
	SetTextColor(txtDC, RGB(255, 255, 255));

	HFONT font, oldFont;
	/*
	CreateFont(
			40,					문자폭
			0,					문자 넓이
			40,					문자 기울기
			0,					문자 방향
			600,				문자 굵기
			0,					bool 문자 기울기(이탤릭체)
			0,					bool 문자 밑줄
			0,					bool 문자 취소선
			HANGUL_CHARSET,		문자 셋팅
			0,					출력 정확도
			0,					클리핑 정확도
			0,					출력 퀄리티
			0,					자간
			TEXT("궁서체")
	);
	*/
	font = CreateFont(TEXTSIZE, 0, 0, 0, 100, false, false, false, HANGUL_CHARSET,
		0, 0, 0, 0, TEXT("HY견고딕"));
	oldFont = (HFONT)SelectObject(txtDC, font);

	TextOut(txtDC, 20, 20 + TEXTSIZE * _row, _vText[_row].c_str(), strlen(_vText[_row].c_str()));

	RECT rc = CAMERAMANAGER->getScreen();
	_textImg->render(hdc, rc.left + 200, rc.top + 600, 0, 20 + TEXTSIZE * (_row / 3),
		400, TEXTSIZE * 3);

	char str[128];
	sprintf_s(str, "row : %d", _row);
	TextOut(hdc, rc.left + 100, rc.top + 600, str, strlen(str));

	DeleteObject(font);
}

void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[128];

	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	char str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		if (i + 1 < vArray.size()) strcat_s(str, ",");
	}

	return str;
}

vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	DWORD read;

	char str[1024];

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 1024, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;
	char* temp;
	const char* separator = "\n";
	char* token;

	token = strtok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
