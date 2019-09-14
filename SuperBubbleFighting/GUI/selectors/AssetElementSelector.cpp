#include "../../stdafx.h"
#include "AssetElementSelector.h"



AssetElementSelector::AssetElementSelector(float x, float y, float width, float height,sf::Font&font)
{
	this->shape.setSize(sf::Vector2f(width, height));
	this->width = width;
	this->height = height;
	this->shape.setPosition(x, y);
	this->x = x;
	this->y = y;
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(255, 255, 255, 200));
	this->shape.setFillColor(sf::Color(50, 50, 50, 500));


	this->str = "assets selection";
	this->label.setFont(font);
	this->label.setFillColor(sf::Color(255, 255, 255));
	this->label.setCharacterSize(20);
	this->label.setString(str);
	this->label.setPosition(x, y);
}

AssetElementSelector::~AssetElementSelector()
{
}

void AssetElementSelector::update()
{
}

void AssetElementSelector::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
	window->draw(this->label);
}
