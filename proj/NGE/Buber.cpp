#include "Buber.h"



Buber::Buber():EMainGame()
{
}


Buber::~Buber()
{
}

bool Buber::Initialize()
{
	setGameName("Buber game");
	return true;
}

void Buber::Begin()
{
	Logger::Log("begin");
	int N = 26*20;
	float dx = 10;
	float dy = 10;
	int c(0);
	for (int i(0); i < N; i++)
	{
		Sprite *sp = gameObject()->createSprite();
		sp->transform().scale(10, 10);
		sp->transform().translate(dx, dy);
		dx += 25;
		c += 1;
		if (c == 26)
		{
			dy += 25;
			c = 0;
			dx = 10;
		}
	}
}

void Buber::Update()
{
	//Logger::Log(std::to_string(time()->fps()));
}

void Buber::End()
{
	Logger::Log("end");
}
