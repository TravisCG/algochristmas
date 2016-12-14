#pragma once
#include <GL/glew.h>
namespace cg {
	class Texture
	{
	public:
		Texture();
		~Texture();
		static void loadTGA(char *filename, GLuint texid);
	};

}

