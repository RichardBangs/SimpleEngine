#include "GameManager.h"

#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "Renderer\RenderableManager.h"
#include "Renderer\Textures\TextureLoader.h"
#include "Renderer\Textures\SpriteLoader.h"

#include "Simulation\SimulationManager.h"
#include "Simulation\GameState.h"
#include "Simulation\PlayerState.h"
#include "Simulation\Events\PlayerCreatedEvent.h"

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


		const char* charactersAtlasPath = "textures\\CharactersSpriteAtlas.png";
		Renderer::SpriteLoader::RegisterAtlas(charactersAtlasPath, 16, 16, 1, 1);
		
		Renderer::SpriteLoader::RegisterSprite(charactersAtlasPath, 0, 17, "Characters::Hero0");


		_world = new World();

		_idOfLocalPlayer = 0;

		Simulation::SimulationManager::Create();
		Simulation::SimulationManager::Instance().AddEvent(new Simulation::PlayerCreatedEvent(0, _idOfLocalPlayer));
		Simulation::SimulationManager::Instance().AddEvent(new Simulation::PlayerCreatedEvent(100, 74));
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::OnUpdate(float dt)
	{
		Simulation::GameState* gameState = Simulation::SimulationManager::Instance().Tick();
		
		for (auto it = gameState->_players.begin(); it < gameState->_players.end(); ++it)
		{
			Simulation::PlayerState* playerState = *it;

			if (_players.count(playerState->_id) == 0)
				_players[playerState->_id] = new Player(playerState->_id, playerState->_id == _idOfLocalPlayer);

			_players[playerState->_id]->UpdateView(playerState, dt);
		}
	}

	void GameManager::OnRender()
	{
	}
}