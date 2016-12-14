#pragma once
#include <GL/glew.h>
#include "ShaderProgram.h"

class demo
{
private:
	float width;
	float height;
	GLuint vao;
	GLuint vbo[2] = { 1,1 };
	GLuint lyricstex;
	void lyrics(double time);
	cg::ShaderProgram *oneprg;

public:
	demo();
	~demo();
	void play(double time);
	void init(float w, float h);
};

