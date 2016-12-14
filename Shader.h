#pragma once
#include <GL/glew.h>
namespace cg{

	class Shader
	{
	public:
		Shader(char *filename, GLenum shadertype);
		~Shader();
		GLuint getShaderId();
	private:
		GLuint shaderid;
	};

}