#include "EditorState.h"





void EditorState::initTextures()
{
	if (!this->tileset.loadFromFile("../res/images/tileset1.png")) std::cout << "error in EditorState.cpp , don't load tileset texture" << std::endl;
}

void EditorState::initGui()
{
	this->textureSelector = new TextureSelector(0.f, 0.f, 600.f, 300.f,this->gridSize,&this->tileset,"TS");
}

void EditorState::initVariables()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf")) std::cout << "ERROR: don't load font from file, EditorState.cpp line 8" << "\n";
	this->text.setFont(font);
	
	this->textureRect = sf::IntRect(this->gridSize, 0,static_cast<int>(this->gridSize),static_cast<int>(this->gridSize));
}

void EditorState::initSelector()
{
	this->mouseSelector.setSize(sf::Vector2f(this->gridSize,this->gridSize));

	this->mouseSelector.setFillColor(sf::Color(199, 123, 142));

	this->mouseSelector.setOutlineThickness(2.f);
	this->mouseSelector.setOutlineColor(sf::Color(61, 59, 59));
}


EditorState::EditorState(sf::RenderWindow * window, std::stack<State*>* states) : State(window,states)
{
	this->initTextures();
	this->initVariables();
	this->initSelector();
	this->window = window;
	this->window->setMouseCursorVisible(false);
	this->text.setCharacterSize(14);
	this->text.setFillColor(sf::Color(119, 119, 119));
	this->map = new MapEditor(window,"../res/images/tileset1.png");
	this->mouseSelector.setTexture(&this->map->getTextureSheet());
	this->mouseSelector.setTextureRect(this->textureRect);
	this->initGui();
}

EditorState::~EditorState()
{
	this->window->setMouseCursorVisible(true);
	delete this->map;
	delete this->textureSelector;
}

void EditorState::endState()
{
}

void EditorState::updateInput(const float & time)
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->map->saveToFile("text.slmp");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		this->map->loadFromFile("text.slmp");
	}
}

void EditorState::update(float time)
{
	this->updateMousePosition();
	this->mousePosGrid =
		sf::Vector2u(
			static_cast<unsigned>(this->pos.x) / static_cast<unsigned>(this->gridSize),
			static_cast<unsigned>(this->pos.y) / static_cast<unsigned>(this->gridSize)
		);
	//updateGui
	this->textureSelector->update(this->mousePosWindow);
	//if(this->textureSelector->getActive())
	//{
		this->mouseSelector.setTextureRect(this->textureRect);
		this->mouseSelector.setPosition(this->mousePosGrid.x*this->gridSize, this->mousePosGrid.y*this->gridSize);
	//}
	

	this->updateInput(time);
	this->pixelPos = sf::Mouse::getPosition(*this->window);
	this->pos = window->mapPixelToCoords(pixelPos);
	this->string = "x:" + std::to_string(pos.x) + "  y:" + std::to_string(pos.y);
	this->text.setString(this->string);
	this->text.setPosition(pos.x, pos.y-20);
	this->map->update(time);

	

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (!this->textureSelector->getActive())
		{
			this->map->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect);
		}
		else 
		{
			this->textureRect = this->textureSelector->getTextureRect();
			this->mouseSelector.setTextureRect(textureRect);
		}
	
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		if (!this->textureSelector->getActive())
		{
		this->map->removeTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
		}
	}

}

void EditorState::render(sf::RenderWindow * window)
{
	this->map->render(*window);

	if (!this->textureSelector->getActive())
	{
		window->draw(this->mouseSelector);
	}
	//render GUI
	this->textureSelector->render(*window);
	window->draw(text);
}
