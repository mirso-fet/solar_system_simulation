// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include <Windows.h>
#include "gl/glu.h"
#include "gl/gl.h"

class Light {
public:
	Light(GLenum light);

	void setLight();

	void enable() { glEnable(light); isEnable = true; }
	void disable() { glDisable(light); isEnable = false; }
	bool isLightEnable() { return isEnable; }

	void setAmbientLight(GLfloat ambient[4]);
	void setDiffuseLight(GLfloat diffuse[4]);
	void setSpecularLight(GLfloat specular[4]);
	
	void setPosition(GLfloat position[4]);
	void setSpotDirection(GLfloat direction[3]);
	void setSpotCutoff(GLfloat spotCutoff);

private:
	GLfloat specular[4] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat ambient[4] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[4] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat position[4] = { 0.0, 0.0, 1.0, 0.0 };
	GLfloat spotDirection[3] = { 0.0, 0.0, -1.0 };
	GLfloat spotCutoff = 180.0;
	GLenum light;
	bool isEnable;
};
