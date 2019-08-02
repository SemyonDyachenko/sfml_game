#include "../stdafx.h"
#include "GameState.h"




void GameState::initLevels()
{
	for (size_t i = 0; i < level_count;i++)
	{
		levels.push_back(new Level(*this->window, "text.slmp", "../res/images/background.png"));
	}
}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states)
	: State(window, states)
{
	this->window = window;
	this->window->setMouseCursorVisible(false);
	this->initLevels();
}
	
GameState::~GameState()
{
    this->window->setView(window->getDefaultView());

	for (size_t i = 0;i < levels.size();i++)
	{
		delete levels[i];
	}
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


	for (size_t i = 0; i < levels.size(); i++)
	{
		if (levels[i] != NULL)
		{
			if (!this->levels[i]->checkEnd())
				levels[i]->update(time);
			else
				levels[i + 1]->update(time);
		}
	}
}

void GameState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

	
		if (!levels[0]->checkEnd())
		{
			if (levels[0] != NULL)
			{
				levels[0]->render(window);
			}
		}
		else
		{
			for (size_t i = 1; i < levels.size(); i++)
			{
				if (levels[i] != NULL)
				{

					if (!levels[i]->checkEnd())
					{
						this->levels[i]->render(window);
					}
					else
					{
						this->levels[i + 1]->render(window);
					}
				}
			}
		}
}