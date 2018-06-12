// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#pragma once

#include <vector>
#ifndef NDEBUG
	#define NDEBUG
#endif
#include "GL/glut.h"
#include "drawable.h"
#include "camera.h"
#include "light.h"

class Scene {
public:
	Scene();
	void displayScene();
	void animateScene();
	void addObject(Drawable* obj);

	Camera camera;
	Light light1;
	Light light2;

private:
	std::vector<Drawable *> drawableObjects;
};
