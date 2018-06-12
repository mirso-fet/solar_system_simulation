// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#include "camera.h"

void Camera::setCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(xPosition, 0.0, 0.0);
	glTranslatef(0.0, 0.0, zPosition);
	glRotatef(xRotationAngle, 1.0, 0.0, 0.0);
	glRotatef(yRotationAngle, 0.0, 1.0, 0.0);
}

void Camera::increaseDistance(GLfloat inc) {
	zPosition -= inc;
}

void Camera::rotateAroundSun(GLfloat angle) {
	yRotationAngle += angle;
	if (yRotationAngle > 360.0) yRotationAngle -= 360.0;
	if (yRotationAngle < -360.0) yRotationAngle += 360.0;
}

void Camera::rotatePerspective(GLfloat angle) {
	xRotationAngle += angle;
	if (xRotationAngle > 360.0) xRotationAngle -= 360.0;
	if (xRotationAngle < -360.0) xRotationAngle += 360.0;
}