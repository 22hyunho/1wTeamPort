#include "stdafx.h"
#include "stateManager.h"
#include "Player.h"
#include "State.h"
#include "Idle.h"
#include "Run.h"
#include "Slash.h"
#include "Charging.h"
#include "ChargeAttack.h"
#include "Carry.h"
#include "Throw.h"
#include "Push.h"
#include "InvenOpen.h"
#include "Stun.h"
#include "UseItem.h"

Player* stateManager::_player = NULL;
State* stateManager::_currentState = NULL;
State* stateManager::_prevState = NULL;

HRESULT stateManager::init(Player * player)
{
	_player = player;
	_prevState = _currentState = NULL;

	addState(IDLE, new Idle);
	addState(RUN, new Run);
	addState(SLASH, new Slash);
	addState(CHARGING, new Charging);
	addState(CHARGEATTACK, new ChargeAttack);
	addState(CARRY, new Carry);
	addState(THROW, new Throw);
	addState(PUSH, new Push);
	addState(INVENOPEN, new InvenOpen);
	addState(STUN, new Stun);
	addState(USEITEM, new UseItem);

	/**** ป๓ลย ****/
	changeState(IDLE);
	return S_OK;
}

void stateManager::release()
{
	stateIter istateList = _stateList.begin();

	for (; istateList != _stateList.end();)
	{
		if (istateList->second != NULL)
		{
			if (istateList->second == _currentState) istateList->second->release();
			SAFE_DELETE(istateList->second);
			istateList = _stateList.erase(istateList);
		}
		else ++istateList;
	}

	_stateList.clear();
}

void stateManager::update()
{
	if (_currentState) _currentState->update();
}

void stateManager::render(HDC hdc)
{
	if (_currentState) _currentState->render(hdc);
}

State * stateManager::addState(int stateNum, State * state)
{
	if (!state) return nullptr;

	_stateList.insert(make_pair(stateNum, state));

	return state;
}

HRESULT stateManager::changeState(int state)
{
	stateIter find = _stateList.find(state);

	if (find == _stateList.end()) return E_FAIL;

	if (find->second == _currentState) return S_OK;

	if (SUCCEEDED(find->second->init(_player))) {
		if (_currentState) _currentState->release();

		_prevState = _currentState;
		_currentState = find->second;

		//TIMEMANAGER->endTimer();

		return S_OK;
	}

	return E_FAIL;
}
