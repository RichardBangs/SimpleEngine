#include "GameManager.h"

#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "Renderer\RenderableManager.h"
#include "Renderer\Textures\TextureLoader.h"
#include "Renderer\Textures\SpriteLoader.h"

#include "InputManager.h"

#include "World.h"
#include "Player.h"

namespace Game
{
	GameManager::GameManager()
	{
		InputManager::Create();

		const char* cityAtlasPath = "textures\\CitySpriteAtlas.png";
		Renderer::SpriteLoader::RegisterAtlas(cityAtlasPath, 16, 16, 1, 1);
		
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 0, 25, "City::Grass-TopLeft");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 1, 25, "City::Grass-Top");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 2, 25, "City::Grass-TopRight");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 0, 26, "City::Grass-MiddleLeft");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 1, 26, "City::Grass-Middle");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 2, 26, "City::Grass-MiddleRight");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 0, 27, "City::Grass-BottomLeft");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 1, 27, "City::Grass-Bottom");
		Renderer::SpriteLoader::RegisterSprite(cityAtlasPath, 2, 27, "City::Grass-BottomRight");

		_world = new World();

		_player = new Player();
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::OnUpdate(float dt)
	{
		_player->Update(dt);
	}

	void GameManager::OnRender()
	{
	}
}