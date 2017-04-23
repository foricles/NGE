#include "Window.h"



EWindow::EWindow()
	:EWindow("NGE v0.1", 640, 480, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED)
{
}

EWindow::EWindow(const std::string name, int wi, int he, int posx, int posy)
	: ESystem(SysType::WINDOW)
	, oTitle(name)
	, oWndWidth(wi)
	, oWndHeigth(he)
	, oWndPosX(posx)
	, oWndPosY(posy)
	, oWndFullScr(false)
	, oSDLWindow(nullptr)
	, oGLContext(nullptr)
	, oWndFlag(SDL_WINDOW_OPENGL)
{
}


EWindow::~EWindow()
{
}

inline SDL_GLContext EWindow::getGLContext()
{
	return oGLContext;
}

inline Uint32 EWindow::getFlag()
{
	return oWndFlag;
}

inline std::string & EWindow::getTitle()
{
	return oTitle;
}

inline bool EWindow::isFullScr()
{
	return oWndFullScr;
}

void EWindow::updateBuffer()
{
	SDL_GL_SwapWindow(oSDLWindow);
}

int EWindow::getWidth()
{
	return oWndWidth;
}
int EWindow::getHeigth()
{
	return oWndHeigth;
}
int EWindow::getPosX()
{
	return oWndPosX;
}
int EWindow::getPosY()
{
	return oWndPosY;
}

bool EWindow::initialize()
{
	const char *title = oTitle.c_str();
	oSDLWindow = SDL_CreateWindow(title, oWndPosX, oWndPosY, oWndWidth, oWndHeigth, oWndFlag);
	if (oSDLWindow == nullptr)
	{
		Logger::fatalError("Window could not been created.");
		return false;
	}

	oGLContext = SDL_GL_CreateContext(oSDLWindow);
	if (oGLContext == nullptr)
	{
		Logger::fatalError("Window could not been created.");
		return false;
	}

	return true;
}

bool EWindow::reset()
{
	return false;
}

bool EWindow::update(GameState *state)
{
	return true;
}
