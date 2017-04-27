#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "objkinds.h"
#include "Structs.h"
#include "Material.h"

class Sprite : public RenderObject
{
private:
	Material  *oMaterial;
	vert      *oLeftTop;
	vert      *oRightDown;
	Transform *oTransform;
public:
	Sprite();
	Sprite(Material *material);
	~Sprite();

	virtual inline void setTransform(const Transform &tra);
	virtual inline Transform &transform();
	virtual inline void setMaterial(Material *mat, bool clr = false);
	virtual inline Material *getMaterial();

	vert leftTop();
	vert rightDown();
};

#endif //_SPRITE_H_