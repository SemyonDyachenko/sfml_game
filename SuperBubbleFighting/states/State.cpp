#include "../stdafx.h"
#include "State.h"



State::State(sf::RenderWindow * window,std::stack<State*>* states)
{
    this->window = window;
    this->quit = false;
    this->states = states;
	this->gridSize = 48.f;
	this->keytime = 0.f;
	this->keytimeMax = 10.f;
}

State::~State()
{
}

const bool & State::getQuit() const
{
    return this->quit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Joystick::isButtonPressed(0,8)) 
    {
        this->quit = true;
    }
}

const bool State::getKeyTime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	
	return false;
}


void State::updateMousePosition(sf::View* view)
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);

	if(view)
	this->window->setView(*view);


    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	this->mousePosGrid =
		sf::Vector2u(
			static_cast<unsigned>(this->mousePosView.x) / static_cast<unsigned>(this->gridSize),
			static_cast<unsigned>(this->mousePosView.y) / static_cast<unsigned>(this->gridSize)
		);

	this->window->setView(this->window->getDefaultView());
}

void State::updateKeyTime(float time)
{
	if (this->keytime < this->keytimeMax)
	{
		this->keytime += 100.f*time;
	}
}
