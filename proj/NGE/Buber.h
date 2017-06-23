#pragma once
#include "MainGame.h"
#include "Logger.h"
#include <time.h>

class Buber : public EMainGame
{
private:
	UniformVector *vr;
	Sprite		  *sp;
public:
	Buber() 
	{
		srand(time(NULL));
	}
	~Buber() {}

	inline void createGrid()
	{
		int N = 26 * 20;
		float dx = 10;
		float dy = 10;
		int c(0);
		for (register int i(0); i < N; i++)
		{
			sp = gameObject()->createSprite();
			sp->transform().translate(dx, dy);
			sp->transform().scale(10, 10);
			if (i % ((rand()%5)+1) == 0)
				sp->setMaterial(gameObject()->getMaterialAt(1));
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
	inline void createBig()
	{
		for (register int i(0); i < 100; ++i)
		{
			sp = gameObject()->createSprite();
			sp->transform().translate(250, 250);
			sp->transform().scale(200, 200);
		}
	}

	bool Initialize() override
	{
		setGameName("Buber game");
		vr = new UniformVector();
		vr->uniformName = "lightPos";
		vr->varCount = 2;

		Material *mat = nullptr;
		mat = gameObject()->createMaterial();
		mat->setFragmentShader("Shaders/f_blue.fdr");

		gameObject()->getMaterialAt(0)->addUniformAttibute(vr);
		return true;
	}
	void Begin() override
	{
		createGrid();
		//createBig();
	}
	void Update() override
	{
		static double i(0.0);

		if (i >= 5)
		{
			Logger::Log(std::to_string(Time()->fps()));
			i = 0.0;
		}
		vr->var = glm::vec4(Input()->getMousePos().x, Window()->getHeigth() - Input()->getMousePos().y, 0, 0);
		i += Time()->delaTime();
	}
	void End() override
	{
		Logger::Log("end");
	}
};

