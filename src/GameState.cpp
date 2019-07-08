#include "GameState.h"



void GameState::initTextures()
{
	if (!this->backTexture.loadFromFile("../res/images/background.png")) { std::cout << "error load img background!" << std::endl; }
	this->background.setTexture(&this->backTexture);

	if (!this->groundTexture.loadFromFile("../res/images/ground.png")) { std::cout << "error load img for ground ..!!" << "\n"; }
	this->ground.setTexture(&this->groundTexture);

}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states) : State(window, states)
{
    this->window = window;
	this->viewSizeX = this->window->getSize().x*1.2;
	this->viewSizeY = this->window->getSize().y*1.2;
    this->window->setMouseCursorVisible(false);
    this->initTextures();
	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(viewSizeX, viewSizeY));
	this->ground.setSize(sf::Vector2f(groundTexture.getSize().x, groundTexture.getSize().y));
	this->ground.setPosition((viewSizeX - groundTexture.getSize().x)/2, viewSizeY/2+200);
    this->player = new Player(this->window,"../res/images/hero.png",viewSizeX/2,100);
    this->player->view.reset(sf::FloatRect(0,0, viewSizeX, viewSizeY));
    this->musicpath = "../res/music/backMusic1.ogg";
    if(!this->music.openFromFile(this->musicpath)) {std::cout << "error open music "<< "\n";}
    this->music.setLoop(true);
    this->music.setVolume(15);
    this->music.play();
}


GameState::~GameState()
{

    delete this->player;
    this->window->setView(window->getDefaultView());
    this->window->setMouseCursorVisible(true);
}

void GameState::endState()
{
    std::cout << " end game state" << std::endl;
}


void GameState::updateInput(const float & time)
{
    this->checkForQuit();

}

void GameState::update(const float& time)
{
    this->pixelPos = sf::Mouse::getPosition(*window);
    this->pos = window->mapPixelToCoords(pixelPos);
    this->updateMousePosition();
    this->updateInput(time);
    this->player->update(time,&ground);
    this->window->setView(this->player->view);
	
}

void GameState::render(sf::RenderWindow * window)
{
    if (!window)
        window = this->window;

	window->draw(this->background);
	window->draw(this->ground);
    this->player->render(window);

}
