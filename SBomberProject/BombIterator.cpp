#include "BombIterator.h"

void BombIterator::reset() { curIndex = -1; ptr = nullptr; }

BombIterator& BombIterator::operator++ () // префиксный инкремент
{
	curIndex++;
	if (curIndex == -1)
		curIndex = 0;
	for (; curIndex < refVecBombs.size(); curIndex++)
	{
		ptr = &refVecBombs[curIndex];
		break;
	}
	if (curIndex == refVecBombs.size())
	{
		curIndex = -1;
		ptr = nullptr;
	}
	return *this;
}

BombIterator& BombIterator::operator-- () // префексный декремент
{
	if (curIndex == -1)
		curIndex = refVecBombs.size() - 1;
	for (; curIndex >= 0; curIndex--)
	{
		ptr = &refVecBombs[curIndex];
		break;
	}
	if (curIndex == -1)
	{
		ptr = nullptr;
	}
	return *this;
}

Bomb* BombIterator::operator*() // операция разыменования итератора
{
	return refVecBombs[curIndex];
}

bool BombIterator::operator==(BombIterator it) // проверка на лог. равенство итераторов
{
	if (curIndex == it.curIndex &&
		ptr == it.ptr &&
		refVecBombs == it.refVecBombs)
	{
		return true;
	}
	return false;
}

bool BombIterator::operator!=(BombIterator it) // проверка на лог. неравенство
{
	return !(*this == it);
}

vector<Bomb*> BombIterator::FindAllBombs(vector<DynamicObject*>& vecDynamicObj)
{
	vector<Bomb*> vecBombs;

	for (size_t i = 0; i < vecDynamicObj.size(); i++)
	{
		Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj[i]);
		if (pBomb != nullptr)
		{
			vecBombs.push_back(pBomb);
		}
	}

	return vecBombs;
}


