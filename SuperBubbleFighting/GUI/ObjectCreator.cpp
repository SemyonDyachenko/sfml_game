#include "../stdafx.h"
#include "ObjectCreator.h"


ObjectCreator::ObjectCreator(sf::RenderWindow * window)
{
	this->window = window;
	this->creationWindow.setSize(sf::Vector2f(400, 400));
	this->creationWindow.setPosition(window->getSize().x/2-400/2, window->getSize().y / 2-400/2);
	this->enterField.setSize(sf::Vector2f(140, 40));
	this->enterField.setPosition(creationWindow.getPosition().x+120, this->creationWindow.getPosition().y+this->creationWindow.getSize().y/2);
	this->enterField.setFillColor(sf::Color(255, 255, 255));
	this->creationWindow.setFillColor(sf::Color(50, 50, 50, 100));
	this->creationWindow.setOutlineThickness(1.f);
	this->creationWindow.setOutlineColor(sf::Color(255, 255, 255, 200));

	this->font.loadFromFile("../res/fonts/font.ttf");
	this->text.setFont(font);

	this->name = "default";
	this->text.setString(name);

	this->isHide = true;

	this->buttons["CREATE"] = new Button(creationWindow.getSize().x / 4, enterField.getPosition().y + 50, 80, 40, &this->font,"CREATE", sf::Color(255, 255, 255), sf::Color(255, 255, 255), sf::Color(255, 255, 255));
	this->buttons["EXIT"] = new Button(creationWindow.getSize().x / 4+100, enterField.getPosition().y + 50, 80, 40, &this->font,"EXIT", sf::Color(255, 255, 255), sf::Color(255, 255, 255), sf::Color(255, 255, 255));
}


ObjectCreator::~ObjectCreator()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void ObjectCreator::setHide(bool hide)
{
	this->isHide = hide;
}

const bool & ObjectCreator::getHide() const
{
	return this->isHide;
}

void ObjectCreator::update(sf::Vector2f mousePos)
{
	if (!isHide)
	{
		for (auto &it : this->buttons)
		{
			if (this->isHide)
			{
				it.second->update(mousePos);

			}
		}
		
	

		if (this->buttons["CREATE"]->isPressed())
		{

		}

		if (this->buttons["EXIT"]->isPressed())
		{

		}
	}
}

void ObjectCreator::render(sf::RenderWindow * window)
{
	if (!isHide)
	{
		window->draw(creationWindow);
		window->draw(enterField);

		for (auto &it : this->buttons)
		{
			if (this->isHide)
			{
				it.second->render(window);

			}
		}
	}
	window->draw(this->text);
}
