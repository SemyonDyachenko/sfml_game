#include "../../stdafx.h"
#include "MapObject.h"



MapObject::MapObject()
{
}

void MapObject::initFonts() 
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf"))
		std::cout << "error load font from file for MapObject ... \n";
}

MapObject::MapObject(float x, float y,float gridSizeF,std::string name)
{
	this->initFonts();
	this->shape.setPosition(static_cast<float>(x)*gridSizeF,static_cast<float>(y)*gridSizeF);
	this->shape.setSize(sf::Vector2f(static_cast<float>(gridSizeF), static_cast<float>(gridSizeF)));
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(95, 97, 99));
	this->name = name;
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color(90, 90, 90));
	this->text.setString(name);
	this->text.setPosition(this->shape.getPosition().x, this->shape.getPosition().y - 20);
	this->rect = sf::FloatRect(x*gridSizeF, y*gridSizeF, gridSizeF, gridSizeF);
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
	ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " ";
	return ss.str();
}

void MapObject::update()
{
}

void MapObject::render(sf::RenderWindow & window)
{
	window.draw(this->shape); 
	window.draw(this->text);
}

