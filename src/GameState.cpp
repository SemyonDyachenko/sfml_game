#include "GameState.h"



void GameState::initTextures()
{
    if (!this->backgroundTexture.loadFromFile("../res/images/background.png")) { std::cout << "error load img background!" << std::endl; }
    this->backgroundShape.setTexture(&this->backgroundTexture);

    if(!this->groundTexture.loadFromFile("../res/images/ground.png")) {std::cout << "error load img for ground ..!!" << "\n"; }
    this->ground.setTexture(&this->groundTexture);


}

GameState::GameState(sf::RenderWindow * window, std::stack<State*>*states) : State(window, states)
{
    this->window = window;
    this->window->setMouseCursorVisible(false);
    this->backgroundShape.setPosition(0, 0);
    this->backgroundShape.setSize(sf::Vector2f(static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y)));
    this->initTextures();
    this->ground.setSize(sf::Vector2f(this->window->getSize().x,groundTexture.getSize().y));
    this->ground.setPosition(0,this->window->getSize().y - this->groundTexture.getSize().y/2);
    this->player = new Player("../res/images/hero.png",500,ground.getPosition().y-96);
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
    this->player->update(time);
}

void GameState::render(sf::RenderWindow * window)
{
    if (!window)
        window = this->window;

    window->popGLStates();
    window->draw(this->backgroundShape);
    window->pushGLStates();
    window->draw(this->ground);
    this->player->render(window);

}
