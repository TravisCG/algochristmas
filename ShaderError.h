#pragma once

#include <GL/glew.h>

namespace cg
{
	enum ERROR_TYPE { SHADER_ERROR, PROGRAM_ERROR };
	class ShaderError
	{
	public:
		ShaderError();
		~ShaderError();
		static void errorStr(GLuint obj, ERROR_TYPE type);
	};
}

