#include "Shader.h"
#include <stdio.h>
#include <stdlib.h>
#include "ShaderError.h"

using namespace cg;

Shader::Shader(char *filename, GLenum shadertype)
{
	FILE *f = fopen(filename, "r");
	fseek(f, 0, SEEK_END);
	size_t count = ftell(f);

	rewind(f);
	char *source = (char*)calloc(count, sizeof(char));
	fread(source, sizeof(char), count, f);
	fclose(f);

	shaderid = glCreateShader(shadertype);
	glShaderSource(shaderid, 1, &source, NULL);
	glCompileShader(shaderid);
	
	/* TODO error checking */
	int error;
	glGetShaderiv(shaderid, GL_COMPILE_STATUS, &error);
	if (error == GL_FALSE) {
		printf("Shader error\n");
		printf("%s\n", source);
		ShaderError::errorStr(shaderid, SHADER_ERROR);
	}
	free(source);
}


Shader::~Shader()
{
	glDeleteShader(shaderid);
}

GLuint Shader::getShaderId() {
	return(shaderid);
}
