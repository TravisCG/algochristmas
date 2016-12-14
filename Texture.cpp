#include "Texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

using namespace cg;

Texture::Texture()
{
}


Texture::~Texture()
{
}

void Texture::loadTGA(char *filename, GLuint texid)
{
	char id;
	char colormaptype;
	char imgtype;
	char colormap[5];
	short int w;
	short int h;
	char bpp;
	char *image;
	GLenum type;

	FILE *f = fopen(filename, "rb");
	fread(&id, 1, 1, f);
	fread(&colormaptype, 1, 1, f);
	fread(&imgtype, 1, 1, f);
	fread(&colormap, 5, 1, f);
	fread(&colormap, 4, 1, f);
	fread(&w, 2, 1, f);
	fread(&h, 2, 1, f);
	fread(&bpp, 1, 1, f);
	bpp = bpp / 8;

	if (bpp == 1) {
		type = GL_RED;
	}
	else if(bpp == 3){
		type = GL_BGR;
	}
	else {
		type = GL_BGRA;
	}

	fread(&id, 1, 1, f);
	image = (char*)malloc(w * h * bpp);
	fread(image, sizeof(char), w * h * bpp, f);
	fclose(f);

	glBindTexture(GL_TEXTURE_2D, texid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w,
		h, 0, type, GL_UNSIGNED_BYTE,
		image);

	free(image);
}
