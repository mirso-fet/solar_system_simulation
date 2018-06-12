// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include "planet.h"
#include "texture.h"

class Sun : public Planet {
	public:
		Sun(const TextureInfo& textureInfo,
			GLfloat radius,
			GLfloat rotationPeriod) :
			Planet(textureInfo, radius, 0.0f, 1000000.0f, rotationPeriod) 
	    {}
};