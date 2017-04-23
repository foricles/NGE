#pragma once
#include "MainGame.h"
#include "Logger.h"

class Buber : public EMainGame
{
private:

public:
	Buber();
	~Buber();

	bool Initialize() override;
	void Begin() override;
	void Update() override;
	void End() override;
};

