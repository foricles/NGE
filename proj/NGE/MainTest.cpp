#include "Buber.h"
#include "Application.h"
#include "Shader.h"

int main(int argc, char** argv)
{
	Application *app = new Application();
	Buber *buber = new Buber();
	GLuint exitCode;

	app->setGameClass(buber);
	exitCode = app->run();

	delete buber;
	delete app;
	return exitCode;
}