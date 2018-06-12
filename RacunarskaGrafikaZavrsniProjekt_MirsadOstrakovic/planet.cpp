// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#include "planet.h"

void Planet::setMaterial() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbientSpec);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuseSpec);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecularSpec);
	glMaterialfv(GL_FRONT, GL_EMISSION, materialEmissionSpec);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininessSpec);
}

void Planet::animation() {
	rotationAroundSelfAngle += ROTATION_CONST / rotationPeriod;
	rotationAroundSunAngle += (ROTATION_CONST / 365.26) / orbitalPeriod;
}

void Planet::draw() {
	glPushMatrix();
		if (isMaterialEnable) {
			glEnable(GL_COLOR_MATERIAL);
			setMaterial();
		}

		glRotatef(rotationAroundSunAngle, 0.0, 1.0, 0.0);
		glTranslatef(AU*distanceToSun, 0.0, 0.0);
		glRotatef(rotationAroundSelfAngle, 0.0, 1.0, 0.0);

		glRotatef(xTextureRotationAngle, 1.0, 0.0, 0.0);
		glRotatef(yTextureRotationAngle, 0.0, 1.0, 0.0);
		glRotatef(zTextureRotationAngle, 0.0, 0.0, 1.0);
		drawTextureSphere(texture, EARTH_RADIUS*radius);
		
		if (isMaterialEnable)
			glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	for (const auto& e : listOfSatellite) {
		glPushMatrix();
			glRotatef(rotationAroundSunAngle, 0.0, 1.0, 0.0);
			glTranslatef(AU*distanceToSun, 0.0, 0.0);
			e->draw();
		glPopMatrix();
	}
}

void Planet::drawTextureSphere(Texture texture, GLfloat dim) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getTexture());
	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, 1);
	gluSphere(quad, dim, 70, 70);
	glDisable(GL_TEXTURE_2D);
}
