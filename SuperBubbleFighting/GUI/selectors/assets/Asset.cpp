#include "../../../stdafx.h"
#include "Asset.h"




void Asset::init()
{
	this->isSelect = false;
}

Asset::Asset(float x,float y,std::string path)
{
	this->init();
	this->x = x;
	this->y = y;
	if (!this->image.loadFromFile("../res/images/assets/" + path))
		std::cout << "ERROR LOADING ... : not load image from file ../res/images/assets/" << path << std::endl;
	this->texture.loadFromImage(this->image);
	this->shape.setTexture(&this->texture);
	this->shape.setSize(sf::Vector2f(this->texture.getSize().x, this->texture.getSize().y));
	this->shape.setPosition(this->x,this->y);
}

Asset::~Asset()
{
}

const bool & Asset::checkSelect() const
{
	return this->isSelect;
}

const sf::Vector2f & Asset::getPosition() const
{
	return this->shape.getPosition();
}

void Asset::update()
{
}

void Asset::render(sf::RenderWindow & window)
{
	window.draw(this->shape);
}
