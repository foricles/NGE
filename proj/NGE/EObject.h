#ifndef _EOBJECT_
#define _EOBJECT_

#include <GLEW\glew.h>

class EObject
{
public:
	EObject();
	~EObject();

	inline GLuint getObjectId();
private:
	static GLuint oCounter;

	GLuint oObjId;
};

#endif // !_EOBJECT_