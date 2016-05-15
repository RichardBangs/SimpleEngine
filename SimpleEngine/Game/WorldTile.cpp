#include "WorldTile.h"

#include "Renderer\QuadRenderable.h"

namespace Game
{
	WorldTile::WorldTile(int x, int y, const char* texturePath)
	{
		this->x = x;
		this->y = y;

		_renderable = new Renderer::QuadRenderable(texturePath);

		_renderable->SetPosition(glm::vec3(x, y, 0.0f));
		_renderable->SetSize(glm::vec2(1.0f, 1.0f));
	}

	WorldTile::~WorldTile()
	{
	}
}