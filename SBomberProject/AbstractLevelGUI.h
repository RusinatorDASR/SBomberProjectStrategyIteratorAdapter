#pragma once
#include <stdint.h>

#include "GameObject.h"

using namespace std;

class AbstractLevelGUI :
	public GameObject
{
public:
	virtual void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t
		bombsNumberNew, int16_t scoreNew) {};
	virtual void __fastcall SetHeight(uint16_t heightN) {};
	virtual uint16_t GetFinishX() const = 0;
	virtual void SetFinishX(uint16_t finishXN) = 0;
};

