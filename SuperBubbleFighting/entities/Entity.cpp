#include "Entity.h"



Entity::Entity(std::string name, float x, float y, sf::Texture & texture)
{
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
}

Entity::~Entity()
{
}
