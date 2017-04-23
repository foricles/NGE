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

	void use();
	void unuse();

	void compile(const std::string &vertexPath, const std::string &fragPath);
	void link();
	//Атрибут (Attribute) - это данные, передаваемые программой вершинному шейдеру (другим шейдерам данные не доступны)
	void addAttrib(const std::string &attrib);

	void setUniformF(const std::string &name, float n);
	void setUniformF(const std::string &name, float x, float y);
	void setUniformF(const std::string &name, float x, float y, float z);
	void setUniformF(const std::string &name, float x, float y, float z, float w);
	void setUniformMatrix4(const std::string &name, const glm::mat4 &matrix);
};

