#ifndef MAPOBJECT_H
#define MAPOBJECT_H


#include "../Bullet.h"

class MapObject
{
private:
	sf::RectangleShape shape;
	float posX, posY;
	float width,height;

public:
	MapObject();

	~MapObject();

	virtual void setPosition(const float x, const float y);
	virtual void setSize(const float width, const float height);

	void update();
	void render(sf::RenderWindow * window);
};


#endif // ! MAPOBJECT_H