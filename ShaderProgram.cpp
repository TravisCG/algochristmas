#include "ShaderProgram.h"
#include <stdio.h>
#include "ShaderError.h"

using namespace cg;

ShaderProgram::ShaderProgram()
{
	programid = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(programid);
}

void ShaderProgram::addShader(char *filename, GLenum shadertype)
{
	Shader *shader = new Shader(filename, shadertype);
	glAttachShader(programid, shader->getShaderId());
}

void ShaderProgram::compile()
{
	int error;
	glLinkProgram(programid);
	glGetProgramiv(programid, GL_LINK_STATUS, &error);
	if (error == GL_FALSE) {
		printf("Link error\n");
		ShaderError::errorStr(programid, PROGRAM_ERROR);

	}
	glValidateProgram(programid);
	glGetProgramiv(programid, GL_VALIDATE_STATUS, &error);
	if (error == GL_FALSE) {
		printf("Validate error\n");
		ShaderError::errorStr(programid, PROGRAM_ERROR);
	}
}

GLuint ShaderProgram::getProgramID()
{
	return(programid);
}
