#ifndef _MAINGAME_
#define _MAINGAME_

class MainGame
{
public:
	MainGame();
	virtual ~MainGame();

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