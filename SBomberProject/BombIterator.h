#pragma once
#include <vector>

#include "SBomber.h"

class BombIterator
{
	vector<Bomb*> refVecBombs;
	size_t curIndex;
	Bomb **ptr;
public:
	BombIterator() {}
	BombIterator(vector<Bomb*>& vecBombs) : refVecBombs(vecBombs), curIndex(-1), ptr(nullptr) { ++(*this); }
	void reset();
	BombIterator& operator++ ();
	BombIterator& operator-- ();
	Bomb* operator*();
	bool operator==(BombIterator it);
	bool operator!=(BombIterator it);
	vector<Bomb*> FindAllBombs(vector<DynamicObject*>& vecDynamicObj);
};

