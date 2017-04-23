#include "GameObjectManager.h"


GameObjectManager::GameObjectManager()
	: ESystem(SysType::OBJMANAGER)
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto obj = oGameObjects.begin(); obj != oGameObjects.end(); ++obj)
		delete (*obj);
	oGameObjects.clear();
}

std::vector<RenderObject*>::iterator GameObjectManager::begin()
{
	return oGameObjects.begin();
}
std::vector<RenderObject*>::iterator GameObjectManager::end()
{
	return oGameObjects.end();
}

RenderObject * GameObjectManager::getObjectByName(const std::string name)
{
	for(auto obj = oGameObjects.begin(); obj != oGameObjects.end(); ++obj)
		if(((*obj)->getName() == name) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}
RenderObject * GameObjectManager::getObjectByTag(const std::string tag)
{
	for(auto obj = oGameObjects.begin(); obj != oGameObjects.end(); ++obj)
		if(((*obj)->getTag() == tag) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}
RenderObject * GameObjectManager::getObjectById(GLuint id)
{
	for(auto obj = oGameObjects.begin(); obj != oGameObjects.end(); ++obj)
		if(((*obj)->getObjectId() == id) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}

Sprite * GameObjectManager::createSprite()
{
	Sprite *sprite = nullptr;
	for(auto obj = oGameObjects.begin(); obj != oGameObjects.end(); ++obj)
		if(!(*obj)->activeSelf())
			sprite = dynamic_cast<Sprite*>(*obj);

	if(sprite == nullptr)
	{
		sprite = new Sprite();
		oGameObjects.push_back(sprite);
	}
	return sprite;
}

bool GameObjectManager::initialize()
{
	return false;
}
bool GameObjectManager::reset()
{
	return false;
}
bool GameObjectManager::update(GameState * state)
{
	return false;
}
