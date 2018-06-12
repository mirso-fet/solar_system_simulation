// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include <Windows.h>
#include "gl/glu.h"
#include "gl/gl.h"

#include <vector>
#include <fstream>
#include <string>

class TextureInfo {
	public:
		TextureInfo(const std::string& filename, GLuint width, GLuint height) :
			filename{filename},
			width{width},
			height{height}
		{}

		std::string filename;
		GLuint width;
		GLuint height;
		GLfloat xRotateAngle = 0.0f;
		GLfloat yRotateAngle = 0.0f;
		GLfloat zRotateAngle = 0.0f;
};

class Texture {
public:
	Texture(const std::string& filename, GLuint width, GLuint height);
	GLuint getTexture() { return texture; }

private:
	GLuint texture = 0;
};
