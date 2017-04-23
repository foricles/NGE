#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include <vector>
#include <algorithm>

#include "System.h"
#include "Sprite.h"

class GameObjectManager : public ESystem
{
private:
	std::vector<RenderObject*> oGameObjects;
public:
	GameObjectManager();
	~GameObjectManager();

	virtual std::vector<RenderObject*>::iterator begin();
	virtual std::vector<RenderObject*>::iterator end();

	virtual RenderObject *getObjectByName(const std::string name);
	virtual RenderObject *getObjectByTag(const std::string tag);
	virtual RenderObject *getObjectById(GLuint id);

	virtual int getSize() { return oGameObjects.size(); }

	virtual Sprite *createSprite();

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;
};


#endif //_GAMEOBJECTMANAGER_H_