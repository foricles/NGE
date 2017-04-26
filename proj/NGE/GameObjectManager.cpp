#include "GameObjectManager.h"


GameObjectManager::GameObjectManager()
	: ESystem(SysType::OBJMANAGER)
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		delete (*obj);
	oGameSprites.clear();
}

std::vector<Sprite*>::iterator GameObjectManager::begin()
{
	return oGameSprites.begin();
}
std::vector<Sprite*>::iterator GameObjectManager::end()
{
	return oGameSprites.end();
}

RenderObject * GameObjectManager::getObjectByName(const std::string name)
{
	for(auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		if(((*obj)->getName() == name) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}
RenderObject * GameObjectManager::getObjectByTag(const std::string tag)
{
	for(auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		if(((*obj)->getTag() == tag) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}
RenderObject * GameObjectManager::getObjectById(GLuint id)
{
	for(auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		if(((*obj)->getObjectId() == id) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}

Sprite * GameObjectManager::createSprite()
{
	Sprite *sprite = nullptr;
	for(auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		if(!(*obj)->activeSelf())
			sprite = (*obj);

	if(sprite == nullptr)
	{
		sprite = new Sprite();
		oGameSprites.push_back(sprite);
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
