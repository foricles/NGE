#pragma once

#include <GLEW\glew.h>
#include <string>
#include <fstream>
#include <vector>
#include <glm.hpp>

#include "Logger.h"

class Shader
{
private:
	int oCountAttrib;

	GLuint oShaderID;

	GLuint oVertexID;
	GLuint oFragmentID;


	inline void compileShader(const std::string &path, GLuint &ID);
	inline GLuint getUniformVar(const std::string &var);
public:
	Shader();
	~Shader();

	virtual inline void use();
	virtual inline void unuse();
	
	virtual inline void compile(const std::string &vertexPath, const std::string &fragPath);
	virtual inline void link();
	//Атрибут (Attribute) - это данные, передаваемые программой вершинному шейдеру (другим шейдерам данные не доступны)
	virtual inline void addAttrib(const std::string &attrib);
	
	virtual inline void setUniformF(const std::string &name, float n);
	virtual inline void setUniformF(const std::string &name, float x, float y);
	virtual inline void setUniformF(const std::string &name, float x, float y, float z);
	virtual inline void setUniformF(const std::string &name, float x, float y, float z, float w);
	virtual inline void setUniformMatrix4(const std::string &name, const glm::mat4 &matrix);
};

