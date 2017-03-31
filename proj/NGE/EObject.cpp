#include "EObject.h"

GLuint EObject::oCounter = 0;

EObject::EObject()
	: oObjId(oCounter++)
{
}


EObject::~EObject()
{
}

inline GLuint EObject::getObjectId(){
	return oObjId;
}
