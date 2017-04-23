#ifndef _GAMESTRUCTS_H_
#define _GAMESTRUCTS_H_

#include <GLEW\glew.h>
#include <exception>
#include <glm.hpp>

#include "Logger.h"
#include "transform.h"
#include "SysEnumers.h"

struct vert
{
	glm::vec4 pos;
	glm::vec4 col;
	glm::vec2 uv;

	vert(){
		col.r = 1.0f;
		col.g = 0.0f;
		col.b = 0.8703f;
		col.a = 1.0f;
	}
};

struct textr
{
	GLuint id;
	GLuint width;
	GLuint height;
};

class UniformAttribute
{
public:
	std::string uniformName;
	MaterialAttrib type;
	UniformAttribute() {}
	virtual ~UniformAttribute() {}
};

class UniformVector : public UniformAttribute
{
public:
	GLuint varCount;
	glm::vec4 var;
	UniformVector() {
		type = MaterialAttrib::VECTOR;
	}
};

class UniformMatrix4 : public UniformAttribute
{
public:
	glm::mat4 mtx;
	UniformMatrix4() {
		type = MaterialAttrib::MATRIX;
	}
};

#endif // !_GAMESTRUCTS_H_
