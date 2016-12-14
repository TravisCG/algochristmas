#pragma once

#include <GL/glew.h>
#include "Shader.h"

namespace cg
{
	class ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();
		void compile();
		void addShader(char *filename, GLenum shadertype);
		GLuint getProgramID();
	private:
		GLuint programid;
	};
}

