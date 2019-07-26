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
			}
			this->map[x][y].clear();
		}
		this->map[x].clear();
	}
	this->map.clear();

	
 } 

void MapEditor::initTextures()
{

}

MapEditor::MapEditor(sf::RenderWindow * window,std::string textureFile)
{
	this->window = window;
	this->gridSizeF = 16.f;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSizeWorldGrid.x = 100;
	this->maxSizeWorldGrid.y = 100;
	this->maxSizeF.x = 100 * this->gridSizeF;
	this->maxSizeF.y = 100 * this->gridSizeF;
	this->layers = 1;
	this->textureFile = textureFile;
	
	this->map.resize(this->maxSizeWorldGrid.x,std::vector<std::vector<Tile*>>());

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y,std::vector<Tile*>());

			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers,NULL);

				
			}
		}
	}

	if (!this->textureSheet.loadFromFile(textureFile)) std::cout << "error: don't load texture grass from file , MapEditor.cpp,line 7" << "\n";
	
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

	std::ofstream out_file;
	out_file.open(filename);

	if (out_file.is_open())
	{
		out_file << this->maxSizeWorldGrid.x << " " << this->maxSizeWorldGrid.y << "\n"
			<< this->gridSizeU << "\n"
			<< this->layers << "\n"
			<< this->textureFile << "\n";

		for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				for (size_t z = 0; z < this->layers; z++)
				{
					if (this->map[x][y][z] != NULL)
					out_file << x << " " << y << " " << z << " " << this->map[x][y][z]->getAssString() << " ";
				}
			}
		}

	}
	else
	{
		std::cout << "Error open text file tilemap\n";
	}

	out_file.close();
}

void MapEditor::loadFromFile(const std::string filename)
{
	std::ifstream in_file;
	in_file.open(filename);

	if (in_file.is_open())
	{
		sf::Vector2u size;
		unsigned gridSize = 0;
		unsigned layers = 0;                 
		std::string texture_file = "";
		unsigned x = 0;
		unsigned y = 0;
		unsigned z = 0;
		unsigned trX = 0;
		unsigned trY = 0;
		bool collision = false;
		short type = 0;

		in_file >> size.x >> size.y >> gridSize >> layers >> texture_file;

		this->gridSizeF = static_cast<float>(gridSize);
		this->gridSizeU = gridSize;
		this->maxSizeWorldGrid.x = size.x;
		this->maxSizeWorldGrid.y = size.y;
		this->layers = layers;
		this->textureFile = texture_file;

		this->clear();

		this->map.resize(this->maxSizeWorldGrid.x,std::vector<std::vector<Tile*>>());

		for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				this->map[x].resize(this->maxSizeWorldGrid.y,std::vector<Tile*>());

				for (size_t z = 0; z < this->layers; z++)
				{
					this->map[x][y].resize(this->layers,NULL);
				}
			}
		}

		if (!this->textureSheet.loadFromFile(texture_file)) 
			std::cout << "error: don't load texture grass from file , MapEditor.cpp,line 7" << "\n";

		while (in_file >> x >> y >> z >> trX >> trY >> collision >> type)
		{
			this->map[x][y][z] = new Tile(x, y,this->gridSizeF,this->textureSheet, sf::IntRect(trX, trY,this->gridSizeU,this->gridSizeU),collision,type);
		}
	}
	else
	{
		std::cout << "Error load from file , tilemap\n";
	}

	in_file.close();
}



void MapEditor::addTile(const unsigned  x,const unsigned y,const unsigned z,sf::IntRect& textureRect, const bool collision, const short type)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y > 0 && z < this->layers && z>= 0)
	{
		if (this->map[x][y][z] == NULL || (this->map[x][y][z]->getRect() != textureRect))
		{
			this->map[x][y][z] = new Tile(x, y, this->gridSizeF,this->textureSheet,textureRect,collision,type);
		}
	}
}

void MapEditor::removeTile(const unsigned  x, const unsigned y, const unsigned z)
{
	if (x < this->maxSizeWorldGrid.x && x >= 0 && y < this->maxSizeWorldGrid.y && y > 0 && z < this->layers && z >= 0)
	{
		if (this->map[x][y][z] != NULL)
		{
			delete this->map[x][y][z];
			this->map[x][y][z] = NULL;
		}
	}
}

sf::Texture & MapEditor::getTextureSheet()
{
	return this->textureSheet;
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
}




