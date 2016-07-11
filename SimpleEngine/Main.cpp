
#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "Renderer\RenderableManager.h"
#include "Renderer\Camera.h"
#include "Renderer\ShaderLoader.h"
#include "Renderer\WindowManager.h"

#include "Game\InputManager.h"
#include "Game\GameManager.h"

#include <iostream>
#include <vector>

extern void SetupOpenGLWindow(int argc, char** argv);
extern void OnKeyboardInput(unsigned char key, int x, int y);
extern void OnMouseInput(int button, int state, int x, int y);
extern void OnRender();
extern void SetupScene();
extern void OnClose();
extern void OnTick(int timerId);

Game::GameManager* gameManager;

int main(int argc, char** argv)
{
	SetupOpenGLWindow( argc, argv );

	return 0;
}

void SetupOpenGLWindow(int argc, char** argv)
{
	const int windowWidth = 1600;
	const int windowHeight = 800;

	const float aspectRatio = (float)windowHeight / windowWidth;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	Renderer::WindowManager::Create();
	Renderer::WindowManager::Instance().InitialiseWindow(glm::vec2(100, 100), glm::vec2(windowWidth, windowHeight));

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << "GLEW Version 4.5 is supported." << std::endl;
	}
	else
	{
		std::cout << "ERROR - GLEW 4.5 Not Supported" << std::endl;
		int temp;
		std::cin >> temp;
		return;
	}

	glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(OnKeyboardInput);
	glutMouseFunc(OnMouseInput);
	glutDisplayFunc(OnRender);
	glutCloseFunc(OnClose);
	glutTimerFunc(1, OnTick, 0);

	Renderer::RenderableManager::Create();
	Renderer::Camera::Create();

	Renderer::Camera::Instance().Scale = glm::vec3(aspectRatio, 1.0f, 1.0f);

	gameManager = new Game::GameManager();

	glutMainLoop();
}

void OnKeyboardInput(unsigned char key, int x, int y)
{
	Game::InputManager::Instance().OnKeyboardInput(key);
}

void OnMouseInput(int button, int state, int x, int y)
{
	Game::InputManager::Instance().OnMouseInput(button, state, x, y);
}

void OnUpdate(float dt)
{
	gameManager->OnUpdate( dt );
}

void OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	Renderer::RenderableManager::Instance().Render();

	gameManager->OnRender();

	glutSwapBuffers();
}

void OnTick(int timerId)
{
	OnUpdate(1.0f/60.0f);
	OnRender();

	glutTimerFunc(1000 / 60, OnTick, 0);
}

void OnClose()
{
	glutLeaveMainLoop();

	delete gameManager;

	Renderer::RenderableManager::Destroy();
	Renderer::Camera::Destroy();
	Renderer::ShaderLoader::DestroyAllShaders();
}