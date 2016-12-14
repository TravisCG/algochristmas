#include "demo.h"
#include <stdio.h>
#include "intervals.h"
#include "Texture.h"

demo::demo()
{
}


demo::~demo()
{
}

void demo::init(float w, float h) {
	GLfloat fscoords[] = { -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0 }; //full screen coordinates
	GLfloat textcoord[] = { 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0 };
	float aspect = 1920.0f / 1080.0f;
	height = (float)w / aspect;
	GLint starty = (h - height) / 2;
	width = w;

	glViewport(0, starty, width, height);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(2, (GLuint*)&vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), fscoords, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), textcoord, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenTextures(1, &lyricstex);
	cg::Texture::loadTGA("data\\code.tga", lyricstex);

	oneprg = new cg::ShaderProgram();
	oneprg->addShader("data\\one.fs", GL_FRAGMENT_SHADER);
	oneprg->addShader("data\\one.vs", GL_VERTEX_SHADER);
	oneprg->compile();

}

void demo::lyrics(double time) {
	GLint loc;
	GLfloat x1 = 0.0f, y1 = 0.0f, x2 = 0.0f, y2 = 0.0f;

	loc = glGetUniformLocation(oneprg->getProgramID(), "highlight");

	for (int i = 0; i < 48; i++) {
		if (time > times[i * 2] && time < times[i * 2 + 1]) {
			// draw something
			int highlightindex = i % 12;
			x1 = highlights[highlightindex * 4];
			y1 = 1.0 - highlights[highlightindex * 4 + 3];
			x2 = highlights[highlightindex * 4 + 2];
			y2 = 1.0 - highlights[highlightindex * 4 + 1];
		}
	}

	glUniform4f(loc, x1, y1, x2, y2);
}

void demo::play(double time) {
	GLint loc;

	glUseProgram(oneprg->getProgramID());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, lyricstex);
	loc = glGetUniformLocation(oneprg->getProgramID(), "img");
	glUniform1i(loc, 0);
	lyrics(time);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}


