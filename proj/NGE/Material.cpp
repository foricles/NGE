#include "Material.h"

GLuint Material::count = 0;

Material::Material()
	: oShader(new Shader())
	, oWasCompile(false)
{
	oMaterialId = ++count;
}

Material::Material(const std::string &title)
	: Material()
{
	setTitle(title);
}

Material::~Material()
{
	delete oShader;
}

void Material::apply(const glm::mat4 &camMatrix)
{
	if (oWasCompile)
	{
		oShader->setUniformMatrix4("cameraMainMatrix", camMatrix);

		if (oUniformVaribles.empty()) return;

		for (auto uni = oUniformVaribles.begin(); uni != oUniformVaribles.end(); ++uni)
		{
			switch ((*uni)->type)
			{
			case MaterialAttrib::VECTOR:
			{
				UniformVector *vect = dynamic_cast<UniformVector*>(*uni);
				if (vect != nullptr)
				{
					switch (vect->varCount)
					{
					case 1: oShader->setUniformF(vect->uniformName, vect->var.x); break;
					case 2: oShader->setUniformF(vect->uniformName, vect->var.x, vect->var.y); break;
					case 3: oShader->setUniformF(vect->uniformName, vect->var.x, vect->var.y, vect->var.z); break;
					case 4: oShader->setUniformF(vect->uniformName, vect->var.x, vect->var.y, vect->var.z, vect->var.w); break;
					default:
						break;
					}
				}
				break;
			}
			case MaterialAttrib::MATRIX:
				{
					UniformMatrix4 *matx = dynamic_cast<UniformMatrix4*>(*uni);
					if (matx != nullptr)
					{
						oShader->setUniformMatrix4(matx->uniformName, matx->mtx);
					}
					break;
				}
			}
		}
	}
}

void Material::compile()
{
	if (!oWasCompile)
	{
		oShader->compile(oVertexPath, oFragmentPath);
		oShader->link();
		oWasCompile = true;
	}
}

void Material::setTitle(const std::string &title)
{
	oTitle = title;
}

void Material::setFragmentShader(const std::string &filePath)
{
	if (!oWasCompile)
		oFragmentPath = filePath;
}

void Material::setVertexShader(const std::string &filePath)
{
	if (!oWasCompile)
		oVertexPath = filePath;
}

void Material::addUniformAttibute(UniformAttribute * attribute)
{
	oUniformVaribles.push_back(attribute);
}

UniformAttribute * Material::getUniformAttribute(const std::string & attrib)
{
	for (auto att = oUniformVaribles.begin(); att != oUniformVaribles.end(); ++att)
		if ((*att)->uniformName == attrib)
			return (*att);
	return nullptr;
}
