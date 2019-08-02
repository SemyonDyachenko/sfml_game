#include "../stdafx.h"
#include "SettingsState.h"



void SettingsState::initVariables()
{
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
	this->buttons["RESOLUTION"] = new Button(10, 10, 150, 45, &this->font, "Resulotin", sf::Color(221, 59, 59, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["VSYNC"] = new Button(10, 100, 150, 45, &this->font, "VSYNC", sf::Color(78, 113, 183, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["FULL_SCREEN"] = new Button(10, 200, 150, 45, &this->font, "Full Screen", sf::Color(247, 119, 69, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["APPLY"] = new Button(10, 300, 150, 45, &this->font, "Apply", sf::Color(247, 119, 69, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["CANCEL"] = new Button(10, 400, 150, 45, &this->font, "Cancel", sf::Color(65, 147, 59, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

SettingsState::SettingsState(sf::RenderWindow * window, std::stack<State*>* states)
	: State(window,states)
{
	this->initVariables();
	this->initFonts();
	this->initButtons();
	
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


	// change resolution
	if (this->buttons["RESOLUTION"]->isPressed())
	{
		
	}


	// vsync
	if (this->buttons["VSYNC"]->isPressed())
	{
		
	}


	//full screen mode
	if (this->buttons["FULL_SCREEN"]->isPressed())
	{
		
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
}
