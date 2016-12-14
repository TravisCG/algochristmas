#include "ShaderError.h"
#include <stdlib.h>
#include <stdio.h>

using namespace cg;

ShaderError::ShaderError()
{
}


ShaderError::~ShaderError()
{
}

void ShaderError::errorStr(GLuint obj, ERROR_TYPE type)
{
	int len = 0;
	int outlen = 0;
	char *msg;

	if (type == PROGRAM_ERROR) {
		glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &len);
	}
	else {
		glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &len);
	}

	msg = (char*)malloc(len);

	if (type == PROGRAM_ERROR) {
		glGetProgramInfoLog(obj, len, &outlen, msg);
	}
	else {
		glGetShaderInfoLog(obj, len, &outlen, msg);
	}

	printf("%s\n", msg);

	free(msg);
}