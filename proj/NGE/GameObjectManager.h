#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include <vector>
#include <algorithm>
#include <algorithm>

#include "System.h"
#include "Sprite.h"
#include "Material.h"

class GameObjectManager : public ESystem
{
private:
	std::vector<Sprite*> oGameSprites;
	std::vector<Material*> oMaterials;
	std::vector<Sprite*> oFreeSprites;
	static bool cmp(Sprite *a, Sprite *b);
public:
	GameObjectManager();
	~GameObjectManager();

	virtual inline std::vector<Sprite*>::iterator begin();
	virtual inline std::vector<Sprite*>::iterator end();
	
	virtual inline RenderObject *getObjectByName(const std::string &name);
	virtual inline RenderObject *getObjectByTag(const std::string &tag);
	virtual inline RenderObject *getObjectById(GLuint id);
	virtual inline RenderObject *getObjectAt(GLuint i);
	
	virtual inline Material *getMaterialByTitle(const std::string &name);
	virtual inline Material *getMaterialById(GLuint id);
	virtual inline Material *getMaterialAt(GLuint i);

	virtual inline int getSize() { return oGameSprites.size(); }

	virtual inline Sprite *createSprite();
	virtual inline void deleteSparite(Sprite *sprite);
	virtual inline Material *createMaterial();

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;
};


#endif //_GAMEOBJECTMANAGER_H_