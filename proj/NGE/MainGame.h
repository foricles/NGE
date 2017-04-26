#ifndef _MAINGAME_
#define _MAINGAME_

#include <string>

#include "System.h"
#include "Window.h"
#include "Input.h"
#include "GameObjectManager.h"
#include "Time.h"

class EMainGame : private ESystem
{
private:
	std::string *oGameName;	

	bool initialize() { return false; };
	bool reset() { return false; };
	bool update(GameState *state) { return false; };
public:
	EMainGame();
	virtual ~EMainGame();

	void setGameName(const std::string &name);
	std::string &getGameName()const;

	EWindow *Window();
	EInput *Input();
	ETime *Time();
	GameObjectManager *gameObject();
	
	void appSystems(std::map<SysType, ESystem*> *sys);
//--------------------------------------------------------
	// Initialize game
	virtual bool Initialize();

	// Call on start game after Initialize()
	virtual void Begin();
	// Call before apdate frame
	virtual void Update();
	// Call after draw frame
	virtual void PostUpdate();
	// Call on fixed time
	virtual void FixUpdate();
	// Call before close
	virtual void End();
};

#endif // !_MAINGAME_