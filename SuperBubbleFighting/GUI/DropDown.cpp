#include "../stdafx.h"
#include "DropDown.h"




DropDown::DropDown(float x, float y, float width, float height,sf::Font& font, std::string list[],unsigned nrOfElements, unsigned default_index)
{
	this->activeElement = new Button(
		x, y, width, height,
		&this->font, list[default_index], 14,
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);
	
	for (unsigned i = 0; i < nrOfElements; i++)
	{
		this->list.push_back(
			new Button(
				x, y + ((i + 1) * height), width, height,
				&this->font, list[i], 14,
				sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
				sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(20, 20, 20, 0),
				i
			)
		);
	}
}

DropDown::~DropDown()
{

	delete this->activeElement;
	for (size_t i = 0; i < this->list.size(); i++)
	{
		delete this->list[i];
	}

}

const unsigned short & DropDown::getActiveElementId() const
{
	return this->activeElement;
}

const bool DropDown::getKeytime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}

	return false;

}

void DropDown::updateKeytime(float time)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 10.f * time;

}

void DropDown::update(sf::Vector2f mousePos,float time)
{
	this->updateKeytime(time);

	this->activeElement->update(mousePos);

	if (this->activeElement->isPressed() && this->getKeytime())
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}

	if (this->showList)
	{
		for (auto &i : this->list)
		{
			i->update(mousePos);

			if (i->isPressed() && this->getKeytime())
			{
				this->showList = false;
				this->activeElement->setText(i->getText());
				this->activeElement->setId(i->getId());
			}
		}
	}
}


void DropDown::render(sf::RenderWindow * window)
{
	this->activeElement->render(window); 

	if (this->showList)
	{
		for (auto &i : this->list)
		{
			i->render(window);
		}
	}
}
