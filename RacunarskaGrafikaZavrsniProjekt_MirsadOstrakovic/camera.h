// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include <Windows.h>
#include "gl/gl.h"
#include "gl/glu.h"

class Camera {
public:
	void setCamera();
	void increaseDistance(GLfloat inc);
	void rotateAroundSun(GLfloat angle);
	void rotatePerspective(GLfloat angle);
	void moveCameraLeft(GLfloat inc) { xPosition -= inc; }
	void moveCameraRight(GLfloat inc) { xPosition += inc; }


private:
	GLfloat xPosition = 0.0;
	GLfloat zPosition = -500.0;
	GLfloat xRotationAngle = 0.0;
	GLfloat yRotationAngle = 0.0;
};
