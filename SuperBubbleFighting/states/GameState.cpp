#include "GameState.h"






void GameState::initLevels()
{
}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states)
	: State(window, states)
{
	this->window = window;
	this->window->setMouseCursorVisible(false);
}
	
GameState::~GameState()
{
    this->window->setView(window->getDefaultView());
}

void GameState::endState()
{
    std::cout << " end game state" << std::endl;
}


void GameState::updateInput(const float & time)
{
    this->checkForQuit();
}

void GameState::update(float time)
{
    this->updateMousePosition();
    this->updateInput(time);
}

void GameState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

}