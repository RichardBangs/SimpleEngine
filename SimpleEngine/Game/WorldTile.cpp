#include "WorldTile.h"

#include "Renderer\SpriteRenderable.h"

namespace Game
{
	WorldTile::WorldTile(int x, int y, const char* spriteID)
	{
		this->x = x;
		this->y = y;

		_renderable = new Renderer::SpriteRenderable(spriteID);

		_renderable->SetPosition(glm::vec3(x, y, 0.0f));
	}

	WorldTile::~WorldTile()
	{
	}
}