#include "Tile.h"



Tile::Tile()
{
	this->collision = false;
	this->type = 0;
}

Tile::Tile(unsigned x, unsigned y, float gridSizeF, sf::Texture& texture, const sf::IntRect& rect,bool collision,short type)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	//this->shape.setFillColor(sf::Color::White);
	this->posX = x; this->posY = y;
	this->shape.setPosition(static_cast<float>(x)*gridSizeF,static_cast<float>(y)*gridSizeF);
//	this->shape.setOutlineThickness(1.f);
//	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setTexture(&texture);
	this->shape.setTextureRect(rect);

	this->collision = collision;
	this->type = type;
}


Tile::~Tile()
{
}

float Tile::getPositionX()
{
	return this->posX;
}

float Tile::getPositionY()
{
	return this->posY;
}

const std::string Tile::getAssString() const
{
	std::stringstream ss;
	ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " " << this->collision << " " << this->type;
	return ss.str();
}


void Tile::update()
{

}

void Tile::render(sf::RenderWindow & window)
{
	 window.draw(this->shape);
}

