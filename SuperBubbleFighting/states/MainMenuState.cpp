#include "MainMenuState.h"




void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),static_cast<float>(this->window->getSize().y)));



    if (!this->backgroundTexture.loadFromFile("../res/images/background.jpg"))
    {
        std::cout << "ERROR in GAMEMENUSTATE (initBackground):: ERROR LOAD TEXTURE FROM FILE";
    }

  //  this->background.setTexture(&this->backgroundTexture);
  this->background.setFillColor(sf::Color(0,0,0));
}

void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("../res/fonts/ftm.ttf"))
    {
        std::cout << "ERROR in MainMenuState class (function initFonts): NOT LOAD FONTS FROM FILE" << std::endl;
    }

}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(10, 10, this->window->getSize().x/2-20, this->window->getSize().y/2-20, &this->font, "SINGLE GAME", sf::Color(221, 59, 59, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->buttons["SETTINGS_STATE"] = new Button(this->window->getSize().x/2,10, this->window->getSize().x/2-20, this->window->getSize().y/2-20, &this->font, "SETTINGS", sf::Color(78, 113, 183, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->buttons["ONLINE_STATE"] = new Button(10, this->window->getSize().y/2, this->window->getSize().x/2-20, this->window->getSize().y/2-20, &this->font, "ONLINE", sf::Color(247, 119, 69, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->buttons["EXIT_STATE"] = new Button(this->window->getSize().x/2,this->window->getSize().y/2,this->window->getSize().x/2-20, this->window->getSize().y/2-20, &this->font, "QUIT", sf::Color(65, 147, 59, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow * window,std::stack<State*>* states) : State(window,states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initButtons();

}

MainMenuState::~MainMenuState()
{
    auto it = this->buttons.begin();
    for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
    {
        delete it->second;
    }
}

void MainMenuState::endState()
{
    std::cout << " end MainMenu state" << std::endl;
}

void MainMenuState::updateInput(const float & dt)
{
    this->checkForQuit();
}

void MainMenuState::updateButtons()
{
    for  (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }


    //start game
    if (this->buttons["SETTINGS_STATE"]->isPressed())
    {
        //	this->states->push(new SettingsState(this->window, this->states));
    }


    //start game
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window,this->states));
    }


    //exit
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
        this->window->close();
    }

}

void MainMenuState::renderButtons(sf::RenderWindow * window)
{
    for (auto &it : this->buttons)
    {
        it.second->render(window);
    }

}

void MainMenuState::update(const float & dt)
{
    this->updateMousePosition();
    this->updateButtons();
}

void MainMenuState::render(sf::RenderWindow * window)
{
    if (!window)
        window = this->window;


    window->draw(background);
    this->renderButtons(window);
}