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
#include "Renderer\Textures\SpriteLoader.h"

#include "World.h"


namespace Game
{
	GameManager::GameManager()
	{
		Renderer::SpriteLoader::RegisterSprite("textures\\CitySpriteAtlas.png", 16, 16, 1, 1, 2, 0, "City::Red-Top");

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