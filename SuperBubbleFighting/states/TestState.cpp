#include "TestState.h"



void TestState::initFonts()
{
	if (this->font.loadFromFile("../res/fonts/font.ftm")) std::cout << "ERROR: in test state don't load font from file \n";
}

void TestState::initButtons()
{
	this->buttons["PLAYER"] = new Button(10, 10, 150, 45, &this->font, "Play", sf::Color(0, 255, 0, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["STOP"] = new Button(10, 100, 150, 45, &this->font, "Stop", sf::Color(255, 0, 0, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

TestState::TestState(sf::RenderWindow * window, std::stack<State*>* states)
	: State(window, states)
{
	this->initFonts();
	this->initButtons();
}


TestState::~TestState()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void TestState::endState()
{
	std::cout << "end test state" << std::endl;
}

void TestState::updateInput(const float & time)
{

}

void TestState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["PLAY"]->isPressed())
	{

	}

	if (this->buttons["STOP"]->isPressed())
	{

	}



}

void TestState::update(float time)
{
	this->updateInput(time);
	this->updateButtons();
}

void TestState::renderButtons(sf::RenderWindow * window)
{
	for (auto &it : this->buttons)
	{
		it.second->render(window);
	}
}

void TestState::render(sf::RenderWindow * window)
{
	window->draw(this->workingScene);
	this->renderButtons(window);
}
