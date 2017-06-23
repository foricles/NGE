#include "GameObjectManager.h"


bool GameObjectManager::cmp(Sprite * a, Sprite * b)
{
	return (a->getMaterial()->getId() < b->getMaterial()->getId());
}

GameObjectManager::GameObjectManager()
	: ESystem(SysType::OBJMANAGER)
{
	oMaterials.push_back(new Material());
}

GameObjectManager::~GameObjectManager()
{
	for (auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		delete (*obj);
	oGameSprites.clear();
	for (auto mat = oMaterials.begin(); mat != oMaterials.end(); ++mat)
		delete (*mat);
	oMaterials.clear();
}

std::vector<Sprite*>::iterator GameObjectManager::begin()
{
	return oGameSprites.begin();
}
std::vector<Sprite*>::iterator GameObjectManager::end()
{
	return oGameSprites.end();
}

RenderObject * GameObjectManager::getObjectByName(const std::string &name)
{
	for(auto obj = oGameSprites.begin(); obj != oGameSprites.end(); ++obj)
		if(((*obj)->getName() == name) && (*obj)->activeSelf())
			return (*obj);
	return nullptr;
}
RenderObject * GameObjectManager::getObjectByTag(const std::string &tag)
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

RenderObject * GameObjectManager::getObjectAt(GLuint i)
{
	if((i < 0) && (i >= oGameSprites.size()))
		return nullptr;
	return oGameSprites[i];
}

Material * GameObjectManager::getMaterialByTitle(const std::string & name)
{
	for (auto obj = oMaterials.begin(); obj != oMaterials.end(); ++obj)
		if ((*obj)->getTitle() == name)
			return (*obj);
	return nullptr;
}

Material * GameObjectManager::getMaterialById(GLuint id)
{
	for (auto obj = oMaterials.begin(); obj != oMaterials.end(); ++obj)
		if ((*obj)->getId() == id)
			return (*obj);
	return nullptr;
}

Material * GameObjectManager::getMaterialAt(GLuint i)
{
	if ((i < 0) && (i >= oMaterials.size()))
		return nullptr;
	return oMaterials[i];
}

Sprite * GameObjectManager::createSprite()
{
	Sprite *sprite = nullptr;
	if(oFreeSprites.size() == 0)
	{
		sprite = new Sprite(oMaterials[0]);
		oGameSprites.push_back(sprite);
	}
	else
	{
		sprite = oFreeSprites.back();
		oFreeSprites.pop_back();
		oGameSprites.push_back(sprite);
	}
	std::stable_sort(oGameSprites.begin(), oGameSprites.end(), cmp);
	return sprite;
}

inline void GameObjectManager::deleteSparite(Sprite *sprite)
{
	if (sprite != nullptr)
		oFreeSprites.push_back(sprite);
}

Material * GameObjectManager::createMaterial()
{
	Material *material = new Material();
	oMaterials.push_back(material);
	return material;
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
