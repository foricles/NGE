#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <GLEW\glew.h>
#include <SDL.h>
#include <map>

#include "Logger.h"
#include "MainGame.h"
#include "SysEnumers.h"

#include "Window.h"
#include "Input.h"
#include "Render2D.h"
#include "GameObjectManager.h"
#include "Time.h"

class Application
{
public:
	Application();
	~Application();
private:
	EMainGame *oMainGameClass;

	GameState oGameState;
	std::map<SysType, ESystem*> oSystems;

	GLuint mainloop();
public:
	void setGameClass(EMainGame *mainGame);

	bool init();
	GLuint run();
};

#endif // !_PROCESSOR_H_