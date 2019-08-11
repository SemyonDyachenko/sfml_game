#include "../stdafx.h"
#include "Level.h"



void Level::initShaders()
{
	//if (!this->core_shader.loadFromFile("../resource/shaders/vertexShader.vert", "../resource/shaders/fragmentShader.frag"))
	//	std::cout << "ERROR: don't load vertexShader or fragmentShader in Level.cpp \n";
}

void Level::initTextures()
{
	if (!this->playerTexture.loadFromFile("../res/images/heroes/ork.png"))
		std::cout << "ERROR: don't load playerTexture in level \n";
}

void Level::initVariables()
{
	this->end = true;
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

void Level::initPlayer()
{

}

void Level::initEnemyes()
{
}

void Level::initObject()
{
}

void Level::init()
{
	this->initShaders();
	this->initTextures();
	this->initVariables();
	this->initView();
	this->initPlayer();
	this->initEnemyes();
	this->initObject();
}

Level::Level(sf::RenderWindow & window, std::string map_filename, std::string back_filename)
{
	this->window = &window;
	this->init();
	this->tilemap = new MapEditor(&window,"../res/images/tileset.png");
	this->tilemap->loadFromFile(map_filename);
	this->tilemap->setGameMap(true);
	this->player = new Player(this->tilemap->getObject("player")->getGlobalBounds().left, this->tilemap->getObject("player")->getGlobalBounds().top, playerTexture, "../res/animation/anim.xml", *this->tilemap);
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

//void Level::start()
//{
//	this->start = true;
//}

//void Level::end()
//{
//	this->end = true;
//}

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
		//for (size_t i = 0; i < enemyes.size(); i++)
		//{
		//this->enemyes[i]->update(time);
	//	}
}

void Level::updateObjects(float time)
{
	//for (size_t i = 0; i < objects.size(); i++)
//	{
//		this->objects[i]->update(time);
//	}
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
	//for (size_t i = 0; i < enemyes.size(); i++)
//	{
	//	this->enemyes[i]->render(window);
//	}
}

void Level::renderObjects(sf::RenderWindow * window)
{
	//for (size_t i = 0; i < objects.size(); i++)
	//{
	//	this->objects[i]->render(window);
	//}
}

void Level::render(sf::RenderWindow * window)
{
	if (!window)
		window = this->window;

	this->renderObjects(window);
	this->renderEnemy(window);
	this->renderPlayer(window);
	this->tilemap->render(*window);
}
