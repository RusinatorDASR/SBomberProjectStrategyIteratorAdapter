#include <iostream>

#include "LevelGUI_2.h"
#include "ScreenSingleton.h"

using namespace std;

void LevelGUI_2::Draw() const
{
	ScreenSingleton::getInstance().SetColor(CC_Cyan);

	ScreenSingleton::getInstance().GotoXY(x, y);
	char* buf = new (nothrow) char[width + 1];
	if (buf == nullptr)
	{
		return;
	}
	memset(buf, '*', width);
	buf[width] = '\0';
	cout << buf;
	ScreenSingleton::getInstance().GotoXY(x, y + height);
	cout << buf;
	delete[] buf;
	buf = nullptr;

	for (size_t i = size_t(y); i < height + y; i++)
	{
		ScreenSingleton::getInstance().GotoXY(x, (double)i);
		cout << "*";
		ScreenSingleton::getInstance().GotoXY(x + width - 1, (double)i);
		cout << "*";
	}

	ScreenSingleton::getInstance().GotoXY(3, 1);
	cout << "Kadrov_v_Sekundu: " << static_cast<int>(fps / (passedTime / 1000.0));
	ScreenSingleton::getInstance().GotoXY(25, 1);
	cout << "Proshlo_vremya: " << static_cast<int>(passedTime / 1000.0) << " sec";
	ScreenSingleton::getInstance().GotoXY(48, 1);
	cout << "Kol-vo_Bomb: " << bombsNumber;
	ScreenSingleton::getInstance().GotoXY(64, 1);
	cout << "Schet: " << score;
}

void __fastcall LevelGUI_2::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
	passedTime = passedTimeNew;
	fps = fpsNew;
	bombsNumber = bombsNumberNew;
	score = scoreNew;
}


