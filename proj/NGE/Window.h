#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "System.h"

#include <GLEW\glew.h>
#include <SDL.h>
#include <string>


class EWindow : public ESystem
{
private:
	int oWndWidth;
	int oWndHeigth;
	int oWndPosX;
	int oWndPosY;
	std::string oTitle;

	bool oWndFullScr;

	SDL_Window *oSDLWindow;
	SDL_GLContext oGLContext;
	Uint32 oWndFlag;
public:
	EWindow();
	EWindow(const std::string name, int wi, int he, int posx = SDL_WINDOWPOS_CENTERED, int posy = SDL_WINDOWPOS_CENTERED);
	~EWindow();

	virtual SDL_GLContext getGLContext();
	virtual Uint32 getFlag();
	virtual std::string &getTitle();
	virtual bool isFullScr();
	virtual void updateBuffer();

	virtual int getWidth();
	virtual int getHeigth();
	virtual int getPosX();
	virtual int getPosY();

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;
};

#endif // !_WINDOW_H_