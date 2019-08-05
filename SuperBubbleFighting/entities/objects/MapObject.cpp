#include "../../stdafx.h"
#include "MapObject.h"



MapObject::MapObject(float x, float y,std::string name)
{
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(95, 97, 99));
	this->shape.setPosition(x, y);
}


MapObject::~MapObject()
{

}

void MapObject::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
	this->posX = x;
	this->posY = y;
}

void MapObject::setSize(const float width, const float height)
{
	this->shape.setSize(sf::Vector2f(width, height));
	this->width = width;
	this->height = height;
}

const sf::FloatRect & MapObject::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

const std::string & MapObject::getName() const
{
	return this->name;
}

void MapObject::update()
{
}

void MapObject::render(sf::RenderWindow * window)
{
	window->draw(this->shape);
}

