#include "../stdafx.h"
#include "Level.h"



void Level::initShaders()
{
	//if (!this->core_shader.loadFromFile("../resource/shaders/vertexShader.vert", "../resource/shaders/fragmentShader.frag"))
	//	std::cout << "ERROR: don't load vertexShader or fragmentShader in Level.cpp \n";
}

void Level::initTextures()
{
	if (!this->playerTexture.loadFromFile("../res/images/braid.png"))
		std::cout << "ERROR: don't load playerTexture in level \n";

	this->skyT.loadFromFile("../res/images/skyblue.png");
	this->sky.setTexture(&skyT);
	this->sky.setSize(sf::Vector2f(this->window->getSize()));

	this->forestt1.loadFromFile("../res/images/forest1.png");
	this->forest1.setTexture(&forestt1);
	this->forest1.setSize(sf::Vector2f(this->window->getSize()));

	this->forestt2.loadFromFile("../res/images/forest2.png");
	this->forest2.setTexture(&forestt2);
	this->forest2.setSize(sf::Vector2f(this->window->getSize()));

	this->forestt3.loadFromFile("../res/images/forest3.png");
	this->forest3.setTexture(&forestt3);
	this->forest3.setSize(sf::Vector2f(this->window->getSize()));
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
	tree.loadFromFile("../res/images/tree.png");
	this->treeSprite.setTexture(tree);
	this->tilemap = new MapEditor(&window, "../res/images/tileset.png");
	this->tilemap->loadFromFile(map_filename);
	this->tilemap->setGameMap(true);
	this->player = new Player(this->tilemap->getObject("player")->getGlobalBounds().left, this->tilemap->getObject("player")->getGlobalBounds().top, playerTexture, "../res/animation/anim.xml", *this->tilemap);
	this->levelView.setCenter(player->getPosition().x, player->getPosition().y);
	this->sky.setPosition(this->tilemap->getObject("back")->rect.left, this->tilemap->getObject("back")->rect.top);
	this->forest1.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->forest2.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->forest3.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);

	music.openFromFile("../res/music/witcher.ogg");
	music.setLoop(true);
	music.setVolume(8);
	music.play();
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
	this->window->setView(this->levelView);
	this->levelView.setCenter(player->getPosition().x, player->getPosition().y);
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

	window->draw(sky);
	window->draw(forest1);
	window->draw(forest2);
	window->draw(forest3);
	this->tilemap->render(*window);
	this->renderObjects(window);
	this->renderEnemy(window);
	this->renderPlayer(window);
	for (auto &x : this->tilemap->getAllObject())
	{
		for (auto &y : x)
		{
			for (auto *z : y)
			{
				if (z != NULL)
				{
					if (z->getName() == "tree")
					{
						this->treeSprite.setPosition(z->getGlobalBounds().left, z->getGlobalBounds().top-tree.getSize().y+z->getGlobalBounds().height);
						window->draw(this->treeSprite);
					}
				}
			}
		}
	}
}
