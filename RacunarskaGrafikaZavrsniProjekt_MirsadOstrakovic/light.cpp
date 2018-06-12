// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#include "light.h"


void Light::setAmbientLight(GLfloat ambient[4]) {
	memcpy(this->ambient, ambient, 4 * sizeof(GLfloat));
	glLightfv(light, GL_AMBIENT, this->ambient);
}

void Light::setDiffuseLight(GLfloat diffuse[4]) {
	memcpy(this->diffuse, diffuse, 4 * sizeof(GLfloat));
	glLightfv(light, GL_DIFFUSE, this->diffuse);
}

void Light::setSpecularLight(GLfloat specular[4]) {
	memcpy(this->specular, specular, 4 * sizeof(GLfloat));
	glLightfv(light, GL_SPECULAR, this->specular);
}

void Light::setPosition(GLfloat position[4]) {
	memcpy(this->position, position, 4 * sizeof(GLfloat));
	glLightfv(light, GL_POSITION, this->position);
}
void Light::setSpotDirection(GLfloat spotDirection[3]) {
	memcpy(this->spotDirection, spotDirection, 3 * sizeof(GLfloat));
	glLightfv(light, GL_SPOT_DIRECTION, this->spotDirection);
}

void Light::setSpotCutoff(GLfloat spotCutoff) {
	this->spotCutoff = spotCutoff;
	glLightf(light, GL_SPOT_CUTOFF, spotCutoff);
}

void Light::setLight() {
	glLightfv(light, GL_POSITION, position);
	glLightfv(light, GL_SPECULAR, specular);
	glLightfv(light, GL_AMBIENT, ambient);
	glLightfv(light, GL_DIFFUSE, diffuse);
	glLightfv(light, GL_SPOT_DIRECTION, spotDirection);
	glLightf(light, GL_SPOT_CUTOFF, spotCutoff);
}

Light::Light(GLenum light) : light{ light }, isEnable{ true } {
	if (light == GL_LIGHT0) {
		GLfloat tmp[] = { 1.0, 1.0, 1.0, 1.0 };
		memcpy(specular, tmp, 4 * sizeof(GLfloat));
		memcpy(diffuse, tmp, 4 * sizeof(GLfloat));
	}

	setLight();
	enable();
}