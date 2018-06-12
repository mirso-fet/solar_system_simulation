// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include "planet.h"

class Satellite : public Planet {
	public:
		Satellite(const TextureInfo& textureInfo,
			GLfloat radius,
			GLfloat distanceToPlanet,
			GLfloat orbitalPeriod,
			GLfloat rotationPeriod) :
			Planet(textureInfo, radius, distanceToPlanet, orbitalPeriod, rotationPeriod)
		{}

		void increseRadius(GLfloat radiusInc) {
			radius += radiusInc;
			if (radius < 0.1 || radius > 0.6)
				radius = 0.1;
		}

		void increaseRotationAngle(GLfloat angleInc) {
			rotationAroundSunAngle += angleInc;
			
			if (rotationAroundSunAngle > 360.0)
				rotationAroundSunAngle -= 360.0;

			if (rotationAroundSunAngle < -360.0)
				rotationAroundSunAngle += 360.0;
		}

};