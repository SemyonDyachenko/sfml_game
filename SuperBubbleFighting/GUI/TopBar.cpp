#include "../stdafx.h"
#include "TopBar.h"




void TopBar::initFonts()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf"))
		std::cout << " error load font" << std::endl;
}

void TopBar::initButtons()
{
	this->buttons["NEW"] = new Button(0, 0, 100, this->size.y,&this->font, "NEW", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
}

TopBar::TopBar(sf::RenderWindow * window,float x, float y)
{
	this->posX = x;
	this->posY = y;
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(window->getSize().x, 60));
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color::Red);
	this->size = shape.getSize();
	this->initFonts();
	this->initButtons();
}

TopBar::~TopBar()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void TopBar::update(sf::Vector2f mousePos)
{
	for (auto &it : this->buttons)
	{
		it.second->update(mousePos);
	}

	if (this->buttons["NEW"]->isPressed())
	{

	}
}

void TopBar::render(sf::RenderWindow * window)
{
	window->draw(this->shape);
	for (auto &it : this->buttons)
	{
		it.second->render(window);
	}
}
