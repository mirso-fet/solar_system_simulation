// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#include "texture.h"


Texture::Texture(const std::string& filename, GLuint width, GLuint height) {
	//open file
	std::ifstream file(filename, std::ifstream::in | std::ifstream::binary);
	if (!file.is_open()) return;

	//read texture
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)),
		(std::istreambuf_iterator<char>()));
	char* data = &buffer[0]; //this pointer will not be valid after insertion in the vector

	//setup texture object
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_BGRA_EXT, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_TEXTURE_ENV_COLOR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	//close file
	file.close();
}
