#include "../stdafx.h"
#include "EditorState.h"


void EditorState::initView()
{
	this->editorView.setSize(sf::Vector2f(
		this->window->getSize().x,
		this->window->getSize().y
	));

	this->editorView.setCenter(
		this->window->getSize().x /2.f,
		this->window->getSize().y / 2.f
	);
}

void EditorState::initTextures()
{
	if (!this->tileset.loadFromFile("../res/images/tileset.png")) std::cout << "error in EditorState.cpp , don't load tileset texture" << std::endl;
}

void EditorState::initGui()
{
	this->textureSelector = new TextureSelector(0.f, 0.f, 600.f, 600.f,this->gridSize,&this->tileset,"TS");
}

void EditorState::initVariables()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf")) std::cout << "ERROR: don't load font from file, EditorState.cpp line 8" << "\n";
	this->text.setFont(font);
	
	this->textureRect = sf::IntRect(this->gridSize, 0,static_cast<int>(this->gridSize),static_cast<int>(this->gridSize));

	this->collision = false;
	this->type = TileTypes::DEFAULT;
	this->cameraSpeed = 0.3f;


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
	this->window = window;
	this->initView();
	this->initTextures();
	this->initVariables();
	this->initSelector();
	this->window->setMouseCursorVisible(false);
	this->text.setCharacterSize(14);
	this->text.setFillColor(sf::Color(119, 119, 119));
	this->map = new MapEditor(window,"../res/images/tileset.png");
	this->mouseSelector.setTexture(&this->map->getTextureSheet());
	this->mouseSelector.setTextureRect(this->textureRect);
	this->initGui();
}

EditorState::~EditorState()
{
	delete this->map;
	delete this->textureSelector;
	this->window->setView(this->window->getDefaultView());
}

void EditorState::endState()
{
	std::cout << "end editor state" << "\n";
}

void EditorState::updateInput(const float & time)
{
	this->checkForQuit();

	// save/load keybinds
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->map->saveToFile("text.slmp");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		this->map->loadFromFile("text.slmp");
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->getKeyTime())
	{
		if (this->collision)
			this->collision = false;
		else
			this->collision = true;
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && this->getKeyTime())
	{
		if (this->textureSelector->getHide())
			this->textureSelector->setHide(false);
		else
			this->textureSelector->setHide(true);
	}


}

void EditorState::updateView(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->editorView.move(this->cameraSpeed*time, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->editorView.move(-this->cameraSpeed*time, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->editorView.move(0,this->cameraSpeed*time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->editorView.move(0, -this->cameraSpeed*time);
	}

}

void EditorState::update(float time)
{
	this->updateMousePosition(&this->editorView);
	this->updateKeyTime(time);
	this->updateInput(time);
	//update view
	this->updateView(time);
	//updateGui
	this->textureSelector->update(this->mousePosWindow);
	this->mouseSelector.setTextureRect(this->textureRect);	
	this->mouseSelector.setPosition(this->mousePosGrid.x*this->gridSize, this->mousePosGrid.y*this->gridSize);

	

	
	this->string = "x:" + std::to_string(this->mousePosWindow.x) + "\n" + "y:" + std::to_string(this->mousePosWindow.y) + "\n" + "collision: " + std::to_string(this->collision) + "\n";
	this->text.setString(this->string);
	this->text.setPosition(this->mousePosView.x + 20, this->mousePosView.y);
	this->map->update(time);
				


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (!this->textureSelector->getActive())
		{
			this->map->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect, this->collision, this->type);
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
	if (!window)
		window = this->window;


	window->setView(this->editorView);
	this->map->render(*window);

	if (!this->textureSelector->getActive())
	{
		window->setView(this->editorView);

		window->draw(this->mouseSelector);
	}


	//render GUI
	window->setView(this->window->getDefaultView());
	this->textureSelector->render(*window);

	window->setView(this->editorView);
	window->draw(text);

	window->setView(this->window->getDefaultView());
	
}
