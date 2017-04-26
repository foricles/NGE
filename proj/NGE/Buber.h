#pragma once
#include "MainGame.h"
#include "Logger.h"
#include <time.h>

class Buber : public EMainGame
{
private:
	UniformVector *vr;
	Sprite *sp;
public:
	Buber() 
	{
		srand(time(NULL));
	}
	~Buber() {}

	bool Initialize() override
	{
		setGameName("Buber game");
		return true;
	}
	void Begin() override
	{
		//lightPos
		Logger::Log("begin");

		vr = new UniformVector();
		vr->uniformName = "lightPos";
		vr->varCount = 2;

		int N = 26 * 20;
		float dx = 10;
		float dy = 10;
		int c(0);
		for (int i(0); i < N; i++)
		{
			sp = gameObject()->createSprite();
			sp->transform().translate(dx, dy);
			sp->transform().scale(10, 10);
			sp->getMaterial()->addUniformAttibute(vr);
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
	void Update() override
	{
		static int i(0);

		if (i%50 == 0)
			Logger::Log(std::to_string(Time()->fps()));
		if (i % 20 == 0)
			vr->var = glm::vec4(rand() % Window()->getWidth(), rand() % Window()->getHeigth(), 0, 0);

		if( ++i == 1000) i = 0;
	}
	void End() override
	{
		Logger::Log("end");
	}
};

