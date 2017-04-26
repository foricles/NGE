#include "Time.h"

ETime::ETime()
	: ESystem(SysType::TIME)
{
}

ETime::~ETime()
{
}

bool ETime::initialize()
{
	oFPS = 0.0;
	oFpsBuff = 0.0;
	oFpsCounter = 0;
	oDeltaTime = 0.0;
	oBeginTime = clock();
	oLastTime = oBeginTime;
	return true;
}

bool ETime::reset()
{
	return false;
}

bool ETime::update(GameState * state)
{
	oDeltaTime = ((clock() - oLastTime) / CLOCKS_PER_SEC);
	if (oFpsCounter >= 27)
	{
		oFPS = 1/(oFpsBuff / 27.0);
		oFpsCounter = 0;
		oFpsBuff = 0.0;
	}
	else
	{
		oFpsBuff += oDeltaTime;
		++oFpsCounter;
	}
	oLastTime = clock();
	return true;
}

double ETime::fps()
{
	return oFPS;
}

double ETime::delaTime()
{
	return oDeltaTime;
}

double ETime::rawTime()
{
	return (clock() - oBeginTime) / CLOCKS_PER_SEC;
}
