#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Logger.h"
#include "MainGame.h"

class Processor
{
public:
	static Processor *getInst();
private:
	static Processor *oInstance;
	Processor();
	~Processor();

	bool oQuit;
	MainGame *oMainGameClass;

	void mainloop();
public:
	void setGameClass(MainGame *mainGame);
};

#endif // !_PROCESSOR_