#ifndef _SYSENUMERS_H_
#define _SYSENUMERS_H_

enum class GameState
{
	RUN,
	PAUSE,
	QUIT
};

enum class SysType
{
	WINDOW,
	INPUT,
	RENDER,
	GAMECLASS,
	OBJMANAGER,
	TIME
};

enum class MaterialAttrib
{
	MATRIX,
	VECTOR,
	TEXTURE
};

#endif // !_SYSENUMERS_H_
