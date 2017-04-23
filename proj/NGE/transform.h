#ifndef _TRANSF_H_
#define _TRANSF_H_

#include <GLEW\glew.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include "Logger.h"

struct Transform
{
public:
	Transform();
	void apply();
	const glm::mat4 &getMatrix() const;
	const glm::vec3 &getPosition() const;
	const glm::vec3 &getScale() const;

	void operator=(const Transform &tr);

	void translate(GLfloat x, GLfloat y);
	void translate(GLfloat x, GLfloat y, GLfloat z);
	void translate(const glm::vec2 &vec);
	void translate(const glm::vec3 &vec);

	void scale(GLfloat x, GLfloat y);
	void scale(GLfloat x, GLfloat y, GLfloat z);
	void scale(const glm::vec2 &vec);
	void scale(const glm::vec3 &vec);

	void rotate(GLfloat angle, GLfloat x, GLfloat y);
	void rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z = 0);
	void rotate(GLfloat angle, const glm::vec2 &vec);
	void rotate(GLfloat angle, const glm::vec3 &vec);
private:
	glm::mat4 trmtx;
	glm::vec3 oPos;
	glm::vec3 oScl;
	bool posIsChange;
	bool scaIsChange;
};

#endif //_TRANSF_H_