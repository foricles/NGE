#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL.h>
#include <GLEW\glew.h>
#include <glm.hpp>

#include "System.h"

class EInput : public ESystem 
{
private:
	SDL_Event oEvent;

	glm::vec2 oMousePos;
public:
	EInput();
	~EInput();

	virtual inline glm::vec2 &getMousePos();

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;
};

#endif // !_INPUT_H_