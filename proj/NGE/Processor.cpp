#include "Processor.h"

Processor *Processor::oInstance = nullptr;

Processor * Processor::getInst()
{
	if (oInstance != nullptr)
	{
		delete oInstance;
		oInstance = new Processor();
	}
	return oInstance;
}

Processor::Processor()
	: oQuit(true)
	, oMainGameClass(nullptr)
{
}


Processor::~Processor()
{
}

void Processor::mainloop()
{
	if (oMainGameClass == nullptr)
	{
		oQuit = false;
		Logger::fatalError("Game class is not exist!");
	}

	oMainGameClass->Initialize();

	oMainGameClass->Begin();
	while (!oQuit);
	{

	} 
	oMainGameClass->End();
}

void Processor::setGameClass(MainGame * mainGame)
{
}
