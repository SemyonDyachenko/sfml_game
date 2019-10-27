#include "../stdafx.h"
#include "Level.h"



void Level::initShaders()
{
	//if (!this->core_shader.loadFromFile("../resource/shaders/vertexShader.vert", "../resource/shaders/fragmentShader.frag"))
	//	std::cout << "ERROR: don't load vertexShader or fragmentShader in Level.cpp \n";
}

void Level::initTextures()
{
	if (!this->playerTexture.loadFromFile("../res/images/shoot.png"))
		std::cout << "ERROR: don't load playerTexture in level \n";

	this->skyT5.loadFromFile("../res/images/background/layer0.png");
	this->sky5.setTexture(&skyT3);
	this->sky5.setSize(sf::Vector2f(this->skyT5.getSize().x, this->window->getSize().y));

	
	this->sunT.loadFromFile("../res/images/background/layer.png");
	this->sun.setTexture(&this->sunT);
	this->sun.setSize(sf::Vector2f(1920, this->window->getSize().y));


	this->skyT.loadFromFile("../res/images/background/layer1.png");
	this->sky.setTexture(&skyT);
	this->sky.setSize(sf::Vector2f(1920,this->window->getSize().y));

	this->skyT1.loadFromFile("../res/images/background/layer2.png");
	this->sky1.setTexture(&skyT1);
	this->sky1.setSize(sf::Vector2f(this->skyT1.getSize().x, this->window->getSize().y));

	this->skyT2.loadFromFile("../res/images/background/layer3.png");
	this->sky2.setTexture(&skyT2);
	this->sky2.setSize(sf::Vector2f(this->skyT2.getSize().x,this->window->getSize().y));

	this->skyT3.loadFromFile("../res/images/background/layer4.png");
	this->sky3.setTexture(&skyT3);
	this->sky3.setSize(sf::Vector2f(this->skyT3.getSize().x,this->window->getSize().y));

	this->skyT4.loadFromFile("../res/images/background/layer5.png");
	this->sky4.setTexture(&skyT3);
	this->sky4.setSize(sf::Vector2f(this->skyT4.getSize().x, this->window->getSize().y));
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
	this->player = new Player(&window,this->tilemap->getObject("player")->getGlobalBounds().left, this->tilemap->getObject("player")->getGlobalBounds().top, playerTexture, "../res/animation/anim.xml", *this->tilemap);
	this->levelView.setCenter(player->getPosition().x, player->getPosition().y);
	this->levelView.zoom(0.5);
	this->skyPos1.x = this->tilemap->getObject("back")->rect.left;
	this->skyPos1.y = this->tilemap->getObject("back")->rect.top;

	this->skyPos2.x = this->sky.getPosition().x + this->sky.getSize().x;
	this->skyPos2.y = this->tilemap->getObject("back")->rect.top;

	this->sky.setPosition(this->skyPos1.x,this->skyPos1.y);
	this->sky1.setPosition(this->skyPos2.x, this->skyPos2.y);

	
	this->sky5.setPosition(this->tilemap->getObject("back")->rect.left, this->tilemap->getObject("back")->rect.top);
	this->sun.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->sky.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->sky1.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->sky2.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);
	this->sky3.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top );
	this->sky4.setPosition(this->tilemap->getObject("back")->rect.left,this->tilemap->getObject("back")->rect.top);


	music.openFromFile("../res/music/music.ogg");
	music.setLoop(true);
	music.setVolume(14);
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

void Level::checkBackground(float time)
{
	
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
	checkBackground(time);

	this->bar.update(60);
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
	window->draw(sky5);
	window->draw(sky);
	window->draw(sun);
	window->draw(sky1);
	window->draw(sky2);
	window->draw(sky3);
	window->draw(sky4);
	
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

	this->bar.render(window);
}
