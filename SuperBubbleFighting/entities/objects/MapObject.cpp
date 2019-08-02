#include "../../stdafx.h"
#include "MapObject.h"



MapObject::MapObject()
{
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(95, 97, 99));
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

void MapObject::update()
{
}

void MapObject::render(sf::RenderWindow * window)
{
	window->draw(this->shape);
}

