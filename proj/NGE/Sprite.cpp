#include "Sprite.h"


Sprite::Sprite()
	: Sprite(new Material())
{
}

Sprite::Sprite(Material * material)
	: RenderObject()
	, oLeftTop(new vert())
	, oRightDown(new vert())
	, oTransform(new Transform())
	, oMaterial(material)
{
	oLeftTop->pos = glm::vec4(1.0, 1.0, 0.0, 1.0);
	oLeftTop->col = glm::vec4(1.0, 1.0, 1.0, 1.0);
	oLeftTop->uv = glm::vec2(1.0, 1.0);

	oRightDown->pos = glm::vec4(-1.0, -1.0, 0.0, 1.0);
	oRightDown->col = glm::vec4(1.0, 1.0, 1.0, 1.0);
	oRightDown->uv = glm::vec2(0.0, 0.0);

	setName("Sprite" + std::to_string(getObjectId()));
	setTag("Sprite");
	setLayer("Tefault");
	setActive(true);
}

Sprite::~Sprite()
{
	delete oLeftTop;
	delete oRightDown;
	delete oTransform;
}

void Sprite::setTransform(const Transform & tra)
{
	*oTransform = tra;
}

Transform & Sprite::transform()
{
	return (*oTransform);
}

Material * Sprite::getMaterial()
{
	return oMaterial;
}

void Sprite::setMaterial(Material *mat, bool clr)
{
	if(clr)
		delete oMaterial;
	oMaterial = mat;
}

vert Sprite::leftTop()
{
	vert out = (*oLeftTop);
	out.pos = oTransform->getMatrix() * out.pos;
	return out;
}

vert Sprite::rightDown()
{
	vert out = (*oRightDown);
	out.pos = oTransform->getMatrix() * out.pos;
	return out;
}
