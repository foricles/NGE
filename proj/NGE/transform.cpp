#include "transform.h"

Transform::Transform()
	: trmtx(nullptr)
	, oPos(nullptr)
{
	trmtx = new glm::mat4(1.0f);
	oPos = new glm::vec3(1.0f);
}

Transform::~Transform()
{
	delete trmtx;
	delete oPos;
}

const glm::mat4 & Transform::getMatrix() const
{
	return *trmtx;
}
const glm::vec3 & Transform::getPosition() const
{
	return *oPos;
}

void Transform::operator=(const Transform & tr)
{
	*trmtx = *tr.trmtx;
	*oPos = *tr.oPos;
}

void Transform::translate(const glm::vec3 & vec)
{
	*oPos += vec;
	*trmtx = glm::translate(*trmtx, *oPos);
}
#pragma region translate_overloaded_metods
void Transform::translate(GLfloat x, GLfloat y)
	{
		translate(x, y, 0);
	}
	void Transform::translate(GLfloat x, GLfloat y, GLfloat z)
	{
		translate(glm::vec3(x, y, z));
	}
	void Transform::translate(const glm::vec2 & vec)
	{
		translate(glm::vec3(vec.x, vec.y, 0));
	}
#pragma endregion

void Transform::scale(const glm::vec3 & vec)
{
	*trmtx = glm::scale(*trmtx, vec);
}
#pragma region scale_overloaded_metods
	void Transform::scale(GLfloat x, GLfloat y)
	{
		scale(x, y, 1.0);
	}
	void Transform::scale(GLfloat x, GLfloat y, GLfloat z)
	{
		scale(glm::vec3(x, y, z));
	}
	void Transform::scale(const glm::vec2 & vec)
	{
		scale(glm::vec3(vec.x, vec.y, 1.0));
	}
#pragma endregion

void Transform::rotate(GLfloat angle, const glm::vec3 & vec)
	{
		
	}
#pragma region rotate_overloaded_metods
	void Transform::rotate(GLfloat angle, GLfloat x, GLfloat y)
	{
		rotate(angle, x, y, 0);
	}
	void Transform::rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
	{
		rotate(angle, glm::vec3(x, y, z));
	}
	void Transform::rotate(GLfloat angle, const glm::vec2 & vec)
	{
		rotate(angle, glm::vec3(vec.x, vec.y, 0));
	}
#pragma endregion