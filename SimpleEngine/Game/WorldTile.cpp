#include "WorldTile.h"

#include "Renderer\SpriteRenderable.h"

namespace Game
{
	WorldTile::WorldTile(int x, int y, const char* spriteID)
	{
		this->x = x;
		this->y = y;

		_renderable = new Renderer::SpriteRenderable(spriteID, glm::vec2(1.0f, 1.0f));

		_renderable->SetPosition(glm::vec3(x, y, 0.0f));
	}

	WorldTile::~WorldTile()
	{
	}
}