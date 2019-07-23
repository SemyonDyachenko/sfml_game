#include "State.h"




State::State(sf::RenderWindow * window,std::stack<State*>* states)
{
    this->window = window;
    this->quit = false;
    this->states = states;
    //this->supportedKeys = supportedKeys;
	this->gridSize = 32.f;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Joystick::isButtonPressed(0,8)) /* åñëè íàæàòà êëàâèøà escape òî ñîñòîÿíèå ïåðåìåííîé âûõîäà  = true òî åñòü ìû âûøëè èç ñîñòîÿíèÿ (state) */
    {
        this->quit = true;
    }
}


void State::updateMousePosition()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}
