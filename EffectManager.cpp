#include "stdafx.h"
#include "EffectManager.h"

HRESULT EffectManager::init()
{
	return S_OK;
}

void EffectManager::release()
{
}

void EffectManager::update()
{
}

void EffectManager::render()
{
}

void EffectManager::setSlash(float x, float y)
{
	_slash = new E_Slash;
	_slash->init(x, y);
}

void EffectManager::setChargeAttack(float x, float y)
{
	_cgAttack = new E_CgAttack;
	_cgAttack->init(x, y);
}


