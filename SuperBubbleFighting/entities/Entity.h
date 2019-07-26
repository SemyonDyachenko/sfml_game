#ifndef ENTITY_H
#define ENTITY_H


#include "MapEditor.h"

class Entity
{
protected:
	float posX, posY, dx, dy,speed;
	bool life;
	unsigned hp;
	bool onGround;
	sf::Sprite sprite;
public:
	Entity(float x, float y, sf::Texture& texture,MapEditor& level);
	virtual ~Entity();

	
	virtual const sf::Vector2f& getPosition() const = 0;

	virtual void setPosition(const float x,const float y);

	virtual void update(float time) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
};



#endif // ! ENTITY_H
