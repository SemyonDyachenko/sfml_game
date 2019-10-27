#include "../stdafx.h"
#include "PlayerHealtBar.h"


PlayerHealtBar::PlayerHealtBar()
{
	this->texture.loadFromFile("../res/images/healtbar/bar.png");
	this->bar.setTexture(&texture);

	this->deathBar.setFillColor(sf::Color::Black);
	this->max = 100;
}


PlayerHealtBar::~PlayerHealtBar()
{
}


void PlayerHealtBar::update(int healthcount)
{
	if(healthcount >0)
	{
		if(healthcount<this->max)
		{
			deathBar.setSize(sf::Vector2f(10, (max - healthcount) * 70 / max));
		}
	}
}

void PlayerHealtBar::render(sf::RenderWindow* window)
{
	bar.setPosition(window.);
	deathBar.setPosition(window->getView().getCenter().x - window->getSize().x / 2 + 14, window->getView().getCenter().y - window->getSize().y / 2 + 14);

	window->draw(bar);
	window->draw(deathBar);
}

