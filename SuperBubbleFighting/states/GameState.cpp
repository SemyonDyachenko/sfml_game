#include "GameState.h"





void GameState::initTextures()
{
	if (!this->groundTexture.loadFromFile("../res/images/ground.png")) { std::cout << "error load img for ground ..!!" << "\n"; }
	this->ground.setTexture(&this->groundTexture);

	if (!this->enemyTexture.loadFromFile("../res/images/skeleton.png")) std::cout << "error load texture from file for enemy" << "\n";

}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states)
	: State(window, states)
{
    this->window = window;
    this->window->setMouseCursorVisible(false);
    this->initTextures();
	//this->initAnimations();
	this->ground.setSize(sf::Vector2f(groundTexture.getSize().x, groundTexture.getSize().y));
	this->ground.setPosition((viewSizeX - groundTexture.getSize().x)/2,800);
    this->player = new Player(this->window,"../res/images/heroes/hero.png",window->getSize().x/2,100);
    this->player->view.reset(sf::FloatRect(0,0, window->getSize().x, window->getSize().y));
	this->player->view.zoom(0.5);
}


GameState::~GameState()
{
    delete this->player;

	/*if (skeletons.size() != 0)
	{

		for (size_t i = 0; i < skeletons.size(); i++)
		{
			if (this->skeletons[i]->checkLife()==true)
			{
				delete this->skeletons[i];
			}
		}
	}
	
	*/
    this->window->setView(window->getDefaultView());
  //  this->window->setMouseCursorVisible(true);
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
    this->player->update(time,&ground,this->skeletons);
    this->window->setView(this->player->view);

	this->player->view.setCenter(this->player->getPositionX()+20,this->player->getPositionY());

/*
	if (skeletons.size() != 0)
	{
		for (size_t i = 0; i < skeletons.size(); i++)
		{
			if (this->skeletons[i]->checkLife() == false)
			{
				delete skeletons[i];
			}
			else if(this->skeletons[i]->checkLife() == true)
			{
				skeletons[i]->update(time, &ground);
			}
		}
		
	}
	*/
}

void GameState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;


	this->player->render(window);
	window->draw(this->ground);

	/*if (this->skeletons.size() != 0)
	{
		for (size_t i = 0; i < skeletons.size(); i++)
		{
			if (skeletons[i]->checkLife() == true)
			{
				skeletons[i]->render(window);
			}
		}
	}
	*/
}