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
	sf::IntRect rect;

public:
	Tile();
	Tile(unsigned x, unsigned y,float gridSizeF,sf::Texture& texture,const sf::IntRect& rect, bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();


	const bool& getCollision() const;

	const sf::FloatRect& getRect() const;

	const sf::Vector2f& getPosition() const;

	const bool intersects(const sf::FloatRect rect) const;

	const std::string getAssString() const;
	


	void update();
	void render(sf::RenderWindow& window);


};


#endif // ! TILE_H