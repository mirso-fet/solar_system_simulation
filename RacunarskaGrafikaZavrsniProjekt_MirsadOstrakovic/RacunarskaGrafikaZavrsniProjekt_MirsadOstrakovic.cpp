// Ostrakovic Mirsad, Racunarska grafika, FET Tuzla

#include "stdafx.h"
#ifndef NDEBUG
	#define NDEBUG
#endif

#include <Windows.h>
#include "GL/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

#include <vector>
#include <memory>

#include "drawable.h"
#include "texture.h"
#include "camera.h"
#include "scene.h"
#include "planet.h"
#include "sun.h"
#include "satellite.h"

#define SUN_INIT_DISTANCE 6.0

void init();
void display();
void setupScene();
void idle();
void reshapeHandle(int x, int y);
void kbdHandle(unsigned char key, int x, int y);
void mouseHandle(int button, int state, int x, int y);
void mouseMotionHandle(int x, int y);

const GLfloat sunEmissionSpec[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat planetJupiterSpecularSpec[4] = { 0.8f, 0.8f, 0.8f, 1.0f };

std::shared_ptr<Scene> scene;
std::shared_ptr<Sun> sun;
std::shared_ptr<Planet> planetMercury;
std::shared_ptr<Planet> planetVenus;
std::shared_ptr<Planet> planetEarth;
std::shared_ptr<Planet> planetMars;
std::shared_ptr<Planet> planetJupiter;
std::shared_ptr<Planet> planetSaturn;
std::shared_ptr<Planet> planetUranus;
std::shared_ptr<Planet> planetNeptune;
std::shared_ptr<Satellite> satelliteMoon;

int pressedButton = 0;


int main(int argc, char* argv[]){
	//init GLUT window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Solar system simulation - Mirsad Ostrakovic");
	
	//Create scene
	scene = std::make_shared<Scene>();
	
	//Setup GLUT callback functions
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(kbdHandle);
	glutReshapeFunc(reshapeHandle);
	glutMouseFunc(mouseHandle);
	glutMotionFunc(mouseMotionHandle);
	
	// setup projection matrix
	init();
	
	// setup objects in the Scene
	setupScene();
	
	//infinity loop
	glutMainLoop();

	return 0;
}

void init() {
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 640.0/480.0, 1.0, 1500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void mouseHandle(int button, int state, int x, int y) {

	if (state == GLUT_DOWN) {
		pressedButton = button;

		switch (button) {
		case GLUT_LEFT_BUTTON:
			satelliteMoon->increaseRotationAngle(3.0);
			break;

		case GLUT_RIGHT_BUTTON:
			satelliteMoon->increseRadius(0.05);
			break;
		}
	}
	else
		pressedButton = -1;
}

void mouseMotionHandle(int x, int y) {
	static int lastX = 0;

	if (pressedButton == GLUT_MIDDLE_BUTTON) {
		if (lastX > x)
			scene->camera.moveCameraRight(1.0);
		if (lastX < x)
			scene->camera.moveCameraLeft(1.0);
	}
	lastX = x;
}

void reshapeHandle(int w, int h) {
	glViewport(0, 0, (GLfloat)w, (GLfloat)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (GLfloat)(w) / (GLfloat)h, 1.0, 1500.0);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	scene->displayScene();
}

void setupScene() {
	//The data are from Wiki. Except from the ratio of the diameter of the Sun and the diametars of the planets, all
	//other ratios are same as in real life.

	//Create the Sun
	TextureInfo sunTextureInfo("textures/sun.bmp", 256, 256);
	sun = std::make_shared<Sun>(sunTextureInfo, 50.0, 250.0); // In reality, The Sun is rotating realy fast, you can find data on Wiki.
	sun->setMaterialEmissionSpec(sunEmissionSpec);

	//Create the planet Mercury
	TextureInfo mercuryTextureInfo("textures/mercury.bmp", 256, 256);
	planetMercury = std::make_shared<Planet>(mercuryTextureInfo, 0.382, SUN_INIT_DISTANCE + 0.39, 0.24, 58.64);

	//Create the planet Venus
	TextureInfo venusTextureInfo("textures/venus.bmp", 256, 256);
	planetVenus = std::make_shared<Planet>(venusTextureInfo, 0.949, SUN_INIT_DISTANCE + 0.72, 0.62, -243.02);

	//Create the planet Earth and the Moon
	TextureInfo moonTextureInfo("textures/moon.bmp", 256, 256);
	satelliteMoon = std::make_shared<Satellite>(moonTextureInfo, 0.273, 0.2, 30.0, 0.0833);

	TextureInfo earthTextureInfo("textures/earth.bmp", 256, 256);
	planetEarth = std::make_shared<Planet>(earthTextureInfo, 1.0, SUN_INIT_DISTANCE + 1.0, 1.0, 1.0);
	planetEarth->addSatellite(satelliteMoon.get());

	TextureInfo marsTextureInfo("textures/mars.bmp", 256, 256);
	planetMars = std::make_shared<Planet>(marsTextureInfo, 0.532, SUN_INIT_DISTANCE + 1.52, 1.88, 1.03);

	//Create the planet Jupiter
	TextureInfo jupiterTextureInfo("textures/jupiter.bmp", 256, 256);
	jupiterTextureInfo.xRotateAngle = 90;
	planetJupiter = std::make_shared<Planet>(jupiterTextureInfo, 11.209, SUN_INIT_DISTANCE + 5.20, 11.86, 0.41);
	planetJupiter->setMaterialSpecularSpec(planetJupiterSpecularSpec);

	//Create the planet Saturn
	TextureInfo saturnTextureInfo("textures/saturn.bmp", 256, 256);
	planetSaturn = std::make_shared<Planet>(saturnTextureInfo, 9.449, SUN_INIT_DISTANCE + 9.54, 29.46, 0.43);

	//Create the planet Uranus
	TextureInfo	uranusTextureInfo("textures/uranus.bmp", 256, 256);
	planetUranus = std::make_shared<Planet>(uranusTextureInfo, 4.007, SUN_INIT_DISTANCE + 19.22, 84.01, -0.72);

	//Create the planet Neptune
	TextureInfo neptuneTextureInfo("textures/neptune.bmp", 256, 256);
	planetNeptune = std::make_shared<Planet>(neptuneTextureInfo, 3.883, SUN_INIT_DISTANCE + 30.06, 164.8, 0.67);

	scene->addObject(sun.get());
	scene->addObject(planetMercury.get());
	scene->addObject(planetVenus.get());
	scene->addObject(planetEarth.get());
	scene->addObject(planetMars.get());
	scene->addObject(planetJupiter.get());
	scene->addObject(planetSaturn.get());
	scene->addObject(planetUranus.get());
	scene->addObject(planetNeptune.get());
}

void idle() {
	scene->animateScene();
	glutPostRedisplay();
}

void kbdHandle(unsigned char key, int x, int y) {
	static bool isLightTurnOn1 = true;
	static bool isLightTurnOn2 = true;
	static bool isMaterialTurnOn1 = true;
	static bool isMaterialTurnOn2 = true;

	switch (key) {
	case 'A':
	case 'a':
		scene->camera.rotateAroundSun(-1.0);
		break;

	case 'D':
	case 'd':
		scene->camera.rotateAroundSun(1.0);
		break;

	case 'W':
	case 'w':
		scene->camera.increaseDistance(-1.0);
		break;

	case 'S':
	case 's':
		scene->camera.increaseDistance(1.0);
		break;

	case 'Q':
	case 'q':
		scene->camera.rotatePerspective(1.0);
		break;

	case 'E':
	case 'e':
		scene->camera.rotatePerspective(-1.0);
		break;

	case '0':
		if ((isLightTurnOn1 = !isLightTurnOn1))
			scene->light1.enable();
		else
			scene->light1.disable();
		break;

	case '1':
		if ((isLightTurnOn2 = !isLightTurnOn2))
			scene->light2.enable();
		else
			scene->light2.disable();
		break;

	case '2':
		if ((isMaterialTurnOn1 = !isMaterialTurnOn1))
			sun->enableMaterial();
		else
			sun->disableMaterial();
		break;

	case '3':
		if ((isMaterialTurnOn2 = !isMaterialTurnOn2))
			planetJupiter->enableMaterial();
		else
			planetJupiter->disableMaterial();
		break;
	}
}