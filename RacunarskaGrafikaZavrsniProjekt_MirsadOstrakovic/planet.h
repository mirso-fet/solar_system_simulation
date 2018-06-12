// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#ifndef NDEBUG
	#define NDEBUG
#endif

#include <Windows.h>
#include "GL/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

#include "drawable.h"
#include "texture.h"

#define AU 17.0f
#define EARTH_RADIUS 2.0f
#define ROTATION_CONST 1.0f
// ROTATION_CONST = 0.1f = 1/10 day

class Planet : public Drawable {
public:
	Planet(const TextureInfo& textureInfo,
		GLfloat radius,
		GLfloat distanceToSun,
		GLfloat orbitalPeriod,
		GLfloat rotationPeriod) :
		texture{textureInfo.filename, textureInfo.width, textureInfo.height},
		radius{ radius },
		distanceToSun{ distanceToSun },
		orbitalPeriod{ orbitalPeriod },
		rotationPeriod{ rotationPeriod },
		xTextureRotationAngle{textureInfo.xRotateAngle},
		yTextureRotationAngle{textureInfo.yRotateAngle},
		zTextureRotationAngle{textureInfo.zRotateAngle}
	{}

	void draw();
	void animation();

	void addSatellite(Drawable* object) { listOfSatellite.push_back(object); }

	void enableMaterial() { isMaterialEnable = true; }
	void disableMaterial() { isMaterialEnable = false;  }

	void setMaterialAmbientSpec(const GLfloat materialAmbientSpec[4]) {
		memcpy(this->materialAmbientSpec, materialAmbientSpec, 4 * sizeof(GLfloat));
	}

	void setMaterialDiffuseSpec(const GLfloat materialDiffuseSpec[4]) {
		memcpy(this->materialDiffuseSpec, materialDiffuseSpec, 4 * sizeof(GLfloat));
	}

	void setMaterialSpecularSpec(const GLfloat materialSpecularSpec[4]) {
		memcpy(this->materialSpecularSpec, materialSpecularSpec, 4 * sizeof(GLfloat));
	}

	void setMaterialEmissionSpec(const GLfloat materialEmissionSpec[4]) {
		memcpy(this->materialEmissionSpec, materialEmissionSpec, 4 * sizeof(GLfloat));
	}

	void setMaterialShininessSpec(const GLfloat materialShininessSpec) {
		this->materialShininessSpec = materialShininessSpec;
	}

protected:
	GLfloat rotationAroundSunAngle = 0.0;
	GLfloat rotationAroundSelfAngle = 0.0;

	GLfloat radius; // relative to the radius of the Earth
	GLfloat distanceToSun; // in AU - astronomical unit
	GLfloat orbitalPeriod; // in years
	GLfloat rotationPeriod; // per days

private:
	void drawTextureSphere(Texture texture, GLfloat dim);
	void setMaterial();

	GLfloat materialAmbientSpec[4] = { 0.05f, 0.05f, 0.05f, 1.0f };
	GLfloat materialDiffuseSpec[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat materialSpecularSpec[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat materialEmissionSpec[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat materialShininessSpec = 0.0f;

	Texture texture;
	bool isMaterialEnable = true;
	GLfloat xTextureRotationAngle;
	GLfloat yTextureRotationAngle;
	GLfloat zTextureRotationAngle;

	std::vector<Drawable *> listOfSatellite;
};

