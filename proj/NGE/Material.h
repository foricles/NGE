#ifndef _MATERIALS_H_
#define _MATERIALS_H_

#include <string>
#include <vector>

#include "Structs.h"
#include "Shader.h"

class Material
{
public:
	Material();
	Material(const std::string &title);
	~Material();

	void apply(const glm::mat4 &camMatrix);
	void compile();

	void setTitle(const std::string &title);
	void setFragmentShader(const std::string &filePath);
	void setVertexShader(const std::string &filePath);
	void addUniformAttibute(UniformAttribute* attribute);
	UniformAttribute *getUniformAttribute(const std::string &attrib);

	inline Shader *getMaterialShader(){
		return oShader;
	}
private:
	static GLuint count;

	bool oWasCompile;

	GLuint oMaterialId;
	std::string oTitle;
	std::vector<UniformAttribute*> oUniformVaribles;

	Shader *oShader;

	std::string oVertexPath;
	std::string oFragmentPath;
};

#endif //_MATERIALS_H_