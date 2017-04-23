#include "Shader.h"


Shader::Shader()
	: oCountAttrib(0)
	, oShaderID(0)
	, oVertexID(0)
	, oFragmentID(0)
{
}


Shader::~Shader()
{
}

void Shader::use()
{
	glUseProgram(oShaderID);
	for (int i(0); i < oCountAttrib; i++)
		glEnableVertexAttribArray(i);
}

void Shader::unuse()
{
	glUseProgram(0);
	for (int i(0); i < oCountAttrib; i++)
		glDisableVertexAttribArray(i);
}

GLuint Shader::getUniformVar(const std::string & var)
{
	GLuint uniform = glGetUniformLocation(oShaderID, var.c_str());
	if (uniform == GL_INVALID_INDEX)
		Logger::fatalError("Can not get uniform varible " + var);
	return uniform;
}

void Shader::compile(const std::string & vertexPath, const std::string & fragPath)
{
	oShaderID = glCreateProgram();

	oVertexID = glCreateShader(GL_VERTEX_SHADER);
	if (oVertexID == 0)
		Logger::Log("Failed to create vertex shader", LogType::ERR);

	oFragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	if (oFragmentID == 0)
		Logger::Log("Failed to create fragment shader", LogType::ERR);

	compileShader(vertexPath, oVertexID);
	compileShader(fragPath, oFragmentID);
}

void Shader::compileShader(const std::string & path, GLuint & ID)
{
	//read the file of shader
	std::ifstream vertexFile(path);
	if (vertexFile.fail())
	{
		Logger::Log("Can not open vertex shader file at path: " + path, LogType::ERR);
		perror(path.c_str());
	}

	std::string fileContents = "";
	std::string line = "";

	while (std::getline(vertexFile, line))
		fileContents += line + "\n";

	vertexFile.close();

	//compile shader
	const char* src = fileContents.c_str();
	glShaderSource(ID, 1, &src, nullptr);
	glCompileShader(ID);

	//check to compile success
	GLint success = 0;
	glGetShaderiv(ID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint length = 0;
		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &length);

		std::vector<char> errors(length);
		glGetShaderInfoLog(ID, length, &length, &errors[0]);

		glDeleteShader(ID);

		Logger::Log(path + ": Shader compile failed: ", LogType::ERR);
		std::printf("%s", &errors[0]);
	}
}

void Shader::link()
{	
	//link shaders to programm
	glAttachShader(oShaderID, oVertexID);
	glAttachShader(oShaderID, oFragmentID);

	glLinkProgram(oShaderID);

	//success checked
	GLint isLinked = 0;
	glGetProgramiv(oShaderID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(oShaderID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(oShaderID, maxLength, &maxLength, &infoLog[0]);

		glDeleteProgram(oShaderID);
		glDeleteShader(oVertexID);
		glDeleteShader(oFragmentID);

		Logger::Log("Shader link failed: ", LogType::ERR);
		std::printf("%s", &infoLog[0]);

	}

	//Always detach shaders after a successful link.
	glDetachShader(oShaderID, oVertexID);
	glDetachShader(oShaderID, oFragmentID);
	glDeleteShader(oVertexID);
	glDeleteShader(oFragmentID);
}

void Shader::addAttrib(const std::string & attrib)
{
	glBindAttribLocation(oShaderID, oCountAttrib++, attrib.c_str());
}

void Shader::setUniformF(const std::string & name, float n)
{
	glUniform1f(getUniformVar(name), n);
}
void Shader::setUniformF(const std::string & name, float x, float y)
{
	glUniform2f(getUniformVar(name), x, y);
}
void Shader::setUniformF(const std::string & name, float x, float y, float z)
{
	glUniform3f(getUniformVar(name), x, y, z);
}
void Shader::setUniformF(const std::string & name, float x, float y, float z, float w)
{
	glUniform4f(getUniformVar(name), x, y, z, w);
}
void Shader::setUniformMatrix4(const std::string & name, const glm::mat4 & matrix)
{
	glUniformMatrix4fv(getUniformVar(name), 1, GL_FALSE, &matrix[0][0]);
}