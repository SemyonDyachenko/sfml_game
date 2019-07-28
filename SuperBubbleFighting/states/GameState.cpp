#include "GameState.h"



void GameState::initView()
{
	this->view.setSize(sf::Vector2f(
		this->window->getSize().x,
		this->window->getSize().y
	));

	this->view.setCenter(sf::Vector2f(
		this->window->getSize().x / 2.f,
		this->window->getSize().y / 2.f
	));

	this->view.zoom(0.5);
}

void GameState::initTileMap()
{
	this->tilemap = new MapEditor(this->window, "../res/images/tileset.png");
	this->tilemap->loadFromFile("text.slmp");
}

void GameState::initTextures()
{
	if (!this->playerTexture.loadFromFile("../res/images/heroes/hero.png")) 
		std::cout << "ERROR: don't load image from file in GameState.cpp , line 26\n";
}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states)
	: State(window, states)
{
	this->window = window;
	this->window->setMouseCursorVisible(false);
	this->initView();
	this->initTileMap();
	this->initTextures();
	this->player = new Player(250, 500, playerTexture,*this->tilemap, "../res/animation/anim.xml");

}
	
GameState::~GameState()
{
    delete this->player;
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

void GameState::updateView(float time)
{
	this->view.setCenter(this->player->getPosition().x,this->player->getPosition().y);
}

void GameState::update(float time)
{
    this->updateMousePosition(&this->view);
    this->updateInput(time);
	this->updateView(time);
    this->player->update(time);
	this->tilemap->update(time);
}

void GameState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;


	window->setView(this->view);
	this->tilemap->render(*window);
	this->player->render(window);
}