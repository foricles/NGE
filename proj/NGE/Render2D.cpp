#include "Render2D.h"

ERender2D::ERender2D()
	: ESystem(SysType::RENDER)
	, oBackColor(0.0, 0.0, 0.0, 1)
	, oActiveWnd(nullptr)
	, oObjects(nullptr)
	, oIdVBO(0)
	, oIdVAO(0)
{
}

ERender2D::~ERender2D()
{
}

void ERender2D::setBackgroundColor(float r, float g, float b, float a)
{
	oBackColor.r = r;
	oBackColor.g = g;
	oBackColor.b = b;
	oBackColor.a = a;
}
void ERender2D::setBackgroundColor(const glm::vec4 color)
{
	setBackgroundColor(color.r, color.g, color.b, color.a);
}

void ERender2D::begin()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(oBackColor.r , oBackColor.g, oBackColor.b, oBackColor.a);
}

void ERender2D::end()
{
	for (auto pie = oRenderObjs.begin(); pie != oRenderObjs.end(); ++pie)
		delete (*pie);
	oRenderObjs.clear();
	oActiveWnd->updateBuffer();
}

bool ERender2D::initialize()
{
	bool ok = true;
	if (glewInit() != GLEW_OK)
	{
		Logger::fatalError("GLEW could not be created");
		ok = false;
	}
	else
	{
		Logger::Log("GLEW initialization complete", LogType::INF);

		if (oIdVBO == 0)
			glGenBuffers(1, &oIdVBO);
		if (oIdVAO == 0)
			glGenVertexArrays(1, &oIdVAO);

		glBindVertexArray(oIdVAO);

		glBindBuffer(GL_ARRAY_BUFFER, oIdVBO);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vert), (void*)offsetof(vert, pos));
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(vert), (void*)offsetof(vert, col));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vert), (void*)offsetof(vert, uv));

		glBufferData(GL_ARRAY_BUFFER, MAX_VERTEX * sizeof(vert), nullptr, GL_DYNAMIC_DRAW);

		glBindVertexArray(0);

		ok = true;


		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		oActiveWnd = dynamic_cast<EWindow*>(getSystem(SysType::WINDOW));
		oObjects = dynamic_cast<GameObjectManager*>(getSystem(SysType::OBJMANAGER));
		if (oActiveWnd == nullptr)
		{
			ok = false;
			Logger::fatalError("Window is not set for render.");
		}
		if (oObjects == nullptr)
		{
			ok = false;
			Logger::fatalError("Object pool is not set for render.");
		}

		cam = glm::ortho(0.0f, (float)oActiveWnd->getWidth(), 0.0f, (float)oActiveWnd->getHeigth());
	}

	return ok;
}

bool ERender2D::reset()
{
	return false;
}

bool ERender2D::update(GameState * state)
{
	if ((oObjects->getSize() > MAX_SPRITE) || (oObjects->getSize() <= 0))
		return false;

	bool ok = true;
	int mulc(-1);
	Material *lastMaterial = nullptr;
	for (auto obj = oObjects->begin(); obj != oObjects->end(); ++obj)
	{
		Sprite *sprite = (*obj);
		if (lastMaterial == nullptr || lastMaterial->getId() != sprite->getMaterial()->getId())
		{
			++mulc;
			oRenderObjs.push_back(new Multi());
			oRenderObjs[mulc]->material = sprite->getMaterial();
			lastMaterial = sprite->getMaterial();
		}
		vert lt = sprite->leftTop();
		vert rd = sprite->rightDown();
		vert ld;
		ld.col = glm::vec4(1, 0, 0.83, 1);
		ld.pos = glm::vec4(lt.pos.x, rd.pos.y, 0.0, 1.0);
		ld.uv = glm::vec2(lt.uv.x, rd.uv.y);
		vert rt;
		rt.col = glm::vec4(1, 0, 0.83, 1);
		rt.pos = glm::vec4(rd.pos.x, lt.pos.y, 0.0, 1.0);
		rt.uv = glm::vec2(rd.uv.x, lt.uv.y);

		oRenderObjs[mulc]->oVertexes.push_back(ld);
		oRenderObjs[mulc]->oVertexes.push_back(rd);
		oRenderObjs[mulc]->oVertexes.push_back(lt);

		oRenderObjs[mulc]->oVertexes.push_back(lt);
		oRenderObjs[mulc]->oVertexes.push_back(rd);
		oRenderObjs[mulc]->oVertexes.push_back(rt);
	}

	if (oRenderObjs.size() > 0)
	{
		begin();
		for (GLuint k(0); k < oRenderObjs.size(); ++k)
		{
			oRenderObjs[k]->material->compile();
			oRenderObjs[k]->material->getMaterialShader()->use();
			oRenderObjs[k]->material->apply(cam);
			glBindVertexArray(oIdVAO);

			glBufferSubData(GL_ARRAY_BUFFER, 0, oRenderObjs[k]->oVertexes.size() * sizeof(vert), oRenderObjs[k]->oVertexes.data());

			glDrawArrays(GL_TRIANGLES, 0, oRenderObjs[k]->oVertexes.size());

			glBindVertexArray(0);
			oRenderObjs[k]->material->getMaterialShader()->unuse();
		}
		end();
	}

	return ok;
}