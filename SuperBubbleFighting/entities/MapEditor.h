#ifndef TILEMAP_H
#define TILEMAP_H



#include "Tile.h"
//#include "Player.h"
#include "objects/MapObject.h"
#include "../TinyXML/tinyxml.h"

class Player;
class MapObject;
class Tile;

class MapEditor
{
private:
	void clear();

	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2f maxSizeWorldGrid;
	sf::Vector2f maxSizeF;
	sf::RenderWindow * window;
	unsigned layers;
	std::vector < std::vector < std::vector < Tile*> > > map;
	std::vector<  std::vector< std::vector<MapObject*> > > objects;

	sf::RectangleShape TileSet;
	sf::RectangleShape collisionBox;

	bool inGame;

	sf::Texture textureSheet;
	std::string textureFile;

	void initTextures();
public:
	MapEditor(sf::RenderWindow * window,std::string textureFile);
	virtual ~MapEditor();

	void addTile(const unsigned  x, const unsigned y, const unsigned z, sf::IntRect& textureRect,const bool collision,const short type);
	void removeTile(const unsigned  x, const unsigned y, const unsigned z);

	void addObjct(const unsigned x, const unsigned y,const unsigned z,std::string name);
	void removeObject(const unsigned x, const unsigned y, const unsigned z);
	
	sf::Texture &getTextureSheet();

	void setGameMap(bool inGame);

	void saveToFile(const std::string filename);
	void loadFromFile(const std::string filename);

	//void checkCollision(Player * player);

	const sf::Vector2f & getMapSize() const;
	const unsigned & getLayerCount() const;


	const std::vector<std::vector<std::vector<Tile*> > >& getTiles() const;

	const std::vector<std::vector<std::vector<MapObject*>>> & getAllObject() const;


	void update(float time);
	void render(sf::RenderWindow& window);

	
};



#endif // ! TILEMAP_H