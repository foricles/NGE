#include "Input.h"



EInput::EInput() : ESystem(SysType::RENDER)
{
}


EInput::~EInput()
{
}

glm::vec2 & EInput::getMousePos() 
{
	return oMousePos;
}

bool EInput::initialize()
{
	return false;
}

bool EInput::reset()
{
	return false;
}

bool EInput::update(GameState *state)
{
	while (SDL_PollEvent(&oEvent))
	{
		switch (oEvent.type)
		{
			case SDL_QUIT: 
			{
				(*state) = GameState::QUIT;
				return true;
			}
			case SDL_MOUSEMOTION:
			{
				int x(0), y(0);
				SDL_GetMouseState(&x, &y);
				oMousePos.x = (float)x;
				oMousePos.y = (float)y;
				return true;
			}
		}
	}
	return false;
}
