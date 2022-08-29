#pragma once

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"


class TankAdapter :
	public DestroyableGroundObject
{
	TankAdaptee tank;
public:
	TankAdapter() : tank() {}
	void SetPos(double nx, double ny);
	uint16_t GetWidth() const override;
	void SetWidth(uint16_t widthN);
	void Draw() const override;
	bool __fastcall isInside(double x1, double x2) const override;
	uint16_t GetScore() const;
	double GetY() const;
	double GetX() const;
};
