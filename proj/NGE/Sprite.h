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
	~Sprite();

	inline void setTransform(const Transform &tra);
	Transform &transform();
	Material *getMaterial()const;

	vert leftTop();
	vert rightDown();
};

#endif //_SPRITE_H_