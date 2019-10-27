#include "../stdafx.h"
#include "PlayerHealtBar.h"


void PlayerHealtBar::initText()
{
	this->text.setCharacterSize(18);
	this->text.setFillColor(sf::Color::White);
	this->font.loadFromFile("../res/fonts/sans.otf");
	this->text.setFont(font);
	
}

PlayerHealtBar::PlayerHealtBar()
{
	this->initText();
	this->texture.loadFromFile("../res/images/healtbar/bar.png");
	this->bar.setTexture(&texture);
	this->bar.setSize(sf::Vector2f(this->texture.getSize().x, this->texture.getSize().y));

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
			deathBar.setSize(sf::Vector2f((max - healthcount) * 70 / max, bar.getSize().y));
		}
	}

	this->string = std::to_string(healthcount)+"%";
	this->text.setString(this->string);
}

void PlayerHealtBar::render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	bar.setPosition(window->getView().getCenter().x-window->getSize().x/2+30, window->getView().getCenter().y-window->getSize().y/2+40);
	deathBar.setPosition(bar.getPosition().x,bar.getPosition().y);

	this->text.setPosition(bar.getPosition().x + 50, bar.getPosition().y -5);

	window->draw(bar);
	window->draw(deathBar);
	window->draw(this->text);
	
}

