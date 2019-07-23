#ifndef TILE_H
#define TILE_H

#include "../GUI/Button.h"

enum TileTypes
{
	DEFAULT = 0,
	DAMAGING
};


class Tile
{
private:
	sf::RectangleShape shape;
	float posX, posY;
	bool collision;
	short type;
	
public:
	Tile();
	Tile(unsigned x, unsigned y,float gridSizeF,sf::Texture& texture,const sf::IntRect& rect, bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();


	float getPositionX();
	float getPositionY();

	const std::string getAssString() const;
	

	void update();
	void render(sf::RenderWindow& window);


};


#endif // ! TILE_H