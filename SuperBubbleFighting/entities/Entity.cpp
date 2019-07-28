#include "Entity.h"



Entity::Entity(float x, float y, sf::Texture & texture, MapEditor & level,std::string anim_file)
{
	this->animation.loadFromXML(anim_file, texture);
}

Entity::~Entity()
{

}

const sf::Vector2f & Entity::getPosition() const
{
	return this->sprite.getPosition();
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}



