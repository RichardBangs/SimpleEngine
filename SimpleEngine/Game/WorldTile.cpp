#include "WorldTile.h"

#include "Renderer\SpriteRenderable.h"

namespace Game
{
	WorldTile::WorldTile(int x, int y, const char* spriteID)
	{
		this->x = x;
		this->y = y;

		_renderable = new Renderer::SpriteRenderable(spriteID, glm::vec2(0.1f, 0.1f));

		_renderable->SetPosition(glm::vec3((float)x/10, (float)y/10, 0.0f));
	}

	WorldTile::~WorldTile()
	{
	}
}