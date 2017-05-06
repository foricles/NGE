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

	virtual inline void apply(const glm::mat4 &camMatrix);
	virtual inline void compile();

	virtual inline void setTitle(const std::string &title);
	virtual inline void setFragmentShader(const std::string &filePath);
	virtual inline void setVertexShader(const std::string &filePath);
	virtual inline void addUniformAttibute(UniformAttribute* attribute);
	virtual inline UniformAttribute *getUniformAttribute(const std::string &attrib);

	virtual inline Shader *getMaterialShader(){
		return oShader;
	}
	virtual inline GLuint getId(){
		return oMaterialId;
	}
	virtual inline const std::string &getTitle() {
		return oTitle;
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