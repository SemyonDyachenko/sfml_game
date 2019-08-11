#include "../stdafx.h"
#include "MapEditor.h"

void MapEditor::clear()
{
	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (size_t z = 0; z < this->layers; z++)
			{
				delete this->map[x][y][z];
				this->map[x][y][z] = NULL;
				delete this->objects[x][y][z];
				this->objects[x][y][z] = NULL;
			}
			this->map[x][y].clear();
			this->objects[x][y].clear();
		}
		this->map[x].clear();
		this->objects[x].clear();
	}
	this->map.clear();
	this->objects.clear();
 } 

void MapEditor::initTextures()
{

}

MapEditor::MapEditor(sf::RenderWindow * window,std::string textureFile)
{
	this->window = window;
	this->gridSizeF = 48.f;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSizeWorldGrid.x = 100;
	this->maxSizeWorldGrid.y = 100;
	this->maxSizeF.x = 100 * this->gridSizeF;
	this->maxSizeF.y = 100 * this->gridSizeF;
	this->layers = 1;
	this->textureFile = textureFile;
	this->inGame = false;
	
	
	this->map.resize(this->maxSizeWorldGrid.x,std::vector<std::vector<Tile*>>());
	this->objects.resize(this->maxSizeWorldGrid.x, std::vector<std::vector<MapObject*>>());

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y,std::vector<Tile*>());
			this->objects[x].resize(this->maxSizeWorldGrid.y, std::vector<MapObject*>());

			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers,NULL);	
				this->objects[x][y].resize(this->layers, NULL);
			}
		}
	}

	


	if (!this->textureSheet.loadFromFile(textureFile)) std::cout << "error: don't load texture tiles from file , MapEditor.cpp,line 7" << "\n";
	
	//collision

	this->collisionBox.setSize(sf::Vector2f(
		this->gridSizeF,
		this->gridSizeF
	));

	this->collisionBox.setFillColor(sf::Color(255, 0, 0, 50));
	this->collisionBox.setOutlineColor(sf::Color::Red);
	this->collisionBox.setOutlineThickness(1.f);
}


MapEditor::~MapEditor()
{

	this->clear();
}


void MapEditor::saveToFile(const std::string filename)
{
	/* Save map to text file 
	
	Tiles:
	this->layer
	texture file
	gridPos x,y TextureRect width height x y collision type

	*/



	TiXmlDocument levelFile;
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "utf-8", "");
	levelFile.LinkEndChild(decl);

	TiXmlElement * map;
	map = new TiXmlElement("map");
	levelFile.LinkEndChild(map);

	map->SetAttribute("width", this->maxSizeWorldGrid.x);
	map->SetAttribute("height", this->maxSizeWorldGrid.y);
	map->SetAttribute("gridSize", this->gridSizeU);
	map->SetAttribute("layers", this->layers);
	map->SetAttribute("tileset",this->textureFile.c_str());

	TiXmlElement * tiles;
	tiles = new TiXmlElement("tiles");
	map->LinkEndChild(tiles);

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
			for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				for (size_t z = 0; z < this->layers; z++)
				{
					if (this->map[x][y][z] != NULL)
					{
						TiXmlElement * tile = new TiXmlElement("tile");
						tile->SetAttribute("x", x);
						tile->SetAttribute("y", y);
						tile->SetAttribute("layer", z);
						tile->SetAttribute("tX", this->map[x][y][z]->getRect().left);
						tile->SetAttribute("tY", this->map[x][y][z]->getRect().top);
						tiles->LinkEndChild(tile);
					}
						
				}
			}
		}

	TiXmlElement * objects;
	objects = new TiXmlElement("objects");
	map->LinkEndChild(objects);

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (size_t z = 0; z < this->layers; z++)
			{
				if (this->objects[x][y][z] != NULL)
				{
					TiXmlElement * object = new TiXmlElement("object");
					object->SetAttribute("x", x);
					object->SetAttribute("y", y);
					object->SetAttribute("layer", z);
					object->SetAttribute("name", this->objects[x][y][z]->getName().c_str());
					objects->LinkEndChild(object);
				}
			}
		}
	}


	levelFile.SaveFile(filename.c_str());

}

void MapEditor::loadFromFile(const std::string filename)
{
	TiXmlDocument levelFile(filename.c_str());
	if (!levelFile.LoadFile())//если не удалось загрузить карту
	{
		std::cout << "Loading level \"" << filename << "\" failed." << std::endl;//выдаем ошибку
	}
	sf::Vector2u size;
	unsigned gridSize;
	std::string texture_file;
	unsigned layers;
	unsigned tX, tY;
	std::string name;

	/*unsigned gridSize = 0;
unsigned layers = 0;
std::string texture_file = "";
unsigned x = 0;
unsigned y = 0;
unsigned z = 0;
unsigned trX = 0;
unsigned trY = 0;
bool collision = false;
short type = 0;
std::string name = "";*/

	TiXmlElement *map;
	map = levelFile.FirstChildElement("map");

	size.x = atoi(map->Attribute("width"));
	size.y = atoi(map->Attribute("height"));
	gridSize = atoi(map->Attribute("gridSize"));
	layers = atoi(map->Attribute("layers"));
	texture_file = atoi(map->Attribute("tileset"));

	TiXmlElement *tiles;
	tiles = map->FirstChildElement("tiles");

	TiXmlElement *objects;
	objects = map->FirstChildElement("objects");


	this->gridSizeF = static_cast<float>(gridSize);
	this->gridSizeU = gridSize;
	this->maxSizeWorldGrid.x = size.x;
	this->maxSizeWorldGrid.y = size.y;
	this->layers = layers;
	this->textureFile = texture_file;

	this->clear();

	this->map.resize(this->maxSizeWorldGrid.x,std::vector<std::vector<Tile*>>());
	this->objects.resize(this->maxSizeWorldGrid.x, std::vector<std::vector<MapObject*>>());

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y,std::vector<Tile*>());
			this->objects[x].resize(this->maxSizeWorldGrid.y, std::vector<MapObject*>());

			for (size_t z = 0; z < this->layers; z++)
			{
					this->map[x][y].resize(this->layers,NULL);
					this->objects[x][y].resize(this->layers, NULL);
			}
		}
	}

		if (!this->textureSheet.loadFromFile(textureFile))
			std::cout << "error: don't load texture  from file , MapEditor.cpp,line 7" << "\n";

		TiXmlElement *tileElement;
		tileElement = tiles->FirstChildElement("tile");

		TiXmlElement *objectElement;
		objectElement = objects->FirstChildElement("object");

		if (tileElement == NULL)
		{

		}
		else
		{
			while (tileElement)
			{
				unsigned x = atoi(tileElement->Attribute("x"));
				unsigned y = atoi(tileElement->Attribute("y"));
				unsigned z = atoi(tileElement->Attribute("layer"));
				tX = atoi(tileElement->Attribute("tX"));
				tY = atoi(tileElement->Attribute("tY"));
				this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->textureSheet, sf::IntRect(tX, tY, this->gridSizeU, this->gridSizeU), false, 0);
				tileElement = tileElement->NextSiblingElement("tile");
			}

		}

		if (objectElement == NULL)
		{

		}
		else
		{
			while (objectElement)
			{
				unsigned x = atoi(objectElement->Attribute("x"));
				unsigned y = atoi(objectElement->Attribute("y"));
				unsigned z = atoi(objectElement->Attribute("layer"));
				std::string name = objectElement->Attribute("name");
				this->objects[x][y][z] = new MapObject(x, y, this->gridSizeF, name);
				objectElement = objectElement->NextSiblingElement("object");
			}
		}
}

//void MapEditor::checkCollision(Player * player)
//{
//	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
//	{
//		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
//		{
//
//			for (size_t z = 0; z < this->layers; z++)
//			{
//				if (map[x][y][z] != NULL)
//				{
//					if (this->map[x][y][z]->intersects(player->getGlobalBounds()))
//					{
//						if (map[x][y][z]->getCollision())
//						{
//							
//						}
//					}
//				}
//			}
//		}
//	}
//}

const sf::Vector2f & MapEditor::getMapSize() const
{
	return sf::Vector2f(this->maxSizeWorldGrid);
}

const unsigned & MapEditor::getLayerCount() const
{
	return this->layers;
}

const std::vector<std::vector<std::vector<Tile*>>>& MapEditor::getTiles() const
{
	return this->map;
}

const std::vector<std::vector<std::vector<MapObject*>>>& MapEditor::getAllObject() const
{
	return this->objects;
}

const MapObject* MapEditor::getObject(std::string name) const
{
	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (size_t z = 0; z < this->layers; z++)
			{
				if (objects[x][y][z] != NULL)
				{
					if (objects[x][y][z]->getName() == name)
					{
						return objects[x][y][z];
					}
				}
			}
		}
	}
}



void MapEditor::addTile(const unsigned  x,const unsigned y,const unsigned z,sf::IntRect& textureRect, const bool collision, const short type)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y >= 0 && z < this->layers && z>= 0)
	{
		if (this->map[x][y][z] == NULL || (this->map[x][y][z]->getRect() != sf::FloatRect(textureRect)))
		{
			this->map[x][y][z] = new Tile(x, y, this->gridSizeF,this->textureSheet,textureRect,collision,type);
		}

	}
}

void MapEditor::removeTile(const unsigned  x, const unsigned y, const unsigned z)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y >= 0 && z < this->layers && z >= 0)
	{
		if (this->map[x][y][z] != NULL)
		{
			delete this->map[x][y][z];
			this->map[x][y][z] = NULL;
		}
	}
}

void MapEditor::addObjct(const unsigned x, const unsigned y,const unsigned z, std::string name)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y >= 0 && y >= 0 && z < this->layers && z >= 0)
	{
		if (this->objects[x][y][z] == NULL)
		{
			this->objects[x][y][z] = new MapObject(x,y,this->gridSizeF,name);
		}
	}
}

void MapEditor::removeObject(const unsigned x, const unsigned y,const unsigned z)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y >= 0 && y >= 0 && z < this->layers && z >= 0)
	{
		if (this->objects[x][y][z] != NULL)
		{
			delete this->objects[x][y][z];
			this->objects[x][y][z] = NULL;

		}
	}
}

sf::Texture & MapEditor::getTextureSheet()
{
	return this->textureSheet;
}

void MapEditor::setGameMap(bool inGame)
{
	this->inGame = inGame;
}



void MapEditor::update(float time)
{
}

void MapEditor::render(sf::RenderWindow & window)
{
	for(auto &x :this->map) 
	{
		for (auto &y : x)
		{
			for (auto *z : y)
			{
				if (z != NULL)
				{
					z->render(window);
					if (z->getCollision())
					{
						this->collisionBox.setPosition(z->getPosition());
						window.draw(this->collisionBox);
					}
				}
			}
		}
	}

	for (auto &x : this->objects)
	{
		for (auto &y : x)
		{
			for (auto *z : y)
			{
				if (z != NULL)
				{
					if(!this->inGame)
						z->render(window);
				}
			}
		}
	}
}





