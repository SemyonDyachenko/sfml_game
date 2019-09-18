#include "stdafx.h"
#include "Game.h"
#include "resource/SettingsParsers.h"

void Game::initWindow()
{
	/*SettingsParser*/
	SettingsParsers setParser;
	if (!setParser.loadFromFile("../Data/config.ini"))
	{
		std::cout << "error load settings file!" << std::endl;
	}

    /* here init and create window */
    this->vertical_sync_enable = false;
    this->FrameRateLimit = 120;
    this->winSizeX = 1920; // GetSystemMetrics(SM_CXSCREEN)
    this->winSizeY = 1080; // GetSystemMetrics(SM_CYSCREEN)
    this->winTitle = "Super Bubble Fighting";

	

	setParser.set("title", this->winTitle);
	setParser.set("width",std::to_string(winSizeX));
	setParser.set("height", std::to_string(winSizeY));
	setParser.set("FrameLimit", std::to_string(this->FrameRateLimit));
	setParser.set("vsync", this->vertical_sync_enable);
	setParser.saveToFile();

    this->window = new sf::RenderWindow(sf::VideoMode(winSizeX, winSizeY), winTitle,sf::Style::Titlebar);
    this->window->setVerticalSyncEnabled(this->vertical_sync_enable);
    this->window->setFramerateLimit(this->FrameRateLimit);
    this->window->setPosition(sf::Vector2i(0,0));



	
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window,&this->states));
}

Game::Game()
{
    this->initWindow();
    this->initStates();

}


Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication()
{
    std::cout << "Ending App" << std::endl;
}

void Game::updateDeltaTime()
{
    this->time = float(this->clock.getElapsedTime().asMicroseconds());
    clock.restart();
    time = time / 800;

}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->event)) {

        if (this->event.type == sf::Event::Closed)
            this->window->close();

    }
}

void Game::update()
{
    this->updateEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->time);

        if (this->states.top()->getQuit())
        {

            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
        //App end
    else {
        this->window->close();
        this->endApplication();
    }
}

void Game::render()
{
    //clear
	this->window->clear();

    //render here
    if (!this->states.empty()) {
        this->states.top()->render(this->window);
    }


    // display
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen()) {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}