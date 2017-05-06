#ifndef _RENDER2D_H_
#define _RENDER2D_H_

#include "Structs.h"

#include "Logger.h"
#include "System.h"
#include "Input.h"
#include "Window.h"
#include "GameObjectManager.h"

#include <SDL.h>
#include <GLEW\glew.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <string>
#include <time.h>
#include <thread>
#include <mutex>


class ERender2D : public ESystem
{
private:
	struct Multi
	{
		Material *material;
		std::vector<vert> oVertexes;
		Multi() : material(nullptr) {};
	};
	std::vector<Multi*> oRenderObjs;

	glm::vec4 oBackColor;
	const int MAX_SPRITE = 60000;
	const int MAX_VERTEX = MAX_SPRITE * 6;
public:
	ERender2D();
	virtual ~ERender2D();

	virtual inline void setBackgroundColor(const glm::vec4 color);
	virtual inline void setBackgroundColor(float r, float g, float b, float a = 1.0f);

	bool initialize() override;
	bool reset() override;
	bool update(GameState *state) override;
private:
	GLuint oIdVBO;
	GLuint oIdVAO;
	EWindow *oActiveWnd;
	GameObjectManager *oObjects;
	void begin();
	void end();
	glm::mat4 cam;
};

#endif // !_RENDER2D_H_

