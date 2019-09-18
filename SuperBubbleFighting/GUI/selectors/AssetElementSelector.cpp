#include "../../stdafx.h"
#include "AssetElementSelector.h"



AssetElementSelector::AssetElementSelector(float x, float y, float width, float height,sf::Font&font, std::string source_folder_path)
{
	this->shape.setSize(sf::Vector2f(width, height));
	this->width = width;
	this->height = height;
	this->shape.setPosition(x, y);
	this->x = x;
	this->y = y;
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(255, 255, 255));
	this->shape.setFillColor(sf::Color(sf::Color(20,20,20)));


	this->str = "assets selection";
	this->label.setFont(font);
	this->label.setFillColor(sf::Color(255, 255, 255));
	this->label.setCharacterSize(20);
	this->label.setString(str);
	this->label.setPosition(x, y);

	this->sourceFolder = source_folder_path;

	this->isHide = false;
}

AssetElementSelector::~AssetElementSelector()
{
}

void AssetElementSelector::show()
{
	this->isHide = false;
}

void AssetElementSelector::hide()
{
	this->isHide = true;
}

const bool & AssetElementSelector::getHide() const
{
	return this->isHide;
}

void AssetElementSelector::update()
{
}

void AssetElementSelector::render(sf::RenderWindow* window)
{
	if (this->isHide!=true)
	{
		window->draw(this->shape);
		window->draw(this->label);
	}
}
