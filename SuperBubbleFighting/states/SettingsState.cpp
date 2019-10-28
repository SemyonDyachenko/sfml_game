#include "../stdafx.h"
#include "SettingsState.h"



void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf"))
	{
		std::cout << "ERROR in SettingsState class (function initFonts): NOT LOAD FONTS FROM FILE" << std::endl;
	}
}

void SettingsState::initButtons()
{
	this->buttons["APPLY"] = new Button(this->window->getSize().x - 380, this->window->getSize().y - 10, 150, 45,
	&this->font, "Apply", sf::Color(255, 255, 255, 100), sf::Color(255, 255, 255, 100), sf::Color(255, 255, 255, 100));
	this->buttons["CANCEL"] = new Button(this->window->getSize().x - 180, this->window->getSize().y - 10, 150, 45, 
	&this->font, "Cancel", sf::Color(255, 255, 255, 100), sf::Color(255, 255, 255, 100), sf::Color(255, 255, 255, 100));
}

void SettingsState::initGui()
{
}

void SettingsState::initText()
{
	this->optionsText.setFont(this->font);

	this->optionsText.setPosition(sf::Vector2f(100.f, 100.f));

	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	this->optionsText.setCharacterSize(30);

	this->optionsText.setString(
		"FullScreen \nResolution \nVsync \n\n"
	);
}

SettingsState::SettingsState(sf::RenderWindow * window, std::stack<State*>* states)
	: State(window,states)
{
	this->window = window;
	this->initVariables();
	this->initFonts();
	this->initButtons();
	this->initText();
}


SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void SettingsState::endState()
{
	std::cout << "End Settings State" << std::endl;
}

void SettingsState::updateInput(const float & time)
{
	this->checkForQuit();
}

void SettingsState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}




	//apply and exit
	if (this->buttons["APPLY"]->isPressed())
	{
		
	}

	//cancel (exit)
	if (this->buttons["CANCEL"]->isPressed())
	{

	}


}

void SettingsState::update(float time)
{
	this->updateInput(time);
	this->updateButtons();
	
}

void SettingsState::renderButtons(sf::RenderWindow * window)
{
	for (auto &it : this->buttons)
	{
		it.second->render(window);
	}
}

void SettingsState::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

	this->renderButtons(window);
	window->draw(this->optionsText);
}
