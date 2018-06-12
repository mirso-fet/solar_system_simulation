// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#include "scene.h"

Scene::Scene() : light1{ GL_LIGHT0 }, light2{ GL_LIGHT1 } {
	glClearColor(0.0, 0.0, 0.0, 0.0); // vidjeti da li opuste treba
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	
	//setup light1
	GLfloat specularLight1[4] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat positionLight1[4] = { 0.0, 0.0, 2.0, -1.0 };
	GLfloat spotDirectionLight1[3] = { 0.0, 0.0, -80.0 };
	light1.setSpecularLight(specularLight1);
	light1.setPosition(positionLight1);
	light1.setSpotDirection(spotDirectionLight1);
	
	//setup light2
	GLfloat ambientLight2[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	light2.setAmbientLight(ambientLight2);
}

void Scene::displayScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera.setCamera();
	light1.setLight();
	light2.setLight();
	for(const auto& e : drawableObjects)
		e->draw();
	glutSwapBuffers();
}

void Scene::addObject(Drawable* obj) {
	drawableObjects.push_back(obj);
}

void Scene::animateScene() {
	for(const auto& e : drawableObjects)
		e->animation();
}
