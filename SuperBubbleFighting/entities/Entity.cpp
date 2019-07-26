#include "Entity.h"



Entity::Entity(float x, float y, sf::Texture & texture, MapEditor & level)
{
	this->sprite.setTexture(texture);
	this->speed = 0;
}

Entity::~Entity()
{

}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}



