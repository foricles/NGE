#include "Application.h"


Application::Application()
	: oGameState(GameState::RUN)
	, oMainGameClass(nullptr)
{
}


Application::~Application()
{
	for (register auto sys = oSystems.begin(); sys != oSystems.end(); sys++)
		delete sys->second;
}

bool Application::init()
{
	bool ok = true;

	// SDL initialization
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		Logger::Log("SDL init success.");
	else 
		Logger::fatalError("SDL could not been init.");

	oSystems.insert(std::pair<SysType, ESystem*>(SysType::WINDOW, new EWindow()));
	oSystems.insert(std::pair<SysType, ESystem*>(SysType::INPUT,  new EInput()));
	oSystems.insert(std::pair<SysType, ESystem*>(SysType::TIME, new ETime()));
	oSystems.insert(std::pair<SysType, ESystem*>(SysType::OBJMANAGER, new GameObjectManager()));
	oSystems.insert(std::pair<SysType, ESystem*>(SysType::RENDER, new ERender2D()));

	for (register auto sys = oSystems.begin(); sys != oSystems.end(); sys++)
	{
		sys->second->setAppSystems(&oSystems);
		sys->second->initialize();
	}
	
	oMainGameClass->appSystems(&oSystems);

	return ok;
}

GLuint Application::mainloop()
{
	if (oMainGameClass == nullptr)
	{
		oGameState = GameState::QUIT;
		Logger::fatalError("Game class is not exist!");
		return 1;
	}

	if (!init())
	{
		oGameState = GameState::QUIT;
		return 2;
	}

	oMainGameClass->Initialize();

	oMainGameClass->Begin();
	while (oGameState != GameState::QUIT)
	{
		oMainGameClass->Update();
		for (register auto sys = oSystems.begin(); sys != oSystems.end(); sys++)
			sys->second->update(&oGameState);
		oMainGameClass->PostUpdate();
	} 
	oMainGameClass->End();

	return 0;
}

GLuint Application::run()
{
	return mainloop();
}

void Application::setGameClass(EMainGame * mainGame)
{
	oMainGameClass = mainGame;
}
