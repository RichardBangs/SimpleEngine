#include "GameManager.h"

#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "Renderer\RenderableManager.h"
#include "Renderer\QuadRenderable.h"
#include "Renderer\VertexFormat.h"
#include "Renderer\ShaderLoader.h"
#include "Renderer\Textures\TextureLoader.h"

#include "World.h"


namespace Game
{
	GameManager::GameManager()
	{
		_world = new World();
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::OnUpdate(float dt)
	{
	}

	void GameManager::OnRender()
	{
	}
}