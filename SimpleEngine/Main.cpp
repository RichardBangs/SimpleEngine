
#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "Renderer\RenderableManager.h"
#include "Renderer\SimpleRenderable.h"
#include "Renderer\VertexFormat.h"
#include "Renderer\ShaderLoader.h"

#include <iostream>
#include <vector>

extern void SetupOpenGLWindow(int argc, char** argv);
extern void OnRender();
extern void SetupScene();
extern void OnClose();

int main(int argc, char** argv)
{
	SetupOpenGLWindow( argc, argv );

	return 0;
}

void SetupOpenGLWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(800, 600);
	glutCreateWindow("Simple Engine");

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

	glutDisplayFunc(OnRender);
	glutCloseFunc(OnClose);

	SetupScene();

	glutMainLoop();
}

void SetupScene()
{
	Renderer::RenderableManager::Create();

	std::vector<Renderer::VertexFormat> vertices;
	vertices.push_back(Renderer::VertexFormat(glm::vec3(0.25f, -0.25f, 0.0f)));
	vertices.push_back(Renderer::VertexFormat(glm::vec3(-0.25f, -0.25f, 0.0f)));
	vertices.push_back(Renderer::VertexFormat(glm::vec3(0.25f, 0.25f, 0.0f)));

	auto simpleRenderable = new Renderer::SimpleRenderable();
	simpleRenderable->CreateFromList(vertices);

	unsigned int simpleShaders = Renderer::ShaderLoader::CreateProgram("Shaders\\BasicVertex.glsl", "Shaders\\BasicFragment.glsl");
	simpleRenderable->SetShader(simpleShaders);
}

void OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	Renderer::RenderableManager::Instance().Render();

	glutSwapBuffers();
}

void OnClose()
{
	glutLeaveMainLoop();

	Renderer::RenderableManager::Destroy();
	Renderer::ShaderLoader::DestroyAllShaders();
}