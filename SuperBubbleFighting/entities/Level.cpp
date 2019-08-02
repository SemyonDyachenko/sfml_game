#include "Level.h"



void Level::initTextures()
{
}

void Level::initVariables()
{
	this->end = false;
}

void Level::initView()
{
	this->levelView.setSize(sf::Vector2f(
		this->window->getSize().x,
		this->window->getSize().y
	));

	this->levelView.setCenter(sf::Vector2f(
		this->window->getSize().x / 2.f,
		this->window->getSize().y / 2.f
	));

}

void Level::init()
{
	this->initTextures();
	this->initVariables();
	this->initView();
}

Level::Level(sf::RenderWindow & window, std::string map_filename, std::string back_filename)
{
	this->window = &window;
	this->init();
	this->tilemap = new MapEditor(&window,"..res/images/tilset1.png");
	this->tilemap->loadFromFile(map_filename);
}


Level::~Level()
{
	delete this->player;

	for (size_t i = 0; i < enemyes.size(); i++)
	{
		delete enemyes[i];
	}
	for (size_t i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}

}

void Level::start()
{
	this->start = true;
}

void Level::end()
{
	this->end = true;
}

const bool & Level::checkEnd() const
{
	// TODO: insert return statement here
	return this->end;
}

// UPDATE

void Level::updatePlayer(float time)
{
	this->player->update(time);
}

void Level::updateEnemy(float time)
{
	for (size_t i = 0; i < enemyes.size(); i++)
	{
		this->enemyes[i]->update(time);
	}
}

void Level::updateObjects(float time)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		this->objects[i].update(time);
	}
}

void Level::update(float time)
{
	this->updatePlayer(time);
	this->updateEnemy(time);
	this->updateObjects(time);
}

// RENDER

void Level::renderPlayer(sf::RenderWindow * window)
{
	this->player->render(window);
}

void Level::renderEnemy(sf::RenderWindow * window)
{
	for (size_t i = 0; i < enemyes.size(); i++)
	{
		this->enemyes[i]->render(window);
	}
}

void Level::renderObjects(sf::RenderWindow * window)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		this->objects[i]->render(window);
	}
}

void Level::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

	this->renderObjects(window);
	this->renderEnemy(window);
	this->renderPlayer(window);
}
