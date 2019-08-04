#include "../stdafx.h"
#include "DropDown.h"



DropDown::DropDown(std::map<std::string, Button*> buttons)
{
	this->buttons = buttons;
}

DropDown::~DropDown()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void DropDown::setDrop(bool drop)
{
	this->isDrop = drop;
}



void DropDown::update(sf::Vector2f mousePos)
{

	
		for (auto &it : this->buttons)
		{
			if (isDrop)
			{
			it.second->update(mousePos);
			}
		}	
}

void DropDown::renderButtons(sf::RenderWindow * window)
{
	for (auto &it : this->buttons)
	{
		it.second->render(window);
	}

}

void DropDown::render(sf::RenderWindow * window)
{
	if (isDrop)
		this->renderButtons(window);

}
