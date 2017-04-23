#include "MainGame.h"



EMainGame::EMainGame()
	: ESystem(SysType::GAMECLASS)
	, oGameName(nullptr)
{
	oGameName = new std::string("NGE game");
}


EMainGame::~EMainGame()
{
	delete oGameName;
}

void EMainGame::setGameName(const std::string & name)
{
	oGameName->assign(name);
}

std::string & EMainGame::getGameName() const
{
	return *oGameName;
}

EWindow * EMainGame::window()
{
	return dynamic_cast<EWindow*>(getSystem(SysType::WINDOW));
}

EInput * EMainGame::input()
{
	return dynamic_cast<EInput*>(getSystem(SysType::INPUT));
}

ETime * EMainGame::time()
{
	return dynamic_cast<ETime*>(getSystem(SysType::TIME));
}

GameObjectManager * EMainGame::gameObject()
{
	return dynamic_cast<GameObjectManager*>(getSystem(SysType::OBJMANAGER));;
}

void EMainGame::appSystems(std::map<SysType, ESystem*>* sys)
{
	setAppSystems(sys);
}


//-------------------------------------------------------
bool EMainGame::Initialize()
{
	return false;
}

void EMainGame::Begin()
{
}

void EMainGame::Update()
{
}

void EMainGame::PostUpdate()
{
}

void EMainGame::FixUpdate()
{
}

void EMainGame::End()
{
}
