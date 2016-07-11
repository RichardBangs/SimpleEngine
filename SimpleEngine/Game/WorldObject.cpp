#include "WorldObject.h"

#include "Renderer\SpriteRenderable.h"

namespace Game
{
	WorldObject::WorldObject(int id, int x, int y, const char* spriteID)
	{
		this->_id = id;

		this->_x = x;
		this->_y = y;
		
		_renderable = new Renderer::SpriteRenderable(spriteID, glm::vec2(0.1f, 0.1f));

		_renderable->SetPosition(glm::vec3((float)x / 10, (float)y / 10, -0.5f));
	}

	WorldObject::~WorldObject()
	{
		delete _renderable;
	}
}
