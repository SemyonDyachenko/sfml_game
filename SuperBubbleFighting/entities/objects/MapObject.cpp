#include "../../stdafx.h"
#include "MapObject.h"



MapObject::MapObject()
{
}

MapObject::MapObject(float x, float y,float gridSizeF,std::string name)
{
	this->shape.setPosition(static_cast<float>(x)*gridSizeF,static_cast<float>(y)*gridSizeF);
	this->shape.setSize(sf::Vector2f(static_cast<float>(gridSizeF), static_cast<float>(gridSizeF)));
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(95, 97, 99));
}


MapObject::~MapObject()
{

}

const sf::FloatRect & MapObject::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

const std::string & MapObject::getName() const
{
	return this->name;
}

const std::string MapObject::getAssString() const
{
	std::stringstream ss;
	ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " " << this->name;
	return ss.str();
}

void MapObject::update()
{
}

void MapObject::render(sf::RenderWindow & window)
{
	window.draw(this->shape);
}

