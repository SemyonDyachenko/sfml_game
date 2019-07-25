#include "MainMenuState.h"




void MainMenuState::initCursor()
{
	if (!this->textureCursor.loadFromFile("../res/images/cursor.png")) std::cout << "error load image for cursor" << "\n";
	this->cursor.setTexture(&this->textureCursor);
	this->cursor.setSize(sf::Vector2f(textureCursor.getSize()));
}

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),static_cast<float>(this->window->getSize().y)));



    if (!this->backgroundTexture.loadFromFile("../res/images/background.png"))
    {
        std::cout << "ERROR in GAMEMENUSTATE (initBackground):: ERROR LOAD TEXTURE FROM FILE";
    }

    this->background.setTexture(&this->backgroundTexture);

}

void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("../res/fonts/font.ttf"))
    {
        std::cout << "ERROR in MainMenuState class (function initFonts): NOT LOAD FONTS FROM FILE" << std::endl;
    }

}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(this->window->getSize().x/2- 100, window->getSize().y/3, 150, 45, &this->font, "SINGLE GAME", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
    this->buttons["SETTINGS_STATE"] = new Button(this->window->getSize().x / 2 - 100, window->getSize().y / 3+100, 150, 45, &this->font, "SETTINGS", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
    this->buttons["CREDITS_STATE"] = new Button(this->window->getSize().x / 2 - 100, window->getSize().y / 3 + 200, 150, 45, &this->font, "CREDITS", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
	this->buttons["EDITOR_STATE"] = new Button(this->window->getSize().x / 2 - 100, window->getSize().y / 3 + 300, 150, 45, &this->font, "MAP EDITOR", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
    this->buttons["EXIT_STATE"] = new Button(this->window->getSize().x / 2 - 100, window->getSize().y / 3 + 400, 150, 45, &this->font, "QUIT", sf::Color(255, 255, 255, 255), sf::Color(150, 150, 150, 255), sf::Color(255, 255, 255, 255));
}

MainMenuState::MainMenuState(sf::RenderWindow * window,std::stack<State*>* states) : State(window,states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initButtons();
	this->initCursor();
	window->setMouseCursorVisible(false);
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
        this->states->push(new SettingsState(this->window, this->states));
    }
	

	//editor state	
	if (this->buttons["EDITOR_STATE"]->isPressed())
	{
		this->states->push(new EditorState(this->window, this->states));
	}


    //start game
    if (this->buttons["GAME_STATE"]->isPressed() || (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) || sf::Joystick::isButtonPressed(0,9))
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

void MainMenuState::update(float time)
{
    this->updateMousePosition();
    this->updateButtons();

	this->cursor.setPosition(mousePosWindow.x,mousePosWindow.y);
}

void MainMenuState::render(sf::RenderWindow * window)
{
    if (!window)
        window = this->window;


    window->draw(background);
    this->renderButtons(window);


	window->draw(this->cursor);
}